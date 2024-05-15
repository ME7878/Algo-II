#include<bits/stdc++.h>

using namespace std;
#define M 10

bool bfs(int adj[M][M], int s, int t, int parent[],int V)
{
    char colour[V];
    for(int v=0;v<V;v++){
        colour[v]='w';
        parent[v]=-1;
    }
    queue<int> q;
    q.push(s);
    colour[s] = 'g';
    parent[s] = -1;
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < V; v++) {
            if (colour[v] == 'w' && adj[u][v] > 0) {
                parent[v] = u;
                colour[v] = 'g';
                if (v == t) {
                    return true;
                }
                else
                    q.push(v);
            }
            colour[u]='b';
        }
    }
    return false;
}

int fordFulkerson(int adj[][M], int s, int t,int N)
{
    int u, v;
    int rGraph[M][M];
    for (int u = 0; u < N; u++)
    {
        for (int v = 0; v < N; v++)
        {
            rGraph[u][v]=adj[u][v];
        }
    }
    int max_flow = 0; 
    int parent[N];
    while (bfs(rGraph, s, t, parent,N)) {
        int min_cap = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            if(min_cap>rGraph[u][v])
            min_cap=rGraph[u][v];
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= min_cap;
            rGraph[v][u] += min_cap;
        }
        max_flow += min_cap;
    }
    return max_flow;
}

int main()
{
	int n,s,t;
  	printf("Enter The Number of Vertces In The Graph: ");
	scanf("%d",&n);
	  int adj[M][M];

  		printf("Enter The Elements of The Adjacency Matrix Using The Path Flow:\n");
			for(int i=0;i<n;i++)
 				{
 					for(int j=0;j<n;j++){
 						scanf("%d",&adj[i][j]);
					 }
				 }
    cout << "Enter The Source Vertex(0 - indexing):"<<endl;
    cin>>s;
    cout << "Enter The Sink or Destination  Vertex:"<<endl;
    cin>>t;
    cout << "The maximum possible flow is "<< fordFulkerson(adj, s, t, n);
 
    return 0;
}