#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
vector<int> adj[MAX]; 
int level[MAX];       
int n, m;

void BFS(int source) {
    for (int i = 1; i <= n; i++) level[i] = -1; 
    level[source] = 0;
    queue<int> q;
    q.push(source);

    cout << "\nBFS Traversal: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];  
            if (level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    cout << endl;

    cout << "\nNode Levels:\n";
    for (int i = 1; i <= n; i++)
        cout << "Node " << i << " is at level " << level[i] << endl;
}
int main() {
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    for (int i = 1; i <= n; i++)
        adj[i].clear();

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);    
    }

    // adjacency list print
    cout << "\nAdjacency List:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int v : adj[i])
            cout << v << " ";
        cout << endl;
    }

    int source;
    cout << "\nEnter source node for BFS: ";
    cin >> source;

    BFS(source);

    return 0;
}

