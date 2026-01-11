class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            // Build histogram
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            // Largest Rectangle in Histogram
            stack<int> st;
            for (int j = 0; j <= cols; j++) {
                int currHeight = (j == cols) ? 0 : heights[j];
                while (!st.empty() && currHeight < heights[st.top()]) {
                    int h = heights[st.top()];
                    st.pop();
                    int w = st.empty() ? j : j - st.top() - 1;
                    maxArea = max(maxArea, h * w);
                }
                st.push(j);
            }
        }
        return maxArea;
    }
};