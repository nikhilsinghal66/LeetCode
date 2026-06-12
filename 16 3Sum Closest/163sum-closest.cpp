class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int result=-1;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1;
            int r=n-1;
            while(l<r){
                long long sum=1LL*nums[i]+nums[l]+nums[r];
                int diff=abs(sum-target);
                if(diff<ans){
                    ans=diff;
                    result=sum;
                }
                if(sum < target){
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return result;
    }
};