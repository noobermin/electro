INCLUDE=../
HEADERS=$(INCLUDE)/noob3d/prim.hpp $(INCLUDE)/noob3d/vector.hpp $(INCLUDE)/noob3d/numer.hpp \
	$(INCLUDE)/noob3d/types.hpp $(INCLUDE)/noob3d/matrix.hpp $(INCLUDE)/electro.hpp

threadtest: threadtest.cpp $(HEADERS)
	$(CXX) -g -I$(INCLUDE) --std=c++11 threadtest.cpp -o threadtest -lpthread

deadtest: deadtest.cpp $(HEADERS)
	$(CXX) -g -I$(INCLUDE) --std=c++11 deadtest.cpp -o deadtest -lpthread

all: threadtest deadtest

clean:
	rm threadtest deadtest

.Phony: clean all
