/* Program to control schedule */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fecha
{
    int hora;
    int minuto;
};

struct Asignatura
{
    int diaSemana;
    char *nombreAsignatura;
    Fecha *horarioEntrada;
    Fecha *horarioSalida;
    struct Asignatura *next;
};

typedef struct Asignatura Asignatura;
typedef struct Fecha Fecha;

void addToLast(Asignatura **first, Asignatura *second);
void insertarAlInicio(Asignatura** head_ref, Asignatura* new_node);
void insertarDepues(Asignatura** head_ref, Asignatura* new_node);

void insertarAlRestoPorDiaAscendente(Asignatura** head_ref, Asignatura* new_node);
void insertarAscendentementePorDia(Asignatura** head_ref, Asignatura* new_node);

void insertarAlRestoPorDiaDescendente(Asignatura** head_ref, Asignatura* new_node);
void insertarDescendentementePorDia(Asignatura** head_ref, Asignatura* new_node);

void insertarAlRestoPorHoraDescendente(Asignatura** head_ref, Asignatura* new_node);
void insertarDescendentementePorHora(Asignatura** head_ref, Asignatura* new_node);

Asignatura* newAsignatura();
void printList(Asignatura* head);
void read(Asignatura *head);
Asignatura* inputController(Asignatura *head);

/* Function that addes new node at the end*/
void addToLast(Asignatura **first, Asignatura *second)
{
    Asignatura *temp = *first;
    if (*first == NULL)
    {
       *first = second;
    } else{
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = second;
    }
}

/* Function to call in case newNode is smaller than head*/
void insertarAlInicio(Asignatura** head_ref, Asignatura* new_node)
{
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertarDepues(Asignatura** head_ref, Asignatura* new_node){
    Asignatura* current = *head_ref;
    new_node->next = current->next;
    current->next = new_node;
}

/*ORDEN DESCENDENTE*/

/* Function to insert in descending order by day*/
void insertarDescendentementePorDia(Asignatura** head_ref, Asignatura* new_node)
{
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->diaSemana <= new_node->diaSemana) {
        insertarAlInicio(head_ref,new_node);
    }
    else {
        insertarAlRestoPorDiaDescendente(head_ref, new_node);
    }
}

