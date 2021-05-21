DIJKSTRA = src/dijkstra/dijkstra.cpp
KRUSKAL = src/kruskal/kruskal.cpp
MAIN = main.cpp

compile_algo:
	g++ $(DIJKSTRA) $(KRUSKAL) $(MAIN) -o algo