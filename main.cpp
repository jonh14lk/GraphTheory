#include "src/dijkstra/dijkstra.h"
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
  else if (algo == "ford-fulkerson")
  {
  }
  else if (algo == "hopcroft-karp")
  {
  }
  return 0;
}