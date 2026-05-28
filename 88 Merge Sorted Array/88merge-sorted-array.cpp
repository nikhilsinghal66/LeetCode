class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums11=nums1;
        int l=0;
        int r=0;
        int k=0;
        while(l<m && r<n){
            if(nums11[l]<nums2[r]){
                nums1[k]=nums11[l];
                l++;
                k++;
            }
            else{
                nums1[k]=nums2[r];
                r++,k++;
            }
        }
        while(l<m){
            nums1[k]=nums11[l];
            l++;
            k++;
        }
        while(r<n){
            nums1[k]=nums2[r];
            r++;
            k++;
        }
    }
};