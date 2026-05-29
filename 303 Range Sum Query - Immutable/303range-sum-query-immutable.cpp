class NumArray {
public:
    vector<int> num;
    vector<int> prefix_sum;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        num.resize(n);
        prefix_sum.resize(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            num[i]=nums[i];
            prefix_sum[i]=sum;
        }
    }
    int sumRange(int left, int right) {
        int ans=prefix_sum[right]-prefix_sum[left]+num[left];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */