#include "Tarea.hpp"

size_t Tarea::ids{0};

Tarea::Tarea(size_t tiempoRestante, Tarea::Prioridad prioridad, Tarea::Estado estado) : id_{ids}, tiempoRestante_{tiempoRestante}, prioridad_{prioridad}, estado_{estado} { ++ids; }

size_t Tarea::id() const { return this->id_; }

Tarea::Prioridad Tarea::prioridad() const { return this->prioridad_; }
Tarea::Prioridad& Tarea::prioridad() { return this->prioridad_; }

size_t Tarea::tiempoRestante() const { return this->tiempoRestante_; }
size_t& Tarea::tiempoRestante() { return this->tiempoRestante_; }

Tarea::Estado Tarea::estado() const { return this->estado_; }
Tarea::Estado& Tarea::estado() { return this->estado_; }

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