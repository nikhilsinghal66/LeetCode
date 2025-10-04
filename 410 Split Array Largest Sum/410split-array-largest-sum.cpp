class Solution {
public:

    int sum1(vector<int> vec){
        int result=0;
        for(auto it:vec){
            result+=it;
        }
        return result;
    }

    int find_std(vector<int> nums, int mid, int k){
        int student=1;
        int student_sum=0;
        for(int i=0;i<nums.size();i++){
            if(student_sum+nums[i]<=mid){
                student_sum+=nums[i];
            }
            else{
                student++;
                student_sum=nums[i];
            }
        }
        return student;
    }





    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=sum1(nums);
        while(low<=high){
            int mid=low+(high-low)/2;
            int student=find_std(nums,mid,k);
            if(student>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low; 
    }
};