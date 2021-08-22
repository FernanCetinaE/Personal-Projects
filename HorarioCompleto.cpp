#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node{
    char asignatura[50];
    int diaSemana;
    float horaEntrada;
    float horaSalida;
    struct Node *next;
}*head;

void leer(int count, int *tracker);
void imprimir();

void leer(int count, int *tracker){
    struct Node *newNode, *temp; //punteros de apoyo

    head = (struct Node*)malloc(sizeof(struct Node)); //crea el primer nodo del struct

    if(head == NULL) //mensaje estandar de error al crear nodo
    {
        printf("Error para alojar memoria");
    }
    else
    {
        int diaHolder;
        float entradaHolder, salidaHolder; //variables de asignacion

        /*llenamos el primer nodo*/
        printf("Nombre: ");
        gets(head -> asignatura); //para llenar "char" es necesario "gets"

        printf("\nDia de la semana: ");
        scanf("%d", &diaHolder);
        head -> diaSemana = diaHolder;

        printf("\nEntrada: ");
        scanf("%f", &entradaHolder);
        head -> horaEntrada = entradaHolder;

        printf("\nSalida: ");
        scanf("%f", &salidaHolder);
        head -> horaSalida = salidaHolder;

        head->next = NULL; // Link the address field to NULL, trunca primer nodo
        temp = head;//puntero que apunta al primer nodo creado

        int checkAsignatura=1;
        int sumaDeNodos=*(tracker + checkAsignatura);
        /*iremos llevando registro de cada materia y sus dias de clase*/

        //Añadimos nodos siguientes
        for (int i = 2; i <= count; i++){
        newNode = (struct Node*)malloc(sizeof(struct Node));//creamos el espacio para el nuevo nodo
        
        /* If memory is not allocated for newNode */
        if(newNode == NULL)
        {
            printf("Error de memoria");
            break;
        }
        else
        {
        /*Registro para solicitar nombre de la asignatura*/    
        if(sumaDeNodos + 1 == i ){
        //cada *tracker[i]+1 es la posicion para leer la siguiente materia
            fflush(stdin);
            printf("\n\nNombre: ");
            gets(newNode -> asignatura);

            checkAsignatura++;
            sumaDeNodos = sumaDeNodos + *(tracker + checkAsignatura);          
        }else{
            strcpy(newNode -> asignatura, "12"); //copiamos un "vacio" como referencia a "char"
        }

        
        printf("\nDia de la semana: ");
        scanf("%d", &diaHolder);
        newNode -> diaSemana = diaHolder;

        printf("\nEntrada: ");
        scanf("%f", &entradaHolder);
        newNode -> horaEntrada = entradaHolder;

        printf("\nSalida: ");
        scanf("%f", &salidaHolder);
        newNode -> horaSalida = salidaHolder;

            newNode->next = NULL; // Link the address field of newNode with NULL
            temp->next = newNode; // Link previous node i.e. temp to the newNode
            /*temp tenía guardado el nodo anterior y usará "next" apuntando a
            newNode para enlazarlos
            */
            temp = temp->next; //se posiciona en el nuevo nodo creado
        }
    }
    }
} 

void imprimir(){
    struct Node *pointer; //apuntador auxiliar
    if(head==NULL){
        printf("Lista vacia");
    }else{
        pointer = head; //se apunta el primer nodo del struct

        while(pointer != NULL){
            if(strlen(pointer->asignatura)>2){
            printf("\nMateria: %s", pointer->asignatura);
            }//valor de refencia, para no repetir asignatura en cada nodo; evita redundancia

            printf("\nDia de la semana: %d", pointer -> diaSemana);
            printf("\nEntrada: %.2f", pointer -> horaEntrada);
            printf("\nSalida: %.2f\n", pointer -> horaSalida);
            pointer = pointer -> next;
    }
    }
}

int main(){
    int cantidadMaterias, frecuenciaHolder, cantidadDias=0;
    printf("Cuantas materias registraras?");
    scanf("%d", &cantidadMaterias);
    
    int *ptr = (int *)malloc(sizeof(int)*(cantidadMaterias+1));
    /*ptr almacenará cantidad de materias y la frecuencia de cada una*/
    *(ptr + 0) = cantidadMaterias;


    for (int i = 1; i < cantidadMaterias+1; i++)
    {
        printf("Cantidad de veces que tomas la materia %d: ", i);
        scanf("%d", &frecuenciaHolder);
        *(ptr+i)=frecuenciaHolder;

        cantidadDias=cantidadDias+*(ptr+i);
        printf("\n");
    }
    fflush(stdin);

    leer(cantidadDias, ptr); 
    imprimir();
    return 0;
}
//https://codeforwin.org/2015/09/c-program-to-insert-node-at-end-of-singly-linked-list.html