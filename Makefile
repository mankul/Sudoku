
all:= $(TARGET)
cc:=g++
CFLAGS:= -g -Wall
TARGET:= sudoku
MAIN:= main
GRID:= grid
MATRIX:= matrix

$(TARGET): $(MAIN).o $(MATRIX).o $(GRID).o
	$(cc)  -o $(TARGET) $(MAIN).o $(MATRIX).o $(GRID).o

$(MAIN).o: $(MAIN).cpp matrix.h grid.h config.h 
	$(cc)  -c $(MAIN).cpp


$(MATRIX).o: $(MATRIX).cpp $(GRID).o config.h
	$(cc)  -c $(MATRIX).cpp

$(GRID).o: $(GRID).cpp $(GRID).h config.h
	$(cc)  -c $(GRID).cpp


clean: 
	rm *.o 
	rm $(TARGET)


	
