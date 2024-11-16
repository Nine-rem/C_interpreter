# Compilateur et options
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
LDFLAGS = 

# Répertoires
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# Fichiers source et objets
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Nom de l'exécutable
TARGET = interpreter

# Règle par défaut
all: $(TARGET)

# Règle pour l'exécutable
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

# Règle pour les fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR) # Compatible Windows
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
