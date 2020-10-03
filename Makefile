PKGS=sdl2
CXXFLAGS=$(CFLAGS) -std=c++17 -O0 -ggdb `pkg-config --cflags $(PKGS)`
LIBS=`pkg-config --libs $(PKGS) `

.PHONY: all
all: live-voronoi
	
live-voronoi: $(wildcard src/*cpp) $(wildcard src/*hpp) 
	$(CXX) $(CXXFLAGS) src/main.cpp -o live-voronoi $(LIBS) 

.PHONY: run
run: live-voronoi
	./live-voronoi

.PHONY: tests
tests: live-voronoi-tests
	./live-voronoi-tests
	
live-voronoi-tests: $(wildcard src/*cpp) $(wildcard src/*hpp) 
	$(CXX) $(CXXFLAGS) -DTESTS src/main.cpp -o live-voronoi-tests $(LIBS) 

.PHONY: format
format: 
	find src/ -iname *.hpp -o -iname *.cpp | xargs /opt/rh/llvm-toolset-7/root/usr/bin/clang-format -i -style=file
