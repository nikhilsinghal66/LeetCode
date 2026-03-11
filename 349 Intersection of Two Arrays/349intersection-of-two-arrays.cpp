class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            set1.insert(nums1[i]);
        }
        vector<int> ans;
        for(auto x:nums2){
            if(set1.count(x)){
                ans.push_back(x);
                set1.erase(x);
            }
        }
        return ans;
    }
};