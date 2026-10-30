#ifndef TAREA_HPP
#define TAREA_HPP

#include <cstddef>

class Tarea 
{
    public :
        enum class Estado { ESPERA, EJECUCION, COMPLETADA };
    
        enum class Prioridad { BAJA, ALTA, URGENTE };
        Tarea(size_t tiempoRestante, Prioridad prioridad = Prioridad::BAJA, Estado estadoTarea = Estado::ESPERA);

        //Métodos observadores
        size_t id() const;
        Prioridad prioridad() const;
        size_t tiempoRestante() const;
        Estado estado() const;

        //Métodos modificadores
        Prioridad& prioridad();
        size_t& tiempoRestante();
        Estado& estado();
    private :
        size_t id_, tiempoRestante_;
        Prioridad prioridad_;
        Estado estado_;
        static size_t ids;
};

bool operator <(const Tarea& , const Tarea& );
bool operator >(const Tarea& , const Tarea& );

#endif //TAREA_HPP