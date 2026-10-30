package main

import "container/heap"

type tareaHeap []*Tarea

func (h tareaHeap) Len() int { return len(h) }
func (h tareaHeap) Less(i, j int) bool {
	if h[i].prioridad == h[j].prioridad {
		return h[i].id < h[j].id 
	}
	return h[i].prioridad > h[j].prioridad 
}
func (h tareaHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *tareaHeap) Push(x any)         { *h = append(*h, x.(*Tarea)) }
func (h *tareaHeap) Pop() any {
	old := *h
	n := len(old)
	item := old[n-1]
	old[n-1] = nil 
	*h = old[0 : n-1]
	return item
}

type PriorityQueue struct {
	th tareaHeap
}

func crearCola(maxElementos int) *PriorityQueue {
	h := make(tareaHeap, 0, maxElementos)
	return &PriorityQueue{th: h}
}

func (pq *PriorityQueue) push(t *Tarea) {
	heap.Push(&pq.th, t)
}
func (pq *PriorityQueue) top() *Tarea {
	return pq.th[0]
}
func (pq *PriorityQueue) pop() {
	heap.Pop(&pq.th)
}
func (pq *PriorityQueue) vacia() bool {
	return len(pq.th) == 0
}
