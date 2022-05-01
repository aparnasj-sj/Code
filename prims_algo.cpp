//MINIMUM SPANNING TREE
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	#define vi  vector<int>
	#define pii pair<int,int>
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // paritally formed tree 
        // add min wt edge tat can be conneceted such tat no cycle 
        vi dist(V,INT_MAX); vi vis(V,0);
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            // attach min wt edge 
            pii p=pq.top();
            pq.pop();
            int node=p.second;
            vis[node]=1;
            for(auto e:adj[node]){
                // iterate nbrs of node 
                // e:vector<int>
                // v[0]=nbr, v[1]: wt
                int nbr=e[0];int weight=e[1];
                if(!vis[nbr] && dist[nbr]>weight){
                    // not vis ensure cycle prevention
                    // then u can prefer this new edge in future to connect nbr to T
                    dist[nbr]=weight;
                    pq.push({weight,nbr});
                }
                
            }
            
            // relax nbrs
            
        }
        int ans=0;
        for(auto i:dist){
            ans+=i;
            
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
