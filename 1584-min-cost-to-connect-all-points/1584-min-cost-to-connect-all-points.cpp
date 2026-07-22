class DSU
{
    public:
    vector<int>parent,rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(),parent.end(),0);
    }

    int find(int x)
    {
        if(parent[x] == x)
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int x,int y)
    {
        int p_x = find(x);
        int p_y = find(y);

        if(p_x == p_y)
        {
            return;
        }

        if(rank[p_x] < rank[p_y])
        {
            parent[p_x] = p_y;
        }
        else if(rank[p_x] > rank[p_y])
        {
            parent[p_y] = p_x;
        }
        else
        {
            parent[p_y] = p_x;
            rank[p_x]++;
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        int n = points.size();
        for(int i = 0;i < n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                pq.push({wt,i,j});
            }
        }

        DSU dsu(n + 1);

        int ans = 0;
        while(!pq.empty())
        {
            auto [wt,u,v] = pq.top();
            pq.pop();

            if(dsu.find(u) == dsu.find(v)) continue;
            else
            {
                ans += wt;
                dsu.unite(u,v);
            }
        }

        return ans;
    }
};