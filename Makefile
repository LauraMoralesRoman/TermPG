#Tell make to make one .out file for each .cpp file found in the current directory
.PHONY: run
.PHONY: clean
.PHONY: debug
.PHONY: docs
all: main build
	
DIRGUARD=@if [ ! -d "build" ]; then printf "\n\033[32mCreando directorio de build\033[0m\n"; mkdir build; fi

CXX=g++
CXXFLAGS= 
VPATH = tpg/

objects=build/framebuffer.o build/canvas.o build/draw.o build/vertex.o build/renderable.o 
renderer_obj=$(shell find tpg/drawing/engine | pcregrep -o2 '(.*?[^\/]\/)+(.*?)\.cpp' | sed -e 's/$$/.o/') 

main: $(objects) build/main.o $(renderobj) $(renderer_obj)
	$(CXX) $(CXXFLAGS) $^ -o main
	@printf "\n\033[32mCompilado terminado exitosamente\033[0m\n\n"

build/main.o: $(objects) main.cpp $(renderobj)
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

# 3D renderer
# TODO: hacer que se comprueben los archivos antes de hacer el build (en caso de que no hallan cambiado)
# TODO: hacer que los archivos se almacenen dentor de la carpeta build
$(renderer_obj): %.o: tpg/drawing/engine/%.cpp tpg/drawing/engine/%.hpp
	$(DIRGUARD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-@rm -v main
	-@rm -rv build/
	-@rm -rv ./*.o
	-@rm -rv docs/html
	-@rm -rv docs/latex

run: main
	@./main

debug:
	@$(eval CXXFLAGS=$(CXXFLAGS) -g)	
	$(MAKE) clean
	$(MAKE) main -e CXXFLAGS=$(CXXFLAGS)

docs:
	@if [ ! -d "docs" ]; then printf "\n\033[32mCreando directorio para la documentación\033[0m\n"; mkdir docs; fi
	doxygen Doxyfile
