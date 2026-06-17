class Solution {
public:
    bool f(vector<int>& bloomDay, int m, int k,int days){
        int count=0;
        int temp=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                temp++;
                if(temp==k){
                    count++;
                    temp=0;
                }
            }
            else{
                temp=0;
            }
        }
        return count>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        long long check=1LL*m*k;
        if(bloomDay.size()<check) return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int possible=f(bloomDay,m,k,mid);
            if(possible==true ){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};