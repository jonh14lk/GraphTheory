#ifndef kruskal
#define kruskal
#include <bits/stdc++.h>
using namespace std;

struct kruskal_edge
{
  int u, v, cost;
};

int dsu_find(vector<int> &parent, int v);

bool dsu_union(vector<int> &parent, int x, int y);

void init_dsu(int n, vector<int> &parent);

bool kruskal_comparator(kruskal_edge a, kruskal_edge b);

vector<kruskal_edge> get_mst(vector<kruskal_edge> &edges, vector<int> &parent, int &sum);

void add_edge_kruskal(vector<kruskal_edge> &edges, int u, int v, int cost);

void read_graph_kruskal(int &n, int &m, vector<kruskal_edge> &edges);

void run_kruskal();

#endif