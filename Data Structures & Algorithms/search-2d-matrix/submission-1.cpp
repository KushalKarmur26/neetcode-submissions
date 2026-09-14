class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int columns = matrix[0].size();


        int low = 0;
        int high = rows-1;

        //finding rowindex
        int ourrowindex = rows;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            int check = matrix[mid][0];

            if(check==target) return true;

            if(target<check)
            {
                ourrowindex = mid;
                high = mid - 1;
            }

            else if(target>check) low = mid + 1;
        }

        ourrowindex--;

        if(ourrowindex<0) return false;


        low = 0;
        high = columns - 1;

        //find columnindex
        int ourcolumnindex = columns;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            int check = matrix[ourrowindex][mid];

            if(target==check)
            {
                ourcolumnindex = mid;
                return true;
            }

            if(target<check) high = mid - 1;
            else low = mid + 1;
        }

        return false;
        
    }
};
