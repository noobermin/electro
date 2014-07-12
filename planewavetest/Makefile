INCLUDE=../
HEADERS=$(INCLUDE)/noob3d/prim.hpp $(INCLUDE)/noob3d/vector.hpp $(INCLUDE)/noob3d/numer.hpp \
	$(INCLUDE)/noob3d/types.hpp $(INCLUDE)/noob3d/matrix.hpp $(INCLUDE)/electro.hpp
planewavetest: planewavetest.cpp $(HEADERS)
	$(CXX) -g -I$(INCLUDE) --std=c++11 planewavetest.cpp -o planewavetest -lpthread

all: planewavetest

clean:
	rm planewavetest

.Phony: clean all
