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
        inline size_t id() const { return id_; };
        inline Prioridad prioridad() const { return prioridad_; };
        inline size_t tiempoRestante() const { return tiempoRestante_; };
        inline Estado estado() const { return estado_; };

        //Métodos modificadores
        inline Prioridad& prioridad() { return prioridad_; };
        inline size_t& tiempoRestante() { return tiempoRestante_; };
        inline Estado& estado() { return estado_; };
    private :
        size_t id_, tiempoRestante_;
        Prioridad prioridad_;
        Estado estado_;
        static size_t ids;
};

bool operator <(const Tarea& , const Tarea& );
bool operator >(const Tarea& , const Tarea& );

#endif //TAREA_HPP