class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax=-1;
        int rightmax=-1;
        int n=height.size();
        int low=0;
        int high=n-1;
        int ans=0;
        while(low<high){
            if(height[low]<height[high]){
                if(leftmax>height[low]){
                    ans+=leftmax-height[low];
                }
                else{
                    leftmax=height[low];
                }
                low++;
            }
            else{
                if(rightmax>height[high]){
                    ans+=rightmax-height[high];
                }
                else{
                    rightmax=height[high];
                }
                high--;
            }
        }
        return ans;
    }
};