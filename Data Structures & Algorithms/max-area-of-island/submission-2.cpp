class Solution {

	vector<int> dr = {-1,1,0,0};
	vector<int> dc = {0,0,-1,1};
	
	void dfs(int i,int j,int rows,int columns, vector<vector<int>> &grid, int* currentsize)
	{
		if(i<0 || j<0 || i>=rows || j>=columns) return; //out of bounds
		
		if(grid[i][j] == 0 || grid[i][j] == -1) return; //visited or water
		
		grid[i][j] = -1;
		*currentsize = *currentsize + 1;
		
		for(int k=0;k<4;k++)
			dfs(i + dr[k], j + dc[k], rows, columns, grid, currentsize);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    
    	int rows = grid.size();
    	int columns = grid[0].size();
    	
    	int maxsize = 0;
    	
    	for(int i=0;i<rows;i++)
    	{
    		for(int j=0;j<columns;j++)
    		{
    			if(grid[i][j] == 1)
    			{
    				int currentsize = 0;
    				dfs(i,j,rows,columns,grid,&currentsize);

                    if(currentsize > maxsize) maxsize = currentsize;
    			}
    		}
    	}
    	
    	
    	return maxsize;
        
    }
};