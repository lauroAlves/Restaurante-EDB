# Nome do executável
TARGET = restaurante

# Arquivos fonte
SRCS = main.c menu.c pedido.c fila.c

# Arquivos objeto
OBJS = $(SRCS:.c=.o)

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Regra padrão: compila o executável
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Regra para compilar arquivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -f $(TARGET) $(OBJS)
