# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++17
BIN_DIR = bin

# Directorios
ARMAS_DIR = armas
PERSONAJES_DIR = personajes

# Archivos fuente
SOURCES = main.cpp \
          $(ARMAS_DIR)/armasCombate.cpp \
          $(ARMAS_DIR)/itemsMagicos.cpp \
          $(PERSONAJES_DIR)/guerreros.cpp \
          $(PERSONAJES_DIR)/magos.cpp

# Archivos de cabecera
HEADERS = $(ARMAS_DIR)/armas.hpp \
          $(ARMAS_DIR)/armasCombate.hpp \
          $(ARMAS_DIR)/itemsMagicos.hpp \
          $(PERSONAJES_DIR)/guerreros.hpp \
          $(PERSONAJES_DIR)/magos.hpp \
          $(PERSONAJES_DIR)/personajes.hpp \
          main.hpp

# Objetos
OBJECTS = $(SOURCES:.cpp=.o)

# Ejecutable final
EXEC = $(BIN_DIR)/main

# Regla por defecto
all: $(EXEC)

# Regla para crear el ejecutable
$(EXEC): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

# Regla para compilar los archivos .cpp a .o en la carpeta raíz y en las subcarpetas
$(ARMAS_DIR)/%.o: $(ARMAS_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PERSONAJES_DIR)/%.o: $(PERSONAJES_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar los archivos generados
clean:
	rm -rf $(BIN_DIR) $(ARMAS_DIR)/*.o $(PERSONAJES_DIR)/*.o *.o

# Recompilar todo
rebuild: clean all