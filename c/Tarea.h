#ifndef TAREA_H
#define TAREA_H

#include <stddef.h>
#include <stdbool.h>

typedef enum { PRIORIDAD_BAJA, PRIORIDAD_ALTA, PRIORIDAD_URGENTE, PRIORIDAD_POR_DEFECTO} Prioridad;
typedef enum { ESTADO_ESPERA, ESTADO_EJECUCION, ESTADO_COMPLETADA } Estado;

typedef struct 
{
    size_t id, tiempoRestante;
    Prioridad prioridad;
    Estado estado;
} Tarea;

Tarea crearTarea(size_t tiempoRestante, Prioridad prioridad);
bool mayorPrioridad(const Tarea* A, const Tarea* B);

#endif //TAREA_H