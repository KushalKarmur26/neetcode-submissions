class Solution {

    int converter(int i,int j,int rows,int columns)
    {
        return (i*columns + j);
    }

    bool checkneighbours(int i,int j,int rows,int columns,int letter,string &word,vector<vector<char>> &board,unordered_map<int,bool> &used)
    {
        bool ans = false;

        //word complete
        if(letter==word.size()) return true;
        
        //check top
        if(i>0 && !used[converter(i-1,j,rows,columns)] && board[i-1][j]==word[letter])
        {
            used[converter(i-1,j,rows,columns)] = true;
            ans = checkneighbours(i-1,j,rows,columns,letter+1,word,board,used);

            if(ans) return ans;
            used[converter(i-1,j,rows,columns)] = false;
        }

        //check bottom
        if(i<rows-1 && !used[converter(i+1,j,rows,columns)] && board[i+1][j]==word[letter])
        {
            used[converter(i+1,j,rows,columns)] = true;
            ans = checkneighbours(i+1,j,rows,columns,letter+1,word,board,used);

            if(ans) return ans;
            used[converter(i+1,j,rows,columns)] = false;
        }

        //check left
        if(j>0 && !used[converter(i,j-1,rows,columns)] && board[i][j-1]==word[letter])
        {
            used[converter(i,j-1,rows,columns)] = true;
            ans = checkneighbours(i,j-1,rows,columns,letter+1,word,board,used);

            if(ans) return ans;
            used[converter(i,j-1,rows,columns)] = false;
        }

        //check right
        if(j<columns-1 && !used[converter(i,j+1,rows,columns)] && board[i][j+1]==word[letter])
        {
            used[converter(i,j+1,rows,columns)] = true;
            ans = checkneighbours(i,j+1,rows,columns,letter+1,word,board,used);

            if(ans) return ans;
            used[converter(i,j+1,rows,columns)] = false;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        
        bool ans = false;
        
        int rows = board.size();
        int columns = board[0].size();

        unordered_map<int,bool> used;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(board[i][j]==word[0])
                {
                    used[converter(i,j,rows,columns)] = true;
                    ans = checkneighbours(i,j,rows,columns,1,word,board,used);
                }

                if(ans) return ans;
                used[converter(i,j,rows,columns)] = false;
            }
        }

        return ans; 
    }
};
