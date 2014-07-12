INCLUDE=../
LIBS=-lpthread -lboost_program_options
CXXOPTS=-g -std=c++11
HEADERS=$(INCLUDE)/noob3d/prim.hpp $(INCLUDE)/noob3d/vector.hpp $(INCLUDE)/noob3d/numer.hpp \
	$(INCLUDE)/noob3d/types.hpp $(INCLUDE)/noob3d/matrix.hpp $(INCLUDE)/electro.hpp
standingwave: standingwave.cpp $(HEADERS)
	$(CXX) $(CXXOPTS) -I$(INCLUDE) standingwave.cpp -o standingwave $(LIBS)

all: standingwave

clean:
	rm standingwave

.Phony: clean all
