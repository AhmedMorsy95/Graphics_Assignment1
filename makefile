all:	run
run:	gl.cpp
	g++ gl.cpp -lglut -lGL -lGLU && ./a.out && rm a.out
