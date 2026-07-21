class DSU
{
    public:
    vector<int>parent,size;
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0;i < n;i++)
        {
            parent[i] = i;
        }
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

        if(size[p_x] < size[p_y])
        {
            swap(p_x,p_y);
        }

        parent[p_y] = p_x;
        size[p_x] += size[p_y];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mx_r = 0;
        int mx_c = 0;
        for(auto& r : stones)
        {
            mx_r = max(mx_r,r[0]);
            mx_c = max(mx_c,r[1]);
        }

        DSU dsu(mx_r + mx_c + 2);
        unordered_set<int> set;
        for(int i = 0;i < stones.size();i++)
        {
            int r = stones[i][0];
            int c = stones[i][1] + mx_r + 1;

            dsu.unite(r,c);
            set.insert(r);
            set.insert(c);
        }

        int components = 0;

        for(auto& i : set)
        {
            if(dsu.find(i) == i)
            {
                components++;
            }
        }

        return stones.size() - components;
    }
};