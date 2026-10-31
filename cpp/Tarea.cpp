#include "Tarea.hpp"

size_t Tarea::ids{0};

Tarea::Tarea(size_t tiempoRestante, Tarea::Prioridad prioridad, Tarea::Estado estado) : id_{ids}, tiempoRestante_{tiempoRestante}, prioridad_{prioridad}, estado_{estado} { ++ids; }

//Sobrecarga operadores de comparación para complementar la simulación
bool operator <(const Tarea& A, const Tarea& B) 
{  
    //Política de desempate id mayor
    return A.prioridad() == B.prioridad() ? A.id() > B.id() : A.prioridad() < B.prioridad();
}

bool operator >(const Tarea& A, const Tarea& B) 
{
    //Política de desempate id menor
    return A.prioridad() == B.prioridad() ? A.id() < B.id() : A.prioridad() > B.prioridad();
}