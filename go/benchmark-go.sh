#!/bin/bash
OUTPUT_FILE="benchmark-go.dat"
echo "=== Iniciando compilación en Go ==="
go build -ldflags="-s -w" -o analisis-go main.go tarea.go priority_queue.go
if [ $? -ne 0 ]; then
    echo "ERROR: La compilación ha fallado."
    exit 1
fi
echo "=== RESULTADOS BENCHMARK GO ===" > $OUTPUT_FILE
for (( tareas=10000; tareas<=10000000; tareas+=10000 ))
do
    echo "[!] Ejecutando Go con carga: $tareas tareas"
    echo "---- Carga: $tareas tareas ----" >> $OUTPUT_FILE
    ./analisis-go $tareas >> $OUTPUT_FILE
    echo "" >> $OUTPUT_FILE 
done
echo "=== Batería de pruebas en Go finalizada ==="
