#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int storeIndex=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                storeIndex=i;
                break;
            }
        }
        if(storeIndex==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[storeIndex]){
                swap(nums[i],nums[storeIndex]);
                break;
            }
        }
        reverse(nums.begin() + storeIndex+1,nums.end());
    }
};