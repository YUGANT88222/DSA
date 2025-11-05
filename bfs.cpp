#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void dfs(int node, map<int, vector<int>>& graph, bool visited[]) {
    visited[node] = true;
    cout << "Visited: " << node << endl;

    for (int neighbour : graph[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, graph, visited);
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter number of nodes: ";
    cin >> numNodes;
    cout << "Enter number of edges: ";
    cin >> numEdges;

    map<int, vector<int>> graph;

    cout << "Enter edges (u v) where u and v are nodes (0 to " << numNodes - 1 << "):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph
    }

    bool visited[numNodes];
    for (int i = 0; i < numNodes; ++i)
        visited[i] = false;

    cout << "\nStarting DFS traversal from node 0:\n";
    dfs(0, graph, visited);

    return 0;
}
