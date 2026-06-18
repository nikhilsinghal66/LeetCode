class Solution {
public:
    bool f(int n, vector<int>& quantities,int product){
        int count=0;
        for(auto x:quantities){
            count+=ceil((double)x/product);
        }
        return count<=n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high = *max_element(quantities.begin(), quantities.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            bool check=f(n,quantities,mid);
            if(check==true){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};