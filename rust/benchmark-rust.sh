#!/bin/bash
OUTPUT_FILE="benchmark-rust.dat"
echo "=== Iniciando compilación en Rust ==="
cargo build --release
if [ $? -ne 0 ]; then
    echo "ERROR: La compilación ha fallado."
    exit 1
fi
echo "=== RESULTADOS BENCHMARK RUST ===" > $OUTPUT_FILE
for (( tareas=1000; tareas<=100000; tareas+=1000 ))
do
    echo "[!] Ejecutando Rust con carga: $tareas tareas"
    echo "---- Carga: $tareas tareas ----" >> $OUTPUT_FILE
    ./target/release/benchmark-rust $tareas >> $OUTPUT_FILE
    echo "" >> $OUTPUT_FILE 
done
echo "=== Batería de pruebas en Rust finalizada ==="
