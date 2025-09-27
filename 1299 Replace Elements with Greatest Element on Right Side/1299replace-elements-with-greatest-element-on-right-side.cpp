class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxelm=-1;
        int n=arr.size();
        vector<int> vec(n);
        for(int i=n-1;i>=0;i--){
            vec[i]=maxelm;
            if(arr[i]>maxelm){
                maxelm=arr[i];
            }
        }
        return vec;
    }
};