package main

type Prioridad int

const (
	PrioridadBaja Prioridad = iota
	PrioridadAlta
	PrioridadUrgente
)

type Tarea struct {
	id             int
	tiempoRestante int
	prioridad      Prioridad
}

var globalID = 0

func crearTarea(tiempo int, prio Prioridad) *Tarea {
	globalID++
	return &Tarea{
		id:             globalID,
		tiempoRestante: tiempo,
		prioridad:      prio,
	}
}
