class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto& edge : prerequisites)
        {
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int>q;
        vector<int>ans;
       for(int i = 0;i < indegree.size();i++)
       {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
       }

       while(!q.empty())
       {
        int f = q.front();
        q.pop();
        ans.push_back(f);
        for(auto neigh : adj[f])
        {
            indegree[neigh]--;
            if(indegree[neigh] == 0)
            {
                q.push(neigh);
            }
        }

       }

       return ans.size() == numCourses;
    }
};