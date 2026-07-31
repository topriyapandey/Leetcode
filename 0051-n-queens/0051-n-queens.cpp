class Solution {
public:
    vector<vector<string>> ans;

    void solve(int row,int n,vector<string>& board,vector<int>& col,vector<int>& d1,vector<int>& d2){

        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int j=0;j<n;j++){

            if(col[j]||d1[row+j]||d2[row-j+n-1])
                continue;

            board[row][j]='Q';
            col[j]=1;
            d1[row+j]=1;
            d2[row-j+n-1]=1;

            solve(row+1,n,board,col,d1,d2);

            board[row][j]='.';
            col[j]=0;
            d1[row+j]=0;
            d2[row-j+n-1]=0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n,string(n,'.'));

        vector<int> col(n,0);
        vector<int> d1(2*n-1,0);
        vector<int> d2(2*n-1,0);

        solve(0,n,board,col,d1,d2);

        return ans;
    }
};