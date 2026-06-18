class Solution {
public:
    bool f(int balls,vector<int>& nums, int mxOpn ){
        long long count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>balls){
                count+=(nums[i]-1)/balls;
            }
        }
        return count<=mxOpn;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            bool check=f(mid,nums,maxOperations);
            if(check==true){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};