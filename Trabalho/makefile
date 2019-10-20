all: compile clean exec showresult

compile:
	@echo "Compilando . . ."
	g++ -c main.cpp codes/*.cpp
	g++ -o trabalho *.o

clean:
	rm *.o

exec: 
	./trabalho -g entradas/generos.csv -u entradas/usuarios.csv

showresult:
	@echo "Tada:"
	@cat saida.txt
	@echo "==========================="
	@cat saida2.txt