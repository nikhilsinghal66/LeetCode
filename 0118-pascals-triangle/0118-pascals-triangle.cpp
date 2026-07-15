class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            long long value=1;
            for(int j=0;j<=i;j++){
                temp.push_back(value);
                value=(value*(i-j))/(j+1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};