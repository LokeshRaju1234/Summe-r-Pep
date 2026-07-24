class Solution {
public:
    int arr[4][4] = {{ 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }};
    void dfs(int i,int j,vector<vector<char>>& board)
    {
        board[i][j] = 'R';
        for(int x = 0;x < 4;x++)
        {
            int nr = i + arr[x][0];
            int nc = j + arr[x][1];

            if(nr >= 0 && nc < board[0].size() && nr < board.size() && board[nr][nc] == 'X')
            {
                dfs(nr,nc,board);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) 
    {
        if(board.size() == 0 || board[0].size() == 0) return 0;
        int count = 0;

        for(int i = 0;i < board.size();i++)
        {
            for(int j = 0;j < board[0].size();j++)
            {
                if(board[i][j] == 'X')
                {
                    //counts the numbser of battle ships
                    count++;
                    dfs(i,j,board);
                }
            }
        }

        return count;
    }
};