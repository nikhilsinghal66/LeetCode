class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> prefix(n,0);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]^arr[i];
        }
        int m=queries.size();
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            ans[i]=prefix[queries[i][1]]^prefix[queries[i][0]]^arr[queries[i][0]];
        }
        return ans;
    }
};