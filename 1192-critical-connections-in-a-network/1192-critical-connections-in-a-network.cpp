class Solution {
public:
vector<vector<int>>ans;
    void dfs(auto& adj,auto& time,int parent,int curr,int &gt)
    {
        time[curr] = gt++;
        int cnt = 0;
        int temp = time[curr];
        for(auto neigh : adj[curr])
        {
            if(neigh == parent && cnt == 0) 
            {cnt++;continue;}

            if(time[neigh] == -1)
            {
                dfs(adj,time,curr,neigh,gt);

                time[curr] = min(time[curr],time[neigh]);

                if(time[neigh] > temp) ans.push_back({curr,neigh});
            }

           else  time[curr] = min(time[curr], time[neigh]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        ans = {};
        vector<vector<int>> adj(n);

        for(int i = 0;i < c.size();i++)
        {
            int u = c[i][0];
            int v = c[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int gt = 0;
        vector<int> time(n,-1);

        for(int i = 0;i < n;i++)
        {
            if(time[i] == -1) dfs(adj,time,-1,i,gt);
        }

        return ans;

    }
};