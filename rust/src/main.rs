mod tarea;
mod priority_queue;

use std::env;
use std::process;
use std::time::Instant;

use crate::tarea::{Prioridad, crear_tarea};
use crate::priority_queue::PriorityQueue;

fn tratar_argumentos() -> usize {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        eprintln!("Uso incorrecto: {} <numero_tareas>", args[0]);
        process::exit(1);
    }
    match args[1].parse::<usize>() {
        Ok(n) if n > 0 => n,
        _ => {
            eprintln!("Error: El parámetro debe ser entero y mayor a 0.");
            process::exit(1);
        }
    }
}

fn introducir_tareas(num_tareas: usize) -> PriorityQueue {
    let mut cola = PriorityQueue::crear_cola(num_tareas);
    for i in 1..=num_tareas {
        let prioridad = match i % 3 {
            0 => Prioridad::Baja,
            1 => Prioridad::Alta,
            _ => Prioridad::Urgente,
        };
        cola.push(crear_tarea(i, (i % 5000) + 1, prioridad));
    }
    cola
}

fn despachar_tareas(mut cola: PriorityQueue) {
    while let Some(mut t_despachar) = cola.pop() {
        while t_despachar.tiempo_restante > 0 {
            t_despachar.tiempo_restante -= 1;
        }
    }
}

fn main() {
    let num_tareas = tratar_argumentos();
    let cola = introducir_tareas(num_tareas);
    
    let t0 = Instant::now();
    despachar_tareas(cola);
    let t1 = Instant::now();
    
    println!("{} : {:.6}", num_tareas, t1.duration_since(t0).as_secs_f64());
}
