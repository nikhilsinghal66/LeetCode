class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long a=1;
        ans.push_back(a);
        for(int i=1;i<=rowIndex;i++){
            a=a*(rowIndex-i+1);
            a=a/i;
            ans.push_back(a);
        }
        return ans; 
    }
};