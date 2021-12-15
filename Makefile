#Tell make to make one .out file for each .cpp file found in the current directory
.PHONY: run
.PHONY: clean
all: main build
	
DIRGUARD=if [ ! -d "build" ]; then printf "\033[32mCreando directorio de build\033[0m"; mkdir build; fi

CXX=g++
CXXFLAGS= 
VPATH = tpg/

objects=build/framebuffer.o build/canvas.o build/draw.o

main: $(objects) build/main.o
	$(CXX) $(CXXFLAGS) $^ -o main

build/main.o: $(objects) main.cpp
	$(CXX) $(CXXFLAGS) $^ -c -o $@

build/framebuffer.o: tpg/framebuffer/FrameBuffer.cpp
	$(DIRGUARD)
	$(CXX) $(CXXFLAGS) -c $^ -o $@
build/canvas.o: tpg/canvas/canvas.cpp
	$(DIRGUARD)
	$(CXX) $(CXXFLAGS) -c $^ -o $@
build/draw.o: tpg/drawing/draw.cpp
	$(DIRGUARD)	
	$(CXX) $(CXXFLAGS) -c $^ -o $@

build:
	if [ ! -d "build" ]; then printf "\033[32mCreando directorio de build\033[0m\g"; mkdir build; fi

clean:
	@rm -v main
	@rm -rv build/

run: main
	./main