/* Function to call in case newNode is smaller than head*/
void insertarAlRestoPorDiaDescendente(Asignatura** head_ref, Asignatura* new_node)
{
    Asignatura* current;
    current = *head_ref;

    while (current->next != NULL && current->next->diaSemana > new_node->diaSemana) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

/* Function to insert in ascending order*/
void insertarDescendentementePorHora(Asignatura** head_ref, Asignatura* new_node)
{
    Asignatura* current;
    current = *head_ref;
    int check=0;

        while (current != NULL)
        {
            if(current -> diaSemana == new_node -> diaSemana){
            check=1;
            }
            current = current->next;
        }
        check ? insertarAlRestoPorHoraDescendente(head_ref, new_node) : insertarDescendentementePorDia(head_ref,new_node);
       
}

/* Function to call in case newNode is greater than head by hour*/
void insertarAlRestoPorHoraDescendente(Asignatura** head_ref, Asignatura* new_node)
{
    Asignatura* current;
    current = *head_ref;
    int condicionInsertarAlInicio = (*head_ref)->diaSemana == new_node->diaSemana && ( ((*head_ref)->horarioEntrada->hora + ((*head_ref)->horarioEntrada->minuto)/60) <= (new_node->horarioEntrada->hora + (new_node->horarioEntrada->minuto)/60)); 
    int horaMenor=0; //auxiliar para determinar el orden de insercion

    if ((*head_ref) != NULL && condicionInsertarAlInicio==1) {
        insertarAlInicio(head_ref,new_node);
    }else{
        int nuevoNodoSmallerThanCurrent = current-> next ->horarioEntrada->hora + (current -> next -> horarioEntrada->minuto)/60 >= new_node->horarioEntrada->hora +(new_node->horarioEntrada->minuto)/60;

        while ((current->next != NULL) && (current -> next -> diaSemana >= new_node -> diaSemana) && (nuevoNodoSmallerThanCurrent == 1)){
            /*Insertar horas mayores*/
            
            if( (current -> next -> diaSemana == new_node -> diaSemana) && (!nuevoNodoSmallerThanCurrent) ){
            current = current->next;
            insertarDepues(&current, new_node);
            horaMenor = 1;
            }
            current = current->next;
        }
        if(horaMenor == 0){
            insertarDepues(&current, new_node);
        }
    }
}

/*ORDEN ASCENDENTE*/

/* Function to call in case newNode is greater than head*/
void insertarAlRestoPorDiaAscendente(Asignatura** head_ref, Asignatura* new_node)
{
    Asignatura* current;
    current = *head_ref;

    while (current->next != NULL && current->next->diaSemana <= new_node->diaSemana) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

/* Function to insert in ascending order*/
void insertarAscendentementePorDia(Asignatura** head_ref, Asignatura* new_node)
{
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->diaSemana >= new_node->diaSemana) {
        insertarAlInicio(head_ref,new_node);
    }
    else {
        insertarAlRestoPorDiaAscendente(head_ref, new_node);
    }
}
 
/*Function to create a new node */
Asignatura* newAsignatura()
{
    Asignatura* new_node = (Asignatura*)malloc(sizeof(Asignatura));
 
    return new_node;
}
 
/* Function to print linked list */
void printList(Asignatura* head)
{
    Asignatura* temp = head;
    while (temp != NULL) {
        printf("\nNombre: %s", temp->nombreAsignatura);
        printf("\nDia de la semana: %d", temp->diaSemana);
        printf("\nHora entrada-> %d:%d", temp->horarioEntrada->hora, temp->horarioEntrada->minuto);
        printf("\nHora salida-> %d:%d\n", temp->horarioSalida->hora, temp->horarioSalida->minuto);
        temp = temp->next;
    }
}

/* Function to read linked list, field by field*/
void read(Asignatura *head)
{
    Asignatura *currentNode;
    currentNode = head;
    char palabra[50];
    
    printf("Nombre: ");
    fflush(stdin);
    gets(palabra);
    currentNode->nombreAsignatura = (char *)malloc(sizeof(char)*(strlen(palabra)+1));
    strcpy(currentNode->nombreAsignatura,palabra);
    
    printf("Dia semana: ");
    scanf("%d", &currentNode->diaSemana);
    
    currentNode->horarioEntrada = (Fecha *)malloc(sizeof(Fecha));
    printf("Hora entrada: ");
    scanf("%d", &currentNode->horarioEntrada->hora);
    printf("Minutos entrada: ");
    scanf("%d", &currentNode->horarioEntrada->minuto);

    currentNode->horarioSalida = (Fecha *)malloc(sizeof(Fecha));
    printf("Hora salida: ");
    scanf("%d", &currentNode->horarioSalida->hora);
    printf("Minutos salida: ");
    scanf("%d", &currentNode->horarioSalida->minuto);
    currentNode->next = NULL;
}

/* Validates for new nodes, asks for creation and introduces data*/
Asignatura* inputController(Asignatura *head)
{
    Asignatura* new_node = newAsignatura();

    int creator;
    printf("\nDeseas agregar una materia? Si[1], NO[0]: ");
    scanf("%d",&creator);

    while (creator == 1)
    {
        new_node = newAsignatura();
        read(new_node);

        /*------Escoger el tipo de ordenamiento-------*/

        //insertarAscendentementePorDia(&head, new_node); 
        //addToLast(&head, new_node);
        insertarDescendentementePorHora(&head,new_node); 
        //insertarDescendentementePorDia(&head,new_node); 

        printf("\nDeseas agregar una materia? Si[1], NO[0]: ");
        scanf("%d",&creator);
    }
    
    return head;
}

int main(){
    /* Start with the empty list */
    Asignatura* head = NULL;
    head = inputController(head);

    printList(head);
 
    return 0;
}