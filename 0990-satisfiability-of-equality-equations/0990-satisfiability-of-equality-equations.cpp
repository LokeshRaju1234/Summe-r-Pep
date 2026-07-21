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

        //path compression
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

    // bool check(int a,int b)
    // {
    //     for(auto& s : equations)
    //     {
    //         int c = s[0] - 'a';
    //         int d = s[3] - 'a';

    //         if(find())
    //     }
    // }
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {

        DSU dsu(26);
        for(auto& s : equations)
        {
            int a = s[0] - 'a';
            int b  = s[3] - 'a';
            if(s[1] == '=')
            {
                dsu.unite(a,b);
            }
        }

        for(auto& s : equations)
        {
            int a = s[0] - 'a';
            int b  = s[3] - 'a';
            //if they are in same component then it never satisfies the condition
            if(s[1] != '=' && dsu.find(a) == dsu.find(b))
            {
                return false;
            }
        }

        return true;
    }
};