#ifndef ford_fulkerson
#define ford_fulkerson
#include <bits/stdc++.h>
using namespace std;

struct ford_edge
{
  int u, capacity, back_edge;
};

void get_current_flow(int &current_flow, vector<vector<ford_edge>> &adj, vector<int> &parent, int source, int v, int min_capacity);

void bfs(int n, int source, int sink, vector<vector<ford_edge>> &adj, vector<bool> &visited, vector<int> &parent);

int get_max_flow(int &n, int &source, int &sink, vector<vector<ford_edge>> &adj, vector<bool> &visited, vector<int> &parent);

void add_edge_ford(vector<vector<ford_edge>> &adj, int u, int v, int capacity);

void read_graph_ford(int &n, int &m, int &source, int &sink, vector<vector<ford_edge>> &adj);

int ford_fulkerson_max_flow(int &n, int &source, int &sink, vector<vector<ford_edge>> &adj, vector<bool> &visited, vector<int> &parent);

#endif