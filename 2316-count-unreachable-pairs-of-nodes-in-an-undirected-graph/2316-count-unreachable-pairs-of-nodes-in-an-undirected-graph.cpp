class DSU
{
    public:
    vector<int>parent,size;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n,1);

        iota(parent.begin(),parent.end(),0);
    }

    int find(int x)
    {
        if(parent[x] == x)
        {
            return x;
        }

        //finds the ultimate parent of x
        return parent[x] = find(parent[x]);
    }

    void unite(int a,int b)
    {
        int find_x = find(a);
        int find_y = find(b);

        if(find_x == find_y)
        {
            return;
        }

        if(size[find_x] < size[find_y])
        {
            swap(find_x,find_y);
        }

        //update the parent and size
        parent[find_y] = find_x;
        //increase the rank for the parent
        size[find_x] += size[find_y];
    }

    long long f(int n)
    {
        long long ans = 0;
        int remaining = n;

        for(int i = 0;i < size.size();i++)
        {
            if(find(i) == i)
            {
                long long sz = size[i];
                ans += sz * (remaining - sz);
                remaining -= sz;
            }
        }

        return ans;
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto& e : edges)
        {
            dsu.unite(e[0],e[1]);
        }

        return dsu.f(n);
    }
};