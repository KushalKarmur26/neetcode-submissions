class Solution {

    int indexconverter(vector<vector<int>> &matrix, int ourindex)
    {
        int rows = matrix.size();
        int columns = matrix[0].size();

        int i = ourindex / columns;
        int j = ourindex % columns;

        return matrix[i][j];
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int columns = rows ? matrix[0].size() : 0;
        
        int low = 0;
        int high = rows * columns - 1;

        if(rows==0) return false;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            int check = indexconverter(matrix, mid);

            if(target==check) return true;
            
            if(target<check) high = mid - 1;
            
            else low = mid + 1;

        }

        return false;
        
    }
};
