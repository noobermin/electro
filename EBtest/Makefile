INCLUDE=../
HEADERS=$(INCLUDE)/noob3d/prim.hpp $(INCLUDE)/noob3d/vector.hpp $(INCLUDE)/noob3d/numer.hpp \
	$(INCLUDE)/noob3d/types.hpp $(INCLUDE)/noob3d/matrix.hpp $(INCLUDE)/electro.hpp
Btest: EBtest.cpp $(HEADERS)
	$(CXX) -g -I$(INCLUDE) --std=c++11 EBtest.cpp -o EBtest -lpthread

all: EBtest

clean:
	rm EBtest

.Phony: clean all
