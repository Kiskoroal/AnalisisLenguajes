#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>
#include <string>
#include <cstdlib> //Códigos de salida
#include <chrono> //Cronometro de tiempo

#include "Tarea.hpp"

std::priority_queue<Tarea, std::vector<Tarea>, std::greater<Tarea>> introducirTareas(size_t nTareas) 
{
    std::priority_queue<Tarea, std::vector<Tarea>, std::greater<Tarea>> tareas;
    for(size_t i = 1; i <= nTareas; ++i)
        tareas.push((Tarea((i % 5000) + 1, Tarea::Prioridad(i % 3))));
    
    
    
    return tareas;
}

void despacharTareas(std::priority_queue<Tarea, std::vector<Tarea>, std::greater<Tarea>>& colaTareas) 
{
    //Vamos a despachar las n tareas
    while(!colaTareas.empty()) 
    {
        Tarea tarea = colaTareas.top();
        
        while(tarea.tiempoRestante() > 0) 
        {
            tarea.tiempoRestante() -= 1;
        }

        //Una vez completada la tarea la sacamos de la cola
        colaTareas.pop();
    }
}

size_t tratarArgumentos(int argc, char* argv[]) {
    if (argc != 2) {
        // Lanzamos un error formateado con el nombre del ejecutable
        throw std::invalid_argument(std::string("Uso incorrecto. Ejecucion esperada:\n") + 
                                    argv[0] + " <numero_de_tareas>");
    }

    size_t num_tareas = 0;

    try {
        num_tareas = std::stoull(argv[1]);
    } 
    catch (const std::invalid_argument&) {
        throw std::invalid_argument("Error: El parametro debe ser un numero entero.");
    } 
    catch (const std::out_of_range&) {
        throw std::out_of_range("Error: El numero introducido es demasiado grande.");
    }

    if (num_tareas == 0) {
        throw std::invalid_argument("Error: El numero de tareas debe ser mayor a 0.");
    }

    return num_tareas;
}


int main(int argc, char* argv[]) 
{
    size_t numTareas;

    try {
        numTareas = tratarArgumentos(argc, argv);
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    std::cout << "Generando " << numTareas << " tarea" << (numTareas == 1 ? ".\n" : "s.\n");

    std::priority_queue<Tarea, std::vector<Tarea>, std::greater<Tarea>> colaTareas = introducirTareas(numTareas);
    
    //Cronometramos solo la tarea de simular ya que se presuponen las tareas ya cargadas en memoria
    auto t0 = std::chrono::high_resolution_clock::now();
    despacharTareas(colaTareas);
    auto t1 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diferencia = t1 - t0;

    std::cout << numTareas << ": " << diferencia.count() << "\n";


    return EXIT_SUCCESS;
}