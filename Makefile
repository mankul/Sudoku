

cc:=GCC
CFLAGS:= -g -Wall
TARGET:= sudoku
MAIN:= main
GRID:= grid
MATRIX:= matrix

$(TARGET): $(MAIN).o $(MATRIX).o $(GRID).o
	$(cc) $(CFLAGS) -o $(TARGET) $(MAIN).o $(MATRIX).o $(GRID).o
$(MAIN).o: $(MAIN).cpp matrix.h grid.h config.h solver.h
	$(cc) $(CFLAGS) -o $(MAIN).o $(MAIN).cpp


$(MATRIX).o: $(MATRIX).cpp $(GRID).h config.h
	$(cc) $(CFLAGS) -o $(MATRIX).o -c $(MATRIX).cpp 

$(GRID).o: $(GRID).cpp $(GRID).h config.h
	$(cc) $(CFLAGS) -c $(GRID).cpp


clean: 
	rm $(TARGET)


	
