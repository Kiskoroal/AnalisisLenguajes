#!/bin/bash

# Crear la carpeta local para los resultados compartidos
mkdir -p dats

echo "Construyendo la imagen de Docker (esto tomará unos minutos la primera vez)..."
docker build -t benchmark-suite .

echo "Iniciando el contenedor efímero..."
# -v monta la carpeta local 'dats' en la ruta '/app/dats' del contenedor
# --rm asegura que el contenedor se elimine de tu PC en cuanto termine
docker run --rm -v "$(pwd)/dats:/app/dats" benchmark-suite

echo "Proceso finalizado. El contenedor ha sido eliminado."
echo "Resultados exportados en la carpeta ./dats:"
ls -lh dats