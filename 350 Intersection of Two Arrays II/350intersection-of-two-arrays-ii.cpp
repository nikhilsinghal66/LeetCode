class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        vector<int> vec;
        for(int i=0;i<nums1.size();i++){
            mpp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(mpp.find(nums2[i])!=mpp.end()){
                vec.push_back(nums2[i]);
                mpp[nums2[i]]--;
                if(mpp[nums2[i]]==0){
                    mpp.erase(nums2[i]);
                }
            }

        }
        return vec;
        
    }
};