class Solution {
public:
    bool f(int force, vector<int>&position, int m){
        int count=1;
        int last=position[0];
        for(int i=1;i<position.size();i++){
            if(abs(position[i]-last)>=force){
                count++;
                last=position[i];
            }
        }
        return count>=m;
    }

    int maxDistance(vector<int>& position, int m) {
        int low=1;
        int high=*max_element(position.begin(),position.end());
        sort(position.begin(),position.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int check=f(mid,position,m);
            if(check==true){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};