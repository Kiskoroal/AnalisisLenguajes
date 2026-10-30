CXX = clang++

CXXFLAGS = -std=c++17 -O3 -Wall -Wextra -Wpedantic

EXE = analisis

OBJS = Tarea.o analisis.o

$(EXE) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(LDFLAGS) $^ $(LDLIBS)

all : $(EXE)

Tarea.o : Tarea.hpp

analisis.o : analisis.cpp Tarea.hpp

clean : 
	$(RM) *.o