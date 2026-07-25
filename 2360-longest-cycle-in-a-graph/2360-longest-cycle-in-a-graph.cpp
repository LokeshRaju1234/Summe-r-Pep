class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj, vector<bool> &vis,vector<int> &dist,vector<bool> &path,int &mx,int time)
    {
        vis[node] = true;
        path[node] = true;
        dist[node] = time;
        for(auto& neigh : adj[node])
        {
            if(!vis[neigh])
            {
                dfs(neigh,adj,vis,dist,path,mx,time + 1);
            }
            else if(path[neigh])
            {
                mx = max(mx,time - dist[neigh] + 1);
            }
        }

        path[node] = false;
    }
    int longestCycle(vector<int>& edges) {
        vector<vector<int>> adj(edges.size());

        for(int i = 0;i < edges.size();i++)
        {
            if(edges[i] != -1)
            {
            adj[i].push_back(edges[i]);
            }
        }
    

        vector<bool>vis(edges.size(),false);
        vector<int> dist(edges.size());

        vector<bool>path(edges.size(),false);
        int mxlen = 0;
        for(int i = 0;i < edges.size();i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,dist,path,mxlen,1);
            }
        }

        return (mxlen == 0) ? -1 : mxlen;
    }
};