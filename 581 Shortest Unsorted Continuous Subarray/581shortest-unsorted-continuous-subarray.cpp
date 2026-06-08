class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans=nums;
        sort(ans.begin(),ans.end());
        int start=-1;
        int end=0;
        bool check=false;
        for(int i=0;i<n;i++){
            if(nums[i]!=ans[i]){
                if(!check){
                    start=i;
                    check=true;
                }
                else{
                    end=i;
                }
            }
        }
        return start==-1?0:end-start+1;
        // for(int i=1;i<n;i++){
        //     if(nums[i-1]<nums[i]){
        //         if(i==n-1){
        //             if(start==-1){
        //                 return 0;
        //             }
        //         }
        //     }
        //     else{
        //         if(check==false){
        //             start=i;
        //             check=true;
        //         }
        //         end=i;
        //     }
        // }
        // return start==-1?0:end-start+1;
    }
};