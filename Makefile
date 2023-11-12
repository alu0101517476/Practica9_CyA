CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = Alfabeto.cc Cadena.cc Cinta.cc Cliente.cc Estado.cc Lenguaje.cc MaquinaDeTuring.cc Simbolo.cc Transicion.cc
OBJ = $(SRC:.cc=.o)
EXEC = p09_simulador_MT

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)