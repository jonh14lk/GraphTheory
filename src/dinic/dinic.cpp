#include <bits/stdc++.h>
using namespace std;

#define INF 1e8

struct dinic_edge
{
  int to, index, flow, capacity;
};

bool bfs(vector<vector<dinic_edge>> &graph, vector<int> &dist, int n, int source, int sink)
{
  for (int i = 0; i < n; i++)
    dist[i] = -1;
  dist[source] = 0;
  queue<int> q;
  q.push(source);
  while (!q.empty())
  {
    int u = q.front();
    q.pop();

    for (auto at : graph[u])
    {
      if (at.flow > 0 && dist[at.to] == -1)
      {
        q.push(at.to);
        dist[at.to] = dist[u] + 1;
      }
    }
  }
  return dist[sink] != -1;
}
int dfs(vector<vector<dinic_edge>> &graph, vector<int> &dist, vector<int> &start,
        int sink, int u, int flow)
{
  if (u == sink)
    return flow;
  for (int &p = start[u]; p < graph[u].size(); p++)
  {
    dinic_edge &at = graph[u][p];
    if (at.flow > 0 && dist[u] == dist[at.to] - 1)
    {
      int current = dfs(graph, dist, start, sink, at.to, min(flow, at.flow));
      if (current > 0)
      {
        at.flow -= current;
        graph[at.to][at.index].flow += current;
        return current;
      }
    }
  }
  return 0;
}
int dinic_max_flow(vector<vector<dinic_edge>> &graph, vector<int> &dist, vector<int> &start,
                   int n, int source, int sink)
{
  int max_flow = 0;
  while (bfs(graph, dist, n, source, sink))
  {
    for (int i = 0; i < n; i++)
      start[i] = 0;
    while (true)
    {
      int flow = dfs(graph, dist, start, sink, source, INF);
      if (flow == 0)
        break;
      max_flow += flow;
    }
  }
  return max_flow;
}
void dinic_add_edge(vector<vector<dinic_edge>> &graph, int u, int v, int capacity)
{
  graph[u].push_back({v, (int)graph[v].size(), capacity, capacity});
  graph[v].push_back({u, (int)graph[u].size() - 1, 0, 0});
}
void read_graph_dinic(int &n, int &m, vector<vector<dinic_edge>> &graph, int &source, int &sink)
{
  cin >> n >> m;
  graph.resize(n);
  for (int i = 0; i < m; i++)
  {
    int u, v, capacity;
    cin >> u >> v >> capacity;
    dinic_add_edge(graph, u, v, capacity);
  }
  cin >> source >> sink;
}
void run_dinic()
{
  int n, m, source, sink;
  vector<vector<dinic_edge>> graph;
  vector<int> dist;
  vector<int> start;
  read_graph_dinic(n, m, graph, source, sink);
  dist.resize(n);
  start.resize(n);
  cout << "Fluxo Maximo de " << source << " ate " << sink << " = ";
  cout << dinic_max_flow(graph, dist, start, n, source, sink) << endl;
}