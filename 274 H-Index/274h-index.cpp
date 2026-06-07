class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        sort(citations.begin(),citations.end());
        int ans=-1;
        for(int i=n-1;i>=0 ;i--){
            if(citations[i]<(n-i)){
                return n-i-1;
            }
        }
        return n;
    }
};