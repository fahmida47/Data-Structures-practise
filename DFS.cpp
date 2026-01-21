#include<bits/stdc++.h>
using namespace std;
void DFS(int u,vector<vector<int>>&adj,vector<int>&color)
{
  color[u]=1;  //1 for gray
  cout<<"Visit: "<<u<<endl;
  for(int v: adj[u]){
    if(color[v]==0){
      DFS(v,adj,color);
    }
  }
  color[u]=2;  // 2 for black
  cout<<"Finish: "<<u<<endl;
}
int main()
{
  int node,edge;
  cout<<"Enter the node:"<<endl;
  cin>>node;
  cout<<"Enter the edges:"<<endl;
  cin>>edge;
  vector<vector<int>>adj(node);
  for(int i=0;i<edge;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
  }
  vector<int>color(node,0);//0 for white
  for(int i=0;i<node;i++){
    if(color[i]==0){
      DFS(i,adj,color);
    }
  }
  return 0;
}

//---------------------------------------Cycle detect----------------------------//
#include<bits/stdc++.h>
using namespace std;

bool cycle = false;

void DFS(int u, vector<vector<int>>& adj, vector<int>& color)
{
    color[u] = 1;  // gray (processing)
    cout << "Visit: " << u << endl;

    for (int v : adj[u]) {
        if (color[v] == 0) {
            DFS(v, adj, color);
        }
        else if (color[v] == 1) {
            // back edge found
            cycle = true;
        }
    }

    color[u] = 2;  // black (finished)
    cout << "Finish: " << u << endl;
}

int main()
{
    int node, edge;
    cout << "Enter the node:\n";
    cin >> node;

    cout << "Enter the edges:\n";
    cin >> edge;

    vector<vector<int>> adj(node);

    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> color(node, 0); // 0 = white

    for (int i = 0; i < node; i++) {
        if (color[i] == 0)
            DFS(i, adj, color);
    }

    if (cycle)
        cout << "\nCycle detected → Impossible to complete the course\n";
    else
        cout << "\nNo cycle → Possible to complete the course\n";

    return 0;
}



