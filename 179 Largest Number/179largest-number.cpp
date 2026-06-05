class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),[](int &a , int &b){
            string ab=to_string(a)+to_string(b);
            string ba=to_string(b)+to_string(a);
            return ab > ba;
        });
        string ans="";
        for(auto it:nums){
            ans+=to_string(it);
        }
        if(ans[0]=='0'){
            return "0";
        }
        return ans;
    }
};