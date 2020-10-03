PKGS=sdl2
CXXFLAGS=$(CFLAGS) -std=c++17 -O0 -ggdb `pkg-config --cflags $(PKGS)`
LIBS=`pkg-config --libs $(PKGS) `

.PHONY: all
all: live-voronoi
	
live-voronoi:
	$(CXX) $(CXXFLAGS) src/main.cpp -o live-voronoi $(LIBS) 

.PHONY: format
format: 
	find src/ -iname *.hpp -o -iname *.cpp | xargs /opt/rh/llvm-toolset-7/root/usr/bin/clang-format -i -style=file
