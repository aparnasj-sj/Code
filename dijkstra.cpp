vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)

    {

        // Code here

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> >> pq;

        vector<int> dist(V, INT_MAX);

        dist[s]=0;

        pq.push(make_pair(0, s));

        

        while(!pq.empty())

        {

            

            int node= pq.top().second;

            pq.pop();

            for(auto it: adj[node])

            {

                int n= it[0];

                int d= it[1];

                

                if(dist[n]> dist[node]+d)

                {

                    dist[n]= dist[node]+ d;

                    pq.push(make_pair(dist[n], n));

                }

            }

        }

        return dist;

    }




