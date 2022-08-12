#include <bits/stdc++.h>
using namespace std;
class DSU
{
    int* parent;
    int* rank;
public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for(int i = 0; i<n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);  
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph {
    vector<vector<int> > edgelist;
    int V;
  
public:
    Graph(int V) { this->V = V; }
  
    void addEdge(int x, int y, int w)
    {
        vector<int> a;
        a.push_back(w);
        a.push_back(x);
        a.push_back(y);
        edgelist.push_back(a);
    }
  
    void kruskals_mst()
    {
        sort(edgelist.begin(), edgelist.end());
        DSU s(V);
        int ans = 0;
        int n = edgelist.size();
        cout << "Following are the edges in the constructed MST" << endl;
        for (int i = 0; i<n; i++) {
            vector<int> edge = edgelist[i];
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(1,2,1);
    g.addEdge(1,3,7);
    g.addEdge(2,3,3);
    g.addEdge(1,5,5);
    g.addEdge(1,4,10);
    g.addEdge(3,4,4);
    g.addEdge(4,5,2);
  
    // int n, m;
    // cin >> n >> m;
  
    // Graph g(n);
    // for (int i = 0; i < m; i++)
    // {
    //     int x, y, w;
    //     cin >> x >> y >> w;
    //     g.addEdge(x, y, w);
    // }
  
    g.kruskals_mst();
    return 0;
}
