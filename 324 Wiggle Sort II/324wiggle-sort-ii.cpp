class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans=nums;
        sort(ans.begin(),ans.end());
        int left=(n-1)/2;
        int right=(n-1);
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=ans[left--];
            }
            else{
                nums[i]=ans[right--];
            }
        }     
    }
};