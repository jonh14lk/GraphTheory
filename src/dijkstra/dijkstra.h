#ifndef dijkstra
#define dijkstra
#include <bits/stdc++.h>
using namespace std;

int shortest_path(int &n, vector<vector<pair<int, int>>> &adj_list, vector<int> &dist, vector<bool> &visited, int s, int d);

void add_dijkstra_edge(vector<vector<pair<int, int>>> &adj_list, int u, int v, int cost);

void read_dijkstra_graph(int &n, int &m, vector<vector<pair<int, int>>> &adj_list, vector<int> &dist, vector<bool> &visited);

void run_dijkstra();

#endif