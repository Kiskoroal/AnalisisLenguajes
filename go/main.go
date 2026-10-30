package main

import (
	"fmt"
	"os"
	"strconv"
	"time"
)

func tratarArgumentos() int {
	if len(os.Args) != 2 {
		fmt.Fprintf(os.Stderr, "Uso incorrecto: %s <numero_tareas>\n", os.Args[0])
		os.Exit(1)
	}
	numTareas, err := strconv.Atoi(os.Args[1])
	if err != nil || numTareas <= 0 {
		fmt.Fprintln(os.Stderr, "Error: El parámetro debe ser entero y mayor a 0.")
		os.Exit(1)
	}
	return numTareas
}

func introducirTareas(numTareas int) *PriorityQueue {
	cola := crearCola(numTareas)
	for i := 1; i <= numTareas; i++ {
		var prio Prioridad
		switch i % 3 {
		case 0: prio = PrioridadBaja
		case 1: prio = PrioridadAlta
		default: prio = PrioridadUrgente
		}
		cola.push(crearTarea((i%5000)+1, prio))
	}
	return cola
}

func despacharTareas(cola *PriorityQueue) {
	for !cola.vacia() {
		tDespachar := cola.top()
		for tDespachar.tiempoRestante > 0 {
			tDespachar.tiempoRestante--
		}
		cola.pop()
	}
}

func main() {
	numTareas := tratarArgumentos()
	cola := introducirTareas(numTareas)
	
	t0 := time.Now()
	despacharTareas(cola)
	t1 := time.Now()
	
	fmt.Printf("%d : %f\n", numTareas, t1.Sub(t0).Seconds())
}
