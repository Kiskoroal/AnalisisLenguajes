FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

# Instalar C/C++, Go y dependencias
RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    curl \
    golang-go \
    && rm -rf /var/lib/apt/lists/*

# Instalar Rust
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
ENV PATH="/root/.cargo/bin:${PATH}"

WORKDIR /app

# Copiar el código fuente usando el nuevo nombre de la carpeta
COPY . /app/benchmark

# Script interno con las rutas actualizadas a /app/benchmark/
RUN echo '#!/bin/bash\n\
echo "=== INICIANDO SUITE DE BENCHMARKS ==="\n\
mkdir -p /app/dats\n\
cd /app/benchmark/c && ./benchmark-c.sh && cp -f benchmark-c.dat /app/dats/\n\
cd /app/benchmark/cpp && ./benchmark-cpp.sh && cp -f benchmark-cpp.dat /app/dats/\n\
cd /app/benchmark/go && ./benchmark-go.sh && cp -f benchmark-go.dat /app/dats/\n\
cd /app/benchmark/rust && ./benchmark-rust.sh && cp -f benchmark-rust.dat /app/dats/\n\
echo "=== BENCHMARKS FINALIZADOS ==="\n\
' > /app/run_all.sh && chmod +x /app/run_all.sh

ENTRYPOINT ["/app/run_all.sh"]