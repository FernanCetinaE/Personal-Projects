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

void leer(int count);
void imprimir();

void leer(int count){
    struct Node *newNode, *temp;

    head = (struct Node*)malloc(sizeof(struct Node)); 

    if(head == NULL)
    {
        printf("Error para alojar memoria");
    }
    else
    {
        int diaHolder;
        float entradaHolder, salidaHolder;
        //llenamos el primer nodo
        printf("Nombre: ");
        gets(head -> asignatura);

        printf("\nDia de la semana: ");
        scanf("%d", &diaHolder);
        head -> diaSemana = diaHolder;

        printf("\nEntrada: ");
        scanf("%f", &entradaHolder);
        head -> horaEntrada = entradaHolder;

        printf("\nSalida: ");
        scanf("%f", &salidaHolder);
        head -> horaSalida = salidaHolder;

        head->next = NULL; // Link the address field to NULL
        temp = head;

        //Añadimos nodos siguientes
        for (int i = 2; i <= count; i++){
        newNode = (struct Node*)malloc(sizeof(struct Node));
        
        /* If memory is not allocated for newNode */
        if(newNode == NULL)
        {
            printf("Error de memoria");
            break;
        }
        else
        {

        strcpy(newNode -> asignatura, "12");
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
            temp = temp->next; 
        }
    }
    }
} 

void imprimir(){
    struct Node *pointer;
    if(head==NULL){
        printf("Lista vacia");
    }else{
        pointer = head;

        while(pointer != NULL){
            if(strlen(pointer->asignatura)>2){
            printf("\nMateria: %s", pointer->asignatura);
            }

            printf("\nDia de la semana: %d", pointer -> diaSemana);
            printf("\nEntrada: %.2f", pointer -> horaEntrada);
            printf("\nSalida: %.2f\n", pointer -> horaSalida);
            pointer = pointer -> next;
    }
    }
}

int main(){
    
    leer(2);
    imprimir();
    return 0;
}
//https://codeforwin.org/2015/09/c-program-to-insert-node-at-end-of-singly-linked-list.html