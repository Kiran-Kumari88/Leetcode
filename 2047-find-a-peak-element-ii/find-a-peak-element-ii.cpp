class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int midcolumn = low + (high - low) / 2; // mid = midcolumn

            // row with max value in this column
            int maxRow = 0;
            for (int i = 0; i < m; i++)
                if (mat[i][midcolumn] > mat[maxRow][midcolumn])
                    maxRow = i;

            int left  = (midcolumn - 1 >= 0) ? mat[maxRow][midcolumn - 1] : -1;
            int right = (midcolumn + 1 < n) ? mat[maxRow][midcolumn + 1] : -1;
            int cur   = mat[maxRow][midcolumn];

            if (cur > left && cur > right)
                return {maxRow, midcolumn};
            else if (right > cur)
                low = midcolumn + 1;
            else
                high = midcolumn - 1;
        }
        return {-1, -1};
    }
};