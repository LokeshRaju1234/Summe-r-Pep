class SegmentTree
{
    public:
    vector<int> Seg;

    SegmentTree(int n)
    {
        Seg.resize(4 * n);
    }

    void build(int index,int left,int right,vector<int>& nums)
    {
        if(left == right)
        {
            Seg[index] = nums[left];
            return;
        }


        int mid = (left + right) >> 1;
        build(2 * index + 1,left,mid,nums);
        build(2 * index + 2,mid + 1,right,nums);

        Seg[index] = max(Seg[2 * index + 1],Seg[2 * index + 2]);
    }

    void update(int i,int index,int left,int right)
    {
        //mark as the bucket is used
        if(left == right)
        {
            Seg[index] = -1;
            return;
        }

        int mid =  (left + right) >> 1;
        //if the position to update is  in left half then recurse to left to find that index
        if(i <= mid)
        {
            update(i,2 * index + 1,left,mid);
        }
        //else recurse right to find tat index
        else
        {
            update(i,2 * index + 2,mid + 1,right);
        }
        //finally update the value at that index and update the segment ytree
        Seg[index] = max(Seg[2 * index + 1],Seg[2 * index + 2]);
    }

    int query(int index,int left,int right,int fruit)
    {
        //if the root itself is less than the fruit, we cant find the basket greater than fruit in whole range
        if(Seg[index] < fruit)
        {
            return -1;
        }

        if(left == right)
        {
            return left;
        }

        int mid = (left + right) >> 1;

        if(Seg[2 * index + 1] >= fruit)
        {
            return query(2 * index + 1,left,mid,fruit);
        }
        
        return query(2 * index + 2,mid + 1,right,fruit);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
         int n = baskets.size();
       SegmentTree sg(n);

       sg.build(0,0,n - 1,baskets);

       int unplaced = 0;

       for(int i = 0;i < n;i++)
       {
        //if the fruit cant placed then query returns -1 so it will remain unplaced
        int idx = sg.query(0,0,n - 1,fruits[i]);

        if(idx == -1)
        {
            unplaced++;
        }
        else
        {
            sg.update(idx,0,0,n - 1);
        }
        
       }

       return unplaced;
    }
};