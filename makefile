TARGET = main.o client.o server.o  Parser.o SymbolTable.o Interpreter.o Connect.o OpenServerCommand.o Var.o While.o  Equal.o Sleep.o
CC = g++
CFLAGS = -std=c++17 -Wall -pedantic -c

main:	$(TARGET)
		$(CC) -o main $(TARGET) -pthread

main.o: *.cpp  
		$(CC)  $(CFLAGS) *.cpp

 
clean:
		rm *.o 