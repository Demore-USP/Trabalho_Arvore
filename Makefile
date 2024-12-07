# Variáveis
CC = gcc # Compilador
CFLAGS = -O3 -Wall -g # Opções de compilação: otimização O3, avisos e depuração
EXEC = programa # Nome do executável
OBJ = Main.o ListaFilmes.o Arvore.o # Arquivos objeto

# Regra padrão
all: $(EXEC)

# Regra para criar o executável
$(EXEC): $(OBJ)
    $(CC) $(OBJ) -o $(EXEC)

# Regras para compilar os arquivos objeto
Main.o: Main.c ListaFilmes.h Arvore.h
    $(CC) $(CFLAGS) -c Main.c

ListaFilmes.o: ListaFilmes.c ListaFilmes.h
    $(CC) $(CFLAGS) -c ListaFilmes.c

Arvore.o: Arvore.c Arvore.h
    $(CC) $(CFLAGS) -c Arvore.c

# Limpeza dos arquivos gerados
clean:
    rm -f $(OBJ) $(EXEC)