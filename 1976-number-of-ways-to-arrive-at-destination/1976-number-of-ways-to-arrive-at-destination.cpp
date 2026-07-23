class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<vector<pair<int,int>>>adj(n);
       vector<int> path(n,0);
       vector<long long>dist(n,LLONG_MAX);

       const int MOD = 1e9 + 7;

       for(int i = 0;i < roads.size();i++)
       {
        int u = roads[i][0];
        int v = roads[i][1];
        int wt = roads[i][2];
        
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
       }

       priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> pq;

       pq.push({0,0});
       dist[0] = 0;
       path[0] = 1;


       while(!pq.empty())
       {
        auto [d,no] = pq.top();
        pq.pop();

        if(d > dist[no]) continue;

        for(auto &neigh : adj[no])
        {
            int node = neigh.first;
            int wei = neigh.second;

            if(d + wei < dist[node])
            {
                dist[node] = d + wei;
                path[node] = path[no];
                pq.push({dist[node],node});
            }
            else if(d + wei == dist[node])
            {
                path[node] = (path[no] + path[node]) % MOD;
            }
        }
       }

       return path[n - 1];
    }
};