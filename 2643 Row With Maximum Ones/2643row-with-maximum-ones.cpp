class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int max_count = 0;
        int result = 0;

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) count++;
            }

            if(count > max_count) {
                max_count = count;
                result = i;
            }
        }

        return {result, max_count};
    }
};