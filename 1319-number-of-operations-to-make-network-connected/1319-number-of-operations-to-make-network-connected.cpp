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

    bool unite(int x,int y)
    {
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y)
        {
            return true;
        }

        if(size[parent_x] < size[parent_y])
        {
            swap(parent_x,parent_y);
        }

        parent[parent_y] = parent_x;
        size[parent_x] += size[parent_y];

        return false;        
    }

    int fin()
    {
        int cables = 0;

        for(int i = 0;i < parent.size();i++)
        {
            if(parent[i] == i)
            {
                cables++;
            }
        }

        return cables;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        //if there is no sufficient cables to connect number of computers
        if(connections.size() < n - 1)
        {
            return -1;
        }
        DSU dsu(n);
        for(auto& edge : connections)
        {
            dsu.unite(edge[0],edge[1]);
        }

        return dsu.fin() - 1;
    }
};