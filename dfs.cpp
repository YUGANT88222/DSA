#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;

void bfs(int startNode, map<int, vector<int>>& graph, bool visited[]) {
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << "Visited: " << node << endl;

        for (int neighbour : graph[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
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

    cout << "\nStarting BFS traversal from node 0:\n";
    bfs(0, graph, visited);

    return 0;
}
