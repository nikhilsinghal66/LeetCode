class Solution {
public:
    static bool cmp(int a,int b){
        return a>b;
    }
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long temp=0;
        vector<int> result;
        for(int i=0;i<n;i++){
            temp+=nums[i];
            result.push_back(nums[i]);
            sum-=nums[i];
            if(temp>sum){
                break;
            }
        }
        return result; 
    }
};