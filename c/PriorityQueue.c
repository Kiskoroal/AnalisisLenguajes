#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "PriorityQueue.h"

PriorityQueue* crearCola(nodo maxElementos) 
{
    PriorityQueue* nuevaCola = malloc(sizeof(PriorityQueue));
    

    if (nuevaCola == NULL) 
    {
        fprintf(stderr, "No se ha podido reservar espacio para la creacion de la cola.\n");
        return nuevaCola;
    }

    nuevaCola->colaTareas = malloc(maxElementos * sizeof(Tarea));

    if(nuevaCola->colaTareas == NULL) 
    {
        fprintf(stderr, "No se ha podido reservar espacio para la creacion de la cola.\n");
        free(nuevaCola);
        return NULL;
    }

    nuevaCola->maxElementos = maxElementos;
    nuevaCola->elementos = 0;

    return nuevaCola;    
}

void destruirCola(PriorityQueue* cola) 
{
    if(cola != NULL) 
    {
        cola->maxElementos = 0;
        cola->elementos = 0;
        free(cola->colaTareas);
        free(cola);
    }
}

static nodo hIzq(nodo i) 
{
    return 2 * i + 1;
}

static nodo hDer(nodo i) 
{
    return 2 * i + 2;
}

static nodo padre(nodo i) 
{
    assert(i >= 1); 
    return (i-1) / 2;
}

static void flotar(PriorityQueue* cola, nodo i) 
{
   assert(i < cola->maxElementos);
   Tarea tFlotar = cola->colaTareas[i];

   while(i > 0 && mayorPrioridad(&tFlotar, &cola->colaTareas[padre(i)])) 
   {
        cola->colaTareas[i] = cola->colaTareas[padre(i)];
        i = padre(i);
   }

   cola->colaTareas[i] = tFlotar;
}

static void hundir(PriorityQueue* cola, nodo i) 
{
    assert(i < cola->maxElementos);

    Tarea tHundir = cola->colaTareas[i];

    bool fin = false;

    nodo hMaxPrioridad;

    while(hIzq(i) < cola->elementos && !fin) 
    {
        //Si existe hijo derecho comparamos con el izqdo para tomar el de mayor prioridad para subir
        if(hDer(i) < cola->elementos && mayorPrioridad(&cola->colaTareas[hDer(i)], &cola->colaTareas[hIzq(i)])) 
            hMaxPrioridad = hDer(i);
        else 
            hMaxPrioridad = hIzq(i);
        
        if(mayorPrioridad(&cola->colaTareas[hMaxPrioridad], &tHundir)) 
        {
            cola->colaTareas[i] = cola->colaTareas[hMaxPrioridad];
            i = hMaxPrioridad;
        }
        else 
            fin = true;
    }

    cola->colaTareas[i] = tHundir;
}

void pop(PriorityQueue* cola) 
{
    assert(cola != NULL && cola->elementos > 0);

    if(--(cola->elementos) > 0) 
    {
        cola->colaTareas[0] = cola->colaTareas[cola->elementos];

        if(cola->elementos > 1)
            hundir(cola, 0);
    }
}

void push(PriorityQueue* cola, Tarea t) 
{
    assert(cola != NULL && cola->elementos < cola->maxElementos);

    cola->colaTareas[cola->elementos] = t;
    flotar(cola, cola->elementos);
    cola->elementos++;
}

Tarea top(PriorityQueue* cola) 
{
    assert(cola != NULL && cola->elementos > 0);
    return cola->colaTareas[0];
}

bool vacia(PriorityQueue* cola) { return cola == NULL || cola->elementos == 0; }