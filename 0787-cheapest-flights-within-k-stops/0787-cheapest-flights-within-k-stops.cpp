class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n,INT_MAX);

        for(int i = 0;i < flights.size();i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v,wt});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        dist[src] = 0;
        while(!q.empty())
        {
            pair<int,pair<int,int>> it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int wei = it.second.second;

            if(stops > k) continue;

            for(auto &neigh : adj[node])
            {
                int node = neigh.first;
                int wt = neigh.second;

                if(wei + wt < dist[node])
                {
                    dist[node] = wei + wt;
                    q.push({stops + 1,{node,dist[node]}});
                }
            }
        }

        if(dist[dst] == INT_MAX)
        {
            return -1;
        }

        return dist[dst];
    }
};