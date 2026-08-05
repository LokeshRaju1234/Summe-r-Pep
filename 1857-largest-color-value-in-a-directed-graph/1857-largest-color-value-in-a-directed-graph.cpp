class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);

        vector<vector<int>> count(n,vector<int>(26,0));
        vector<int>indegree(n);
        for(int i = 0;i < edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
        }

        queue<int>q;
        for(int i = 0;i < indegree.size();i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int process = 0;
        int maxi = 0;
        while(!q.empty())
        {

            int curr = q.front();
            q.pop();
            process++;
            count[curr][colors[curr] - 'a']++;
            maxi = max(maxi,count[curr][colors[curr] - 'a']);
            for(auto &next : adj[curr])
            {
                indegree[next]--;
                if(indegree[next] == 0)
                {
                    q.push(next);
                }

                for(int i = 0;i < 26;i++)
                {
                    count[next][i] = max(count[next][i],count[curr][i]);
                }
            }
        }

        return (process == n) ? maxi : -1;
    }
};