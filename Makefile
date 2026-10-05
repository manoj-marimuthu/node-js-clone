TARGET = node
COMMAND = g++ -g -Wall -Iincludes

OBJ = build/main.o \
      build/lexer.o

$(TARGET): $(OBJ)
	$(COMMAND) $(OBJ) -o $(TARGET)

build/main.o: main.cpp
	$(COMMAND) -c main.cpp -o build/main.o

build/lexer.o : src/lexer.cpp
	$(COMMAND) -c src/lexer.cpp -o build/lexer.o

clean:
	rm -Rf build/*.o node
