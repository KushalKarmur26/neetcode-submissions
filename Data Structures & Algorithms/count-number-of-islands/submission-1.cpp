class Solution {

    vector<int> dx;
    vector<int> dy;

    void dfs(int i,int j,int rows,int columns,vector<vector<char>> &grid)
    {
        if(i<0 || j<0 || i>=rows|| j>=columns) return; //index out of bounds;

        if(grid[i][j]=='0' || grid[i][j]=='#') return;

        grid[i][j] = '#';
        
        for(int k=0;k<4;k++)
            dfs(i + dx[k],j + dy[k],rows,columns,grid);

    }

public:


    Solution()
    {
        dx = {-1,1,0,0};
        dy = {0,0,-1,1};
    }

    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int columns = grid[0].size();

        int count = 0;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(grid[i][j]!='0' && grid[i][j]!='#')
                {
                    count++;
                    dfs(i,j,rows,columns,grid);
                }
            }
        }
        
        return count;
    }
};
