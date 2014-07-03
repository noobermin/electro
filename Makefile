INCLUDE=./
HEADERS=$(INCLUDE)/noob3d/prim.hpp $(INCLUDE)/noob3d/vector.hpp $(INCLUDE)/noob3d/numer.hpp \
	$(INCLUDE)/noob3d/types.hpp $(INCLUDE)/noob3d/matrix.hpp
electro: electro.cpp $(HEADERS)
	$(CXX) -g -I$(INCLUDE) --std=c++11 electro.cpp -o electro

all: electro

clean:
	rm electro

.Phony: clean all
