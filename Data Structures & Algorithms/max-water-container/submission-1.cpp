class Solution {
public:

    int area(int i,int j,vector<int> &heights)
    {
        int h = min(heights[i], heights[j]);
        int b = j>i ? j-i : i-j;

        return b*h;
    }

    vector<int> update(int i,int j,vector<int> heights)
    {
        if(heights[i]<heights[j]) return {i+1,j};

        return {i,j-1};
    }


    int maxArea(vector<int>& heights) {
        int size = heights.size();

        int front = 0;
        int rear = size-1;

        int currentarea = area(front,rear,heights);
        int max = currentarea;

        while(front<rear)
        {
            vector<int> updatedvec = update(front,rear,heights);
            front = updatedvec[0];
            rear = updatedvec[1];

            currentarea = area(front,rear,heights);

            max = currentarea>max ? currentarea : max;

        }

        return max;

    }
};
