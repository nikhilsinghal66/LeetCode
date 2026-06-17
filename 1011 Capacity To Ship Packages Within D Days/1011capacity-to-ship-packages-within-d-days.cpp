class Solution {
public:
    int f(int wgt,vector<int> &weights){
        int count=1;
        int temp=0;
        for(int i=0;i<weights.size();i++){
            if(temp + weights[i] > wgt){
                temp=weights[i];
                count++;
            }
            else{
                temp+=weights[i];
            }
        }
        return count;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(auto x:weights){
            high+=x;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int count_day=f(mid,weights);
            if(count_day<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};