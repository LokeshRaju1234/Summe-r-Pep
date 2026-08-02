class Solution {
public:
    int solve(vector<int>& A,int i,int j)
    {
        if(i == j)
        {
            return A[i]; 
        }

        int left = A[i] - solve(A,i + 1,j);
        int right = A[j] - solve(A,i,j - 1);

        return max(left,right); 
    }
    bool predictTheWinner(vector<int>& A) {
        int n = A.size() - 1;
        return solve(A,0,n) >= 0;
    }
};