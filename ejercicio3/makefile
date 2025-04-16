CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRC = main.cpp \
	elegirAtaque.cpp \
	batalla.cpp \
    ../ejercicio2/personajeFactory.cpp \
    ../ejercicio2/randomNum.cpp \
    ../ejercicio1/personajes/guerreros.cpp \
    ../ejercicio1/personajes/magos.cpp\
    ../ejercicio1/armas/armasCombate.cpp \
    ../ejercicio1/armas/itemsMagicos.cpp

# Archivos objeto
OBJ = $(SRC:.cpp=.o)

# Nombre del ejecutable
EXEC = main

# Regla principal
.PHONY: all clean
all: $(EXEC)

# Compilar el ejecutable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJ) $(EXEC)