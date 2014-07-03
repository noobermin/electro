INCLUDE=../
HEADERS=$(INCLUDE)/noob3d/prim.hpp $(INCLUDE)/noob3d/vector.hpp $(INCLUDE)/noob3d/numer.hpp \
	$(INCLUDE)/noob3d/types.hpp $(INCLUDE)/noob3d/matrix.hpp
Btest: Btest.cpp $(HEADERS)
	$(CXX) -g -I$(INCLUDE) --std=c++11 Btest.cpp -o Btest

all: electro

clean:
	rm Btest

.Phony: clean all
