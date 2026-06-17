class Solution {
public:
    long long f(int num,vector<int> &piles){
        long long count=0;
        for(int i=0;i<piles.size();i++){
            count+=((piles[i]+num-1)/num);
        }
        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            long long check=f(mid,piles);
            if(check<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};