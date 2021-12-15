#Tell make to make one .out file for each .cpp file found in the current directory
.PHONY: clean
all: main build
	

CXX=g++
CXXFLAGS= 
VPATH = tpg/

objects=build/framebuffer.o build/canvas.o build/draw.o

main: $(objects) build/main.o
	$(CXX) $(CXXFLAGS) $^ -o main

build/main.o: $(objects) main.cpp
	$(CXX) $(CXXFLAGS) $^ -c -o $@

build/framebuffer.o: build tpg/framebuffer/FrameBuffer.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
build/canvas.o: build tpg/canvas/canvas.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
build/draw.o: build tpg/drawing/draw.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

build:
	mkdir -p build

clean:
	@rm -v main
	@rm -rv build/
