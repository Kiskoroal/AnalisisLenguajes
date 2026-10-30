use std::collections::BinaryHeap;
use crate::tarea::Tarea;

pub struct PriorityQueue {
    cola: BinaryHeap<Tarea>,
}

impl PriorityQueue {
    pub fn crear_cola(capacidad: usize) -> Self {
        Self { cola: BinaryHeap::with_capacity(capacidad) }
    }
    pub fn push(&mut self, t: Tarea) {
        self.cola.push(t);
    }
    pub fn pop(&mut self) -> Option<Tarea> {
        self.cola.pop()
    }
}
