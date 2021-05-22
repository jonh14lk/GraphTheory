#ifndef dinic
#define dinic
#include <bits/stdc++.h>
using namespace std;

struct dinic_edge
{
  int to, index, flow, capacity;
};

bool bfs(vector<vector<dinic_edge>> &graph, vector<int> &dist, int n, int source, int sink);

int dfs(vector<vector<dinic_edge>> &graph, vector<int> &dist, vector<int> &start, int sink, int u, int flow);

int dinic_max_flow(vector<vector<dinic_edge>> &graph, vector<int> &dist, vector<int> &start, int n, int source, int sink);

void dinic_add_edge(vector<vector<dinic_edge>> &graph, int u, int v, int capacity);

void read_graph_dinic(int &n, int &m, vector<vector<dinic_edge>> &graph, int &source, int &sink);

void run_dinic();

#endif