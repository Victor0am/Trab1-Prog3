CC=g++
EXE=trabalho

all: compile

compile:
	@clear
	@echo "Compilando . . ."
	@$(CC) -c main.cpp codes/*.cpp -std=c++17
	@$(CC) -o trabalho *.o
	@clear && echo "Pronto"

clean:
	@clear 
	@echo "Limpando arquivos . . ."
	@rm *.o

# run: 
# 	@ ./$(EXE) -g entradas/generos.csv -u entradas/usuarios.csv -m entradas/midias_corrigidas.csv -f entradas/favoritos.csv
# 	@echo "Relatorios gerados com sucesso!"
	
runv:
	@valgrind ./trabalho -g entradas/generos.csv -u entradas/usuarios.csv -m entradas/midias_corrigidas.csv -f entradas/favoritos.csv
	@echo "Relatorios gerados com sucesso!"