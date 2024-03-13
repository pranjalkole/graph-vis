all: graph-vis

graph-vis:
	gcc -o graph-vis main.c -lraylib
