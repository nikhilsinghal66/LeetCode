/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int lower_bound1(int start,int end,MountainArray &mountainArr,int target){
        int low=start;
        int high=end;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            if(mountainArr.get(mid)<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }

    int lower_bound2(int start,int end,MountainArray &mountainArr,int target){
        int low=start;
        int high=end;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            if(mountainArr.get(mid)>target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        int peak=low;
        int lower1=lower_bound1(0,peak,mountainArr,target);
        int upper1=lower_bound2(peak+1,n-1,mountainArr,target);
        if(lower1!=-1) return lower1;
        return upper1;
    }
};