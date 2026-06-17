class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=1;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if( mid-1 >=0 && arr[mid]>arr[mid-1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};