
all:= $(TARGET)
cc:=g++
CFLAGS:= -g -Wall
TARGET:= sudoku
MAIN:= main
GRID:= grid
MATRIX:= matrix
LOADFILE:= loadFile

$(TARGET): $(MAIN).o $(MATRIX).o $(GRID).o $(LOADFILE).o
	$(cc)  -o $(TARGET) $(MAIN).o $(MATRIX).o $(GRID).o $(LOADFILE).o

$(MAIN).o: $(MAIN).cpp $(MATRIX).h $(GRID).h config.h $(LOADFILE).h
	$(cc)  -c $(MAIN).cpp


$(MATRIX).o: $(MATRIX).cpp $(GRID).o config.h
	$(cc)  -c $(MATRIX).cpp

$(GRID).o: $(GRID).cpp $(GRID).h config.h
	$(cc)  -c $(GRID).cpp

$(LOADFILE).o : $(LOADFILE).cpp $(LOADFILE).h
	$(cc) -c $(LOADFILE).cpp
clean: 
	rm *.o 
	rm $(TARGET)


	
