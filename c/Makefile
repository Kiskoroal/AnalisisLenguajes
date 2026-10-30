CC = clang

CFLAGS = -std=c11 -Wall -Wextra -O3

EXE = analisis

OBJS = Tarea.o PriorityQueue.o analisis.o 

all : $(EXE)

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS) $^ $(LDLIBSs)

Tarea.o : Tarea.c Tarea.h

analisis.o : analisis.c Tarea.h PriorityQueue.h

PriorityQueue.o : PriorityQueue.c PriorityQueue.h



clean :
	$(RM) *.o