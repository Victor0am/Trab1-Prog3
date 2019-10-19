all: compile clean exec showresult

compile:
	@echo "Compilando . . ."
	g++ -c main.cpp codes/Genero.cpp
	g++ -o trabalho main.o Genero.o

clean:
	rm *.o

exec: 
	./trabalho

showresult:
	@echo "Tada:"
	@cat saida.txt