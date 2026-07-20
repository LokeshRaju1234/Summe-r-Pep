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

    int s()
    {
        int count = 0;
        for(int i = 0;i < parent.size();i++)
        {
            //every province has only root if its parent is equal to the parent
            if(find(i) == i)
            {
                count++;
            }
        }

        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n + 1);

       for(int i = 0;i < isConnected.size();i++)
       {
        for(int j = 0;j < isConnected.size();j++)
        {
            if(isConnected[i][j] == 1)
            {
                dsu.unite(i,j);
            }
        }

       }


       return dsu.s() - 1;
    }
};