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

void inputController(Asignatura *head);
void leer(Asignatura *head);
Asignatura *crearNodo();
void imprimir(Asignatura *head);
void agregarAlFinal(Asignatura *first, Asignatura *second);
void sortedInsert(Asignatura* head_ref, Asignatura* new_node);

Asignatura *crearNodo()
{
    Asignatura *nuevo = (Asignatura *)malloc(sizeof(Asignatura));
    nuevo->next = NULL;
    return nuevo;
}

void agregarAlFinal(Asignatura *first, Asignatura *second)
{
    Asignatura *temp = first;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = second;
}

void sortedInsert(Asignatura* head_ref, Asignatura* new_node)
{
    Asignatura* current;
    /* Special case for the head end */
    if (head_ref == NULL || (head_ref)->diaSemana >= new_node->diaSemana) {
        new_node->next = head_ref;
        head_ref = new_node;
        printf("\nif");
    }
    else {
        /* Locate the node before
the point of insertion */
        printf("\nelse");
        current = head_ref;
        while (current->next != NULL && current->next->diaSemana < new_node->diaSemana) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void inputController(Asignatura *head)
{
    int numMaterias = 1;

    if (head == NULL)
    {
        printf("Memoria insuficiente");
    }
    else
    {

        leer(head);

        puts("\nDesea agregar otro nodo? Si[1], No[0]: ");
        scanf("%d", &numMaterias);

        while (numMaterias == 1)
        {
            Asignatura *newNode = crearNodo();
            leer(newNode);
            sortedInsert(head, newNode);

            puts("\nDesea agregar otro nodo? Si[1], No[0]: ");
            scanf("%d", &numMaterias);
        }
    }
}

void imprimir(Asignatura *head)
{
    Asignatura *pointer;
    pointer = head;

    printf("\nNombre: %s", head->nombreAsignatura);
    printf("\nDia de la semana: %d", head->diaSemana);
    printf("\nHora entrada: %d", head->horarioEntrada->hora);
    printf("\nMinuto entrada: %d", head->horarioEntrada->minuto);
    printf("\nHora salida: %d", head->horarioSalida->hora);
    printf("\nMinuto salida: %d\n", head->horarioSalida->minuto);

    while (pointer->next != NULL)
    {
        pointer = pointer->next;
        printf("\nNombre: %s", pointer->nombreAsignatura);
        printf("\nDia de la semana: %d", pointer->diaSemana);
        printf("\nHora entrada: %d", pointer->horarioEntrada->hora);
        printf("\nMinuto entrada: %d", pointer->horarioEntrada->minuto);
        printf("\nHora salida: %d", pointer->horarioSalida->hora);
        printf("\nMinuto salida: %d\n", pointer->horarioSalida->minuto);
    }
}

void leer(Asignatura *head)
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

int main()
{
    Asignatura *head = crearNodo();

    inputController(head);
    imprimir(head);

    return 0;
}