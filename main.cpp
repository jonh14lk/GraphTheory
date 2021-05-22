#include "src/dijkstra/dijkstra.h"
#include "src/dinic/dinic.h"
#include "src/ford_fulkerson/ford_fulkerson.h"
#include "src/kruskal/kruskal.h"

int main(int argc, char const *argv[])
{
  string algo = argv[1];
  if (algo == "dijkstra")
  {
    run_dijkstra();
  }
  else if (algo == "kruskal")
  {
    run_kruskal();
  }
  else if (algo == "ford_fulkerson")
  {
    run_ford_fulkerson();
  }
  else if (algo == "dinic")
  {
    run_dinic();
  }
  return 0;
}