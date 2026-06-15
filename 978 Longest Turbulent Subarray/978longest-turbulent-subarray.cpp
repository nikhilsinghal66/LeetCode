class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        int curr=1;
        int ans=1;
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                if(i==1 || arr[i-2]>arr[i-1]){
                    curr++;
                }
                else{
                    curr=2;
                }
            }
            else if(arr[i-1]>arr[i]){
                if(i==1 || arr[i-2]<arr[i-1]){
                    curr++;
                }
                else{
                    curr=2;
                }
            }
            else{
                curr=1;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};