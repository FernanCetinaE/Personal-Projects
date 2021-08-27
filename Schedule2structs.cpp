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

void leer(Asignatura *head);
void llenarNodos(Asignatura *head);
Asignatura *iniciarNodo();
void imprimir(Asignatura *head);
void concatenar(Asignatura *first, Asignatura *second);

Asignatura *iniciarNodo()
{
    Asignatura *nuevo = (Asignatura *)malloc(sizeof(Asignatura));
    nuevo->next = NULL;
    return nuevo;
}

void concatenar(Asignatura *first, Asignatura *second)
{
    Asignatura *temp = first;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = second;
}

void leer(Asignatura *head)
{
    int numMaterias = 1;

    if (head == NULL)
    {
        printf("Memoria insuficiente");
    }
    else
    {

        llenarNodos(head);

        puts("\nDesea agregar otro nodo? Si[1], No[0]: ");
        scanf("%d", &numMaterias);

        while (numMaterias == 1)
        {
            Asignatura *newNode = iniciarNodo();
            llenarNodos(newNode);
            concatenar(head, newNode);

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

void llenarNodos(Asignatura *head)
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
    Asignatura *head = iniciarNodo();

    leer(head);
    imprimir(head);

    return 0;
}