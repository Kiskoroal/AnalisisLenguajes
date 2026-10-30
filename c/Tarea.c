#include <assert.h> 

#include "Tarea.h"

static size_t ids = 0;

Tarea crearTarea(size_t tiempoRestante, Prioridad prioridad) 
{
    Tarea nuevaTarea;

    if(prioridad == PRIORIDAD_POR_DEFECTO)
        nuevaTarea.prioridad = PRIORIDAD_BAJA;
    else 
        nuevaTarea.prioridad = prioridad;

    nuevaTarea.tiempoRestante = tiempoRestante;

    nuevaTarea.id = ids + 1;

    ++ids;

    return nuevaTarea;
}

bool mayorPrioridad(const Tarea* A, const Tarea* B) 
{ 
    assert(A != NULL && B != NULL);
    //Política de desempate id menor
    return A->prioridad == B->prioridad ? A->id < B->id  : A->prioridad > B->prioridad; 
}

