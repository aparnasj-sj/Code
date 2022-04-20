    class Solution {
  public:
    // Function to detect cycle in a directed graph.
    int dfs(int v,vector<int> &vis,vector<int> &st, vector<int> adj[]){
        vis[v]=1;
        st[v]=1;
        for(auto nbr:adj[v]){
            // if nbr unvis , visit it 
            if(!vis[nbr]){
                if(dfs(nbr,vis,st,adj)){return true;}
                
            }
            else if(st[nbr]){  //else check if already ancestor => true , cycle found
            
                return true;// cycle found 
            }
          
        }
        st[v]=0;//vis[v]=0; // uncomemnting this leads to TLE 
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int n=V;
        vector<int>vis(n,0);
         vector<int>stack(n,0);
         for(int i=0;i<n;i++){
             if(!vis[i]){
                 if(dfs(i,vis,stack,adj)){return true;}
             }
             
         }
        return false;
    }
};
