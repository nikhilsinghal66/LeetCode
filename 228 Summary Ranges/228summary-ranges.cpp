class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        if(nums.size()==0) return vec;
        if(nums.size()==1) {
            vec.push_back(to_string(nums[0]));
            return vec;
        }
        if(nums[1]!=nums[0]+1){
            vec.push_back(to_string(nums[0]));

        }
        int start=-1;
        if(nums[0]+1==nums[1]){
                start=nums[0];
            }
        if(nums.size()==2){
            if(nums[1]==nums[0]+1){
                vec.push_back(to_string(start)+"->"+to_string(nums[1]));
            }
            else{
                vec.push_back(to_string(nums[1]));
            }
        }
        if(nums.size()>=3){
            for(int i=1;i<nums.size()-2;i++){

            if((nums[i-1]+1)!=nums[i] && (nums[i]+1)!=nums[i+1]){

                vec.push_back(to_string(nums[i]));
                start=nums[i+1];
            }
            else if((nums[i-1]+1)==nums[i] && (nums[i]+1)!=nums[i+1]){
                vec.push_back(to_string(start)+"->"+to_string(nums[i]));
                start=nums[i+1];
            }
            // else if((nums[i]+1)==(nums[i+1]) && (start!=-1) && nums[i-1]+1==nums[i]){
            //     continue;
            // }
            else if ((nums[i-1]+1)!=nums[i] && (nums[i]+1)==nums[i+1]){
                start=nums[i];
            }
            else if((nums[i]+1)==(nums[i+1]) && (start!=-1) && nums[i-1]+1==nums[i]){
                continue;
            }
        }
        if(nums[nums.size()-2]+1==nums[nums.size()-1]){
            if(start!=-1){
                vec.push_back(to_string(start)+"->"+to_string(nums[nums.size()-1]));

            }
            else{
                vec.push_back(to_string(nums[nums.size()-2])+"->"+to_string(nums[nums.size()-1]));

            }
            // vec.push_back(to_string(nums[nums.size()-2])+"->"+to_string(nums[nums.size()-1]));

            // vec.push_back(to_string(start)+"->"+to_string(nums[nums.size()-1]));
        }
        else if(nums[nums.size()-2]+1!=nums[nums.size()-1]){
            if(nums[nums.size()-3]+1!=nums[nums.size()-2]){
                vec.push_back(to_string(nums[nums.size()-2]));
                vec.push_back(to_string(nums[nums.size()-1]));
            }
            else{
                vec.push_back(to_string(start)+"->"+to_string(nums[nums.size()-2]));
                vec.push_back(to_string(nums[nums.size()-1]));

            }
            // vec.push_back(to_string(start)+"->"+to_string(nums[nums.size()-2]));
            // vec.push_back(to_string(nums[nums.size()-1]));

            }
        }
        return vec; 
    }
};