#Tell make to make one .out file for each .cpp file found in the current directory
.PHONY: run
.PHONY: clean
.PHONY: debug
all: main build
	
DIRGUARD=if [ ! -d "build" ]; then printf "\033[32mCreando directorio de build\033[0m"; mkdir build; fi

CXX=g++
CXXFLAGS= 
VPATH = tpg/

objects=build/framebuffer.o build/canvas.o build/draw.o build/vertex.o build/renderable.o 

main: $(objects) build/main.o
	$(CXX) $(CXXFLAGS) $^ -o main
	@printf "\n\033[32mCompilado terminado exitosamente\033[0m\n"

build/main.o: $(objects) main.cpp
	$(CXX) $(CXXFLAGS) $^ -c -o $@

build/framebuffer.o: tpg/framebuffer/FrameBuffer.cpp tpg/framebuffer/FrameBuffer.hpp
	$(DIRGUARD)
	$(CXX) $(CXXFLAGS) -c $< -o $@
build/canvas.o: tpg/canvas/canvas.cpp tpg/canvas/canvas.hpp
	$(DIRGUARD)
	$(CXX) $(CXXFLAGS) -c $< -o $@
build/draw.o: tpg/drawing/draw.cpp tpg/drawing/draw.hpp
	$(DIRGUARD)	
	$(CXX) $(CXXFLAGS) -c $< -o $@
build/vertex.o: tpg/drawing/vertex.cpp tpg/drawing/vertex.hpp
	$(DIRGUARD)
	$(CXX) $(CXXFLAGS) -c $< -o $@
build/renderable.o: tpg/drawing/renderable.cpp tpg/drawing/renderable.hpp
	$(DIRGUARD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

build:
	@if [ ! -d "build" ]; then printf "\033[32mCreando directorio de build\033[0m\g"; mkdir build; fi

clean:
	-@rm -v main
	-@rm -rv build/

run: main
	./main

debug:
	@$(eval CXXFLAGS=$(CXXFLAGS) -g)	
	$(MAKE) clean
	$(MAKE) main -e CXXFLAGS=$(CXXFLAGS)

