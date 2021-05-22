#include <bits/stdc++.h>
using namespace std;

struct kruskal_edge
{
  int u, v, cost;
};

int dsu_find(vector<int> &parent, int v)
{
  return parent[v] = (parent[v] == v) ? v : dsu_find(parent, parent[v]);
}
bool dsu_union(vector<int> &parent, int x, int y)
{
  int x_parent = dsu_find(parent, x);
  int y_parent = dsu_find(parent, y);
  if (x_parent != y_parent)
  {
    parent[x_parent] = y_parent;
    return true;
  }
  return false;
}
void init_dsu(int n, vector<int> &parent)
{
  parent.resize(n);
  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }
}
bool kruskal_comparator(kruskal_edge a, kruskal_edge b)
{
  return a.cost < b.cost;
}
vector<kruskal_edge> get_mst(vector<kruskal_edge> &edges, vector<int> &parent, int &sum)
{
  sort(edges.begin(), edges.end(), kruskal_comparator);
  vector<kruskal_edge> answer;
  for (auto const &i : edges)
  {
    int v = i.v, u = i.u, cost = i.cost;
    if (dsu_find(parent, v) != dsu_find(parent, u))
    {
      dsu_union(parent, u, v);
      sum += cost;
      answer.push_back({u, v, cost});
    }
  }
  return answer;
}
void add_edge_kruskal(vector<kruskal_edge> &edges, int u, int v, int cost)
{
  edges.push_back({u, v, cost});
}
void read_graph_kruskal(int &n, int &m, vector<kruskal_edge> &edges)
{
  cin >> n >> m;
  edges.resize(n);
  for (int i = 0; i < m; i++)
  {
    int u, v, cost;
    cin >> u >> v >> cost;
    add_edge_kruskal(edges, u, v, cost);
  }
}
void run_kruskal()
{
  int n, m, sum = 0;
  vector<kruskal_edge> edges;
  vector<int> parent;
  read_graph_kruskal(n, m, edges);
  init_dsu(n, parent);
  vector<kruskal_edge> answer = get_mst(edges, parent, sum);
  cout << "Arestas da arvore geradora minima:" << endl;
  for (auto const &i : answer)
  {
    cout << "(" << i.u << ", " << i.v << ") - custo: " << i.cost << endl;
  }
  cout << "Custo total: " << sum << endl;
}