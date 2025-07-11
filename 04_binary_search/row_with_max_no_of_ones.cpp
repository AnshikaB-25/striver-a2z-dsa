// optimal approach : traverse each row and find the lower bound and then first 1 occurs at low after binary search...so total ones = column size - low
//TC - O(rows log columns)
int rowWithMax1s(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int ind = -1;
        int count = 0;
        for (int i = 0; i < rows; i++) {
            int low = 0;
            int high = cols - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (mat[i][mid] >= 1) {
                    high = mid - 1;
                } else
                    low = mid + 1;
            }
            int count_ones = cols - low;
            if (count_ones > count) {
                ind = i;
                count = count_ones;
            }
        }
        return ind;
    }
