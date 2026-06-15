class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        for(int i=k;i<n-k;i++){
            int left = i-k;
            int right = i+k;
            long long sum;
            if(left==0)
                sum = prefix[right];
            else
                sum = prefix[right] - prefix[left-1];

            ans[i] = sum/(2*k+1);
        }
        return ans;
    }
};