#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Fecha{
    int diaSemana;
    int hora;
    int minuto;
};

struct Asignatura{
    char *nombreAsignatura;
    Fecha *horarioEntrada;
    Fecha *horarioSalida;
    struct Asignatura *next;
}*head; 

typedef struct Asignatura Asignatura;
typedef struct Fecha Fecha;

void lectura();
void impresion();

void lectura(){
    Asignatura *newNode, *temp;
    head = (Asignatura *)malloc(sizeof(Asignatura));

    if(head == NULL){
        printf("Error de memoria");
    }else{
        printf("Nombre: ");
        head -> nombreAsignatura = (char*)malloc(sizeof(char));
        gets(head->nombreAsignatura);

        head -> horarioEntrada = (Fecha*)malloc(sizeof(Fecha));
        printf("Dia semana: ");
        scanf("%d", & head -> horarioEntrada ->diaSemana);
        printf("Hora entrada: ");
        scanf("%d", & head -> horarioEntrada ->hora);
        printf("Minutos entrada: ");
        scanf("%d", & head -> horarioEntrada ->minuto);

        head -> horarioSalida = (Fecha*)malloc(sizeof(Fecha));
        printf("Dia semana: ");
        scanf("%d", & head -> horarioSalida ->diaSemana);
        printf("Hora salida: ");
        scanf("%d", & head -> horarioSalida ->hora);
        printf("Minutos salida: ");
        scanf("%d", & head -> horarioSalida ->minuto);

        head->next = NULL;
        temp=head;

        for(int i=0;i<2;i++){
        newNode = (Asignatura*)malloc(sizeof(Asignatura));
        printf("\nNombre: ");
        newNode -> nombreAsignatura = (char*)malloc(sizeof(char));
        fflush(stdin);
        gets(newNode->nombreAsignatura);
        fflush(stdin);

        newNode -> horarioEntrada = (Fecha*)malloc(sizeof(Fecha));
        printf("Dia semana: ");
        scanf("%d", & newNode -> horarioEntrada ->diaSemana);
        printf("Hora entrada: ");
        scanf("%d", & newNode -> horarioEntrada ->hora);
        printf("Minutos entrada: ");
        scanf("%d", & newNode -> horarioEntrada ->minuto);

        newNode -> horarioSalida = (Fecha*)malloc(sizeof(Fecha));
        printf("Dia semana: ");
        scanf("%d", & newNode -> horarioSalida ->diaSemana);
        printf("Hora salida: ");
        scanf("%d", & newNode -> horarioSalida ->hora);
        printf("Minutos salida: ");
        scanf("%d", & newNode -> horarioSalida ->minuto);

        newNode->next = NULL; 
        temp->next = newNode;
        temp = temp->next;
        }

    }

}

void imprension(){
    Asignatura *pointer;
    pointer=head;

    while(pointer!=NULL){
        printf("\nNombre: %s", pointer->nombreAsignatura);
        printf("\nDia de la semana: %d", pointer -> horarioEntrada -> diaSemana);
        printf("\nHora entrada: %d", pointer -> horarioEntrada -> hora);
        printf("\nMinuto entrada: %d", pointer -> horarioEntrada -> minuto);
        printf("\nHora salida: %d", pointer -> horarioSalida -> hora);
        printf("\nMinuto salida: %d\n", pointer -> horarioSalida -> minuto);
        pointer = pointer -> next;
    }
}

int main(){
    lectura();
    imprension();

    return 0;
}