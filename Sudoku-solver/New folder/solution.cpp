class Solution {
public:

    bool isvalid(vector<vector<char>>& board,int row,int col, char c)
    {
        // checking row
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c) return false;
        }

        //checking col
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==c) return false;
        }

        // checking inner grid
        for(int i=0;i<9;i++)
        {
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board , int row )
    {
        if(row>=9) return true;

        for(int col=0; col<9; col++)
        {
            if(board[row][col]=='.')
            {
                for(char c='1';c<='9';c++)
                {
                    if(isvalid(board,row,col,c))
                    {
                        board[row][col]=c; // place digit

                        bool solved;

                        if(col==8) solved = solve(board,row+1);
                        else solved = solve(board,row);

                        if(solved) return true;

                        //backtrack
                        board[row][col]='.';
                        
                    }
                }
                return false;
            }
        }
        // if current row has every element filled
        return solve (board,row+1);
    }
    void solveSudoku(vector<vector<char>>& board) {

        solve(board,0);    
    }
};