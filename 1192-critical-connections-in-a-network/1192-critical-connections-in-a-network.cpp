class Solution {
public:
    vector<vector<int>> ans;
    void dfs(auto &adj,auto &time,int parent,int curr,int &t)
    {
        time[curr] = t++;
        int temp = time[curr];

        for(auto &neigh : adj[curr])
        {
            //because it came from the parent only
            if(parent == neigh) continue;
            if(time[neigh] == -1)
            {
                dfs(adj,time,curr,neigh,t);

                time[curr] = min(time[curr],time[neigh]);

                if(time[neigh] > temp)
                {
                    ans.push_back({curr,neigh});
                }
            }
            //it has a back edge and it reaches to the anchester even when you remove this edge
            else time[curr] = min(time[curr],time[neigh]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        ans = {};
       vector<vector<int>> adj(n);

       for(auto &edge : c)
       {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
       }

       vector<int> time(n,-1);
       int t = 0;
       for(int i = 0;i < n;i++)
       {
        if(time[i] == -1) dfs(adj,time,-1,i,t);
       }

       return ans;
    }
};