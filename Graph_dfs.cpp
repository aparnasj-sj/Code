// adjacency list

void dfs_helper(vector<int> adj[], vector<int> &ans, map<int, bool> &visited,

                                                           int src, int parent)

{

        visited[src] = 1;

        ans.push_back(src);

        for (int i : adj[src]) 

        {

            if (!visited[i])

            {

                dfs_helper(adj, ans, visited, i, src);

            }

        }

    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])

    {

        // Code here

        map<int, bool>visited;

        vector<int>ans;

        for (int i = 0; i < V; i++) {

        if (visited[i] == 0)

        dfs_helper(adj, ans, visited, i, -1);

        }

        return ans;

    }
