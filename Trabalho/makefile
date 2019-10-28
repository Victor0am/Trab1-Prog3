CC=g++

all: compile

compile:
	
	@echo "Compilando . . ."
	@$(CC) -c main.cpp codes/*.cpp -std=c++17
	@$(CC) -o trabalho *.o
	

clean:
	@clear 
	@echo "Limpando arquivos . . ."
	@rm *.o

run: 
	@./trabalho -g entradas/generos.csv -u entradas/usuarios.csv -m entradas/midias_corrigidas.csv -f entradas/favoritos.csv
	@echo "Relatorios gerados com sucesso!"
	
runv:
	@valgrind ./trabalho -g entradas/generos.csv -u entradas/usuarios.csv -m entradas/midias_corrigidas.csv -f entradas/favoritos.csv
	@echo "Relatorios gerados com sucesso!"