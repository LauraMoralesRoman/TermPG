#Tell make to make one .out file for each .cpp file found in the current directory
.PHONY: clean
all: main 

CXX=g++
CXXFLAGS= 
VPATH = tpg/

objects=build/framebuffer.o build/canvas.o build/draw.o

main: $(objects) build/main.o
	$(CXX) $(CXXFLAGS) $^ -o main

build/main.o: $(objects) main.cpp
	$(CXX) $(CXXFLAGS) $^ -c -o $@

build/framebuffer.o: tpg/framebuffer/FrameBuffer.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
build/canvas.o: tpg/canvas/canvas.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@
build/draw.o: tpg/drawing/draw.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@rm -v main
	@rm -v build/*
