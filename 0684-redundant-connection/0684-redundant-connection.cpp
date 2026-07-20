class DSU
{
    public:
    vector<int>parent,size;
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

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

        //finds the ultimate parent of x
        return parent[x] = find(parent[x]);
    }

    bool unite(int a,int b)
    {
        int find_x = find(a);
        int find_y = find(b);

        if(find_x == find_y)
        {
            return true;
        }

        if(size[find_x] < size[find_y])
        {
            swap(find_x,find_y);
        }

        //update the parent and size
        parent[find_y] = find_x;
        //increase the rank for the parent
        size[find_x] += size[find_y];

        return false;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n + 1);

        for(auto& e : edges)
        {
            if(dsu.unite(e[0],e[1]))
            {
                return {e[0],e[1]};
            }
        }

        return {};
    }
};