#include <bits/stdc++.h>
using namespace std;
#define INF 1e8

int shortest_path(int &n, vector<vector<pair<int, int>>> &adj_list,
                  vector<int> &dist, vector<bool> &visited, int s, int d)
{
  for (int i = 0; i < n; i++)
  {
    dist[i] = INF;
    visited[i] = false;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist[s] = 0;
  pq.push({dist[s], s});
  while (!pq.empty())
  {
    int v = pq.top().second;
    pq.pop();
    if (visited[v])
      continue;
    visited[v] = true;
    for (auto const &nxt : adj_list[v])
    {
      int cost = nxt.first;
      int u = nxt.second;
      if (dist[u] > dist[v] + cost)
      {
        dist[u] = dist[v] + cost;
        pq.push({dist[u], u});
      }
    }
  }
  return dist[d];
}
void add_dijkstra_edge(vector<vector<pair<int, int>>> &adj_list, int u, int v, int cost)
{
  adj_list[u].push_back({cost, v});
  adj_list[v].push_back({cost, u});
}
void read_dijkstra_graph(int &n, int &m, vector<vector<pair<int, int>>> &adj_list,
                         vector<int> &dist, vector<bool> &visited)
{
  cin >> n >> m;
  adj_list.resize(n);
  visited.resize(n);
  dist.resize(n);
  for (int i = 0; i < m; i++)
  {
    int u, v, cost;
    cin >> u >> v >> cost;
    add_dijkstra_edge(adj_list, u, v, cost);
  }
}
void run_dijkstra()
{
  int n, m;
  vector<vector<pair<int, int>>> adj_list;
  vector<int> dist;
  vector<bool> visited;
  read_dijkstra_graph(n, m, adj_list, dist, visited);
  int source, destiny;
  cin >> source >> destiny;
  int answer = shortest_path(n, adj_list, dist, visited, source, destiny);
  if (answer == INF)
  {
    cout << "Não existe caminho entre " << source << " e " << destiny << endl;
  }
  else
  {
    cout << "Distancia minima entre " << source << " e " << destiny << " = " << answer << endl;
  }
}
