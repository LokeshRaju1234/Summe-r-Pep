class SegmentTree
{
    public:
    vector<int>tree;
    SegmentTree(int n)
    {
        tree.resize(4 * n);
    }

    void build(int index,int left,int right,vector<int>& nums)
    {
        if(left == right)
        {
            tree[index] = nums[left];
            return;
        }

        int mid = (left + right) >> 1;
        build(2 * index + 1,left,mid,nums);
        build(2 * index + 2,mid + 1,right,nums);

        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    void update(int i,int index,int left,int right)
    {
        if(left == right)
        {
            tree[index]++;
            return;
        }    

        int mid = (left + right) / 2;

        if(i <= mid)
        {
            update(i,2 * index + 1,left,mid);
        }
        else
        {
            update(i,2 * index + 2,mid + 1,right);
        }

        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    int query(int ql,int qr,int index,int left,int right)
    {
        //completed outside of this range
        if(right < ql  || left > qr)
        {
            return 0;
        }

        if(left >= ql && right <= qr)
        {
            return tree[index];
        }

        //partial overlap so search for left and right call
        int mid = (left + right) >> 1;
        return query(ql,qr,2 * index + 1,left,mid) + query(ql,qr,2 * index + 2,mid + 1,right);
    }    
};
class NumArray
{
    public:
    SegmentTree* st;
    int n;

    NumArray(vector<int>& nums)
    {
        int n = nums.size();
        this->n = n;
        st = new SegmentTree(n);
        st->build(0,0,n - 1,nums);
    }

    void update(int i,int val)
    {
        st->update(i,0,0,n - 1);
    }

    int sumRange(int l,int r)
    {
        return st->query(l,r,0,0,n - 1);
    }
};
class Solution {
public:
int binarysearch(int val,vector<int>& nums)
{
    int l = 0,h = nums.size() - 1;

    while(l <= h)
    {
        int mid = l + (h - l) / 2;

        if(val < nums[mid])
        {
            h = mid - 1;
        }
        else if(val > nums[mid])
        {
            l = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans(nums.size());
        vector<int>arr = nums;

        sort(arr.begin(),arr.end());

        arr.erase(unique(arr.begin(),arr.end()),arr.end());

        SegmentTree* st = new SegmentTree(arr.size());
        int m = arr.size();
        for(int i = nums.size() - 1;i >= 0;i--)
        {
            int sortedIndex = binarysearch(nums[i],arr);
            ans[i] = st->query(0,sortedIndex - 1,0,0,m - 1);

            st->update(sortedIndex,0,0,m - 1);
        }

        return ans;
    }
};