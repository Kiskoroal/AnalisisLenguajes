#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "Tarea.h"

typedef size_t nodo;

typedef struct 
{
    Tarea* colaTareas;
    nodo maxElementos;
    nodo elementos;
} PriorityQueue;

PriorityQueue* crearCola(nodo maxElementos);

void destruirCola(PriorityQueue* cola);

bool vacia(PriorityQueue* cola);

void push(PriorityQueue* cola, Tarea t);
void pop(PriorityQueue* cola);
const Tarea* top(PriorityQueue* cola);

#endif