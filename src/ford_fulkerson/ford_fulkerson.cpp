#include <bits/stdc++.h>
using namespace std;

#define INF 1e8

struct ford_edge
{
  int u, capacity, back_edge;
};

void get_current_flow(int &current_flow, vector<vector<ford_edge>> &adj, vector<int> &parent,
                      int source, int v, int min_capacity)
{
  if (v == source)
  {
    current_flow = min_capacity;
    return;
  }
  if (parent[v] != -1)
  {
    int index = parent[v];
    int u = adj[v][index].u;
    int back_edge = adj[v][index].back_edge;
    int capacity = adj[u][back_edge].capacity;
    get_current_flow(current_flow, adj, parent, source, u, min(min_capacity, capacity));
    adj[u][back_edge].capacity -= current_flow;
    adj[v][index].capacity += current_flow;
  }
}
void bfs(int n, int source, int sink, vector<vector<ford_edge>> &adj,
         vector<bool> &visited, vector<int> &parent)
{
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
    parent[i] = -1;
  }
  visited[source] = true;
  queue<int> q;
  q.push(source);
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    if (v == sink)
      break;
    for (int i = 0; i < adj[v].size(); i++)
    {
      int u = adj[v][i].u, capacity = adj[v][i].capacity, back_edge = adj[v][i].back_edge;
      if (capacity > 0 && !visited[u])
      {
        visited[u] = true;
        q.push(u);
        parent[u] = back_edge;
      }
    }
  }
}
int ford_fulkerson_max_flow(int n, int source, int sink, vector<vector<ford_edge>> &adj,
                            vector<bool> &visited, vector<int> &parent)
{
  int max_flow = 0;
  while (true)
  {
    int current_flow = 0;
    bfs(n, source, sink, adj, visited, parent);
    get_current_flow(current_flow, adj, parent, source, sink, INF);
    if (current_flow == 0)
      break;
    max_flow += current_flow;
  }
  return max_flow;
}
void add_edge_ford(vector<vector<ford_edge>> &adj, int u, int v, int capacity)
{
  adj[u].push_back({v, capacity, (int)adj[v].size()});
  adj[v].push_back({u, 0, (int)adj[u].size() - 1});
}
void read_graph_ford(int &n, int &m, int &source, int &sink, vector<vector<ford_edge>> &adj)
{
  cin >> n >> m;
  adj.resize(n);
  for (int i = 0; i < m; i++)
  {
    int u, v, capacity;
    cin >> u >> v >> capacity;
    add_edge_ford(adj, u, v, capacity);
  }
  cin >> source >> sink;
}
void run_ford_fulkerson()
{
  int n, m, source, sink;
  vector<vector<ford_edge>> adj;
  vector<bool> visited;
  vector<int> parent;
  read_graph_ford(n, m, source, sink, adj);
  visited.resize(n);
  parent.resize(n);
  cout << "Fluxo Maximo de " << source << " ate " << sink << " = ";
  cout << ford_fulkerson_max_flow(n, source, sink, adj, visited, parent) << endl;
}