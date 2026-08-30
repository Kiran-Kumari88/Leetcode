class Solution {
public:
    bool searchInRow(int start,int end,vector<vector<int>>& matrix,int row, int target){
        int n=matrix[0].size();
        start=0;
        end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(target==matrix[row][mid]){
                return true;
            }
            else if(target>matrix[row][mid]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(); // number of rows;
        int n=matrix[0].size(); // number of colums

        int startRow=0;
        int endRow=m-1;
        while(startRow<=endRow){
            int midRow=startRow+(endRow-startRow)/2;

            if(target>=matrix[midRow][0] && target<=matrix[midRow][n-1]){
                return searchInRow(0,n-1,matrix,midRow,target);
            }
            else if(target>matrix[midRow][n-1]){
                startRow=midRow+1;
            }
            else{
                endRow=midRow-1;
            }
        }
        return false;
        
    }
};