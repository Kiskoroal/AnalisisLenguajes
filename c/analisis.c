#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Tarea.h" //Declaración por claridad
#include "PriorityQueue.h"

// Esta macro le dice al compilador que habilite las funciones POSIX (como el reloj)
#define _POSIX_C_SOURCE 199309L

PriorityQueue* introducirTareas(size_t numTareas) 
{
    PriorityQueue* colaT = crearCola(numTareas);

    for(size_t i = 1; i <= numTareas; ++i) 
    {
        push(colaT, crearTarea((i % 5000) + 1, (i % 3)));
    }

    return colaT;
}

void despacharTareas(PriorityQueue* tareas) 
{
    while(!(vacia(tareas))) 
    {
        Tarea* tDespachar = top(tareas);

        while(tDespachar->tiempoRestante > 0) 
            tDespachar->tiempoRestante--;
        
        pop(tareas);
    }
}

size_t tratarArgumentos(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        fprintf(stderr, "Uso incorrecto: %s <numero_tareas>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char* endptr;
    // strtoull es el equivalente en C puro a std::stoull de C++
    size_t num_tareas = strtoull(argv[1], &endptr, 10);
    
    // Verificamos si el usuario coló letras después del número (ej: "1000abc")
    if (*endptr != '\0') 
    {
        fprintf(stderr, "Error: El parámetro debe ser un número entero.\n");
        exit(EXIT_FAILURE);
    }
    
    // Evitamos ejecutar con 0 tareas
    if (num_tareas == 0) 
    {
        fprintf(stderr, "Error: El número de tareas debe ser mayor a 0.\n");
        exit(EXIT_FAILURE);
    }
    
    return num_tareas;
}

double obtenerTiempo() 
{
    return (double)clock() / CLOCKS_PER_SEC;
}

int main(int argc, char* argv[]) 
{
    int numTareas = tratarArgumentos(argc, argv);

    PriorityQueue* colaT = introducirTareas(numTareas);

    double t0 = obtenerTiempo();

    despacharTareas(colaT);

    double t1 = obtenerTiempo();

    destruirCola(colaT);

    printf("%d : %f", numTareas, t1 - t0);

    return EXIT_SUCCESS;
}