use std::cmp::Ordering;

#[derive(Eq, PartialEq, Copy, Clone)]
pub enum Prioridad { Baja = 0, Alta = 1, Urgente = 2 }

#[derive(Eq, PartialEq)]
pub struct Tarea {
    pub id: usize,
    pub tiempo_restante: usize,
    pub prioridad: Prioridad,
}

impl Ord for Tarea {
    fn cmp(&self, other: &Self) -> Ordering {
        let prio_cmp = (self.prioridad as u8).cmp(&(other.prioridad as u8));
        if prio_cmp != Ordering::Equal {
            return prio_cmp;
        }
        other.id.cmp(&self.id)
    }
}

impl PartialOrd for Tarea {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

pub fn crear_tarea(id: usize, tiempo_restante: usize, prioridad: Prioridad) -> Tarea {
    Tarea { id, tiempo_restante, prioridad }
}
