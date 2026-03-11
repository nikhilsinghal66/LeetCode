class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre_index(n);
        vector<int> suffix_index(n);
        pre_index[0]=nums[0];
        for(int i=1;i<n;i++){
            pre_index[i]=nums[i]+pre_index[i-1];
        }
        suffix_index[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix_index[i]=nums[i]+suffix_index[i+1];
        }
        for(int i=0;i<n;i++){
            int left= (i==0)? 0:pre_index[i-1];
            int right=(i==n-1)?0:suffix_index[i+1];
            if(left==right){
                return i;
            }
        }
        return -1; 
    }
};