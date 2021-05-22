DIJKSTRA = src/dijkstra/dijkstra.cpp
KRUSKAL = src/kruskal/kruskal.cpp
FORD_FULKERSON = src/ford_fulkerson/ford_fulkerson.cpp
DINIC = src/dinic/dinic.cpp
MAIN = main.cpp

compile_algo:
	g++ $(DIJKSTRA) $(KRUSKAL) $(FORD_FULKERSON) $(DINIC) $(MAIN) -o algo