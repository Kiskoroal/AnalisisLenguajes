#!/bin/bash

OUTPUT_FILE="benchmark-c.dat"

echo "=== Iniciando compilación en C ==="
make

if [ $? -ne 0 ]; then
    echo "ERROR: La compilación ha fallado."
    exit 1
fi

echo "Compilación exitosa. Arrancando simulaciones..."
echo "Guardando resultados en: $OUTPUT_FILE"
echo "==============================================="

echo "=== RESULTADOS BENCHMARK C ===" > $OUTPUT_FILE

for (( tareas=1000; tareas<=100000; tareas+=1000 ))
do
    echo "[!] Ejecutando C con carga: $tareas tareas"
    
    echo "---- Carga: $tareas tareas ----" >> $OUTPUT_FILE
    ./analisis $tareas >> $OUTPUT_FILE
    echo "" >> $OUTPUT_FILE 
    
    sleep 1
done

make clean

echo "=== Batería de pruebas en C finalizada ==="
echo "Puedes ver los resultados escribiendo: cat $OUTPUT_FILE"