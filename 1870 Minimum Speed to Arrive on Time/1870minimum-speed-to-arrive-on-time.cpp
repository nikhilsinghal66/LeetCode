class Solution {
public:
    bool f(vector<int>& dist, double hour, int speed){
        double count_time=0;
        for(int i=0;i<dist.size();i++){
            if(i==dist.size()-1){
                count_time+=(double)dist[i]/speed;
            }
            else{
                count_time+=ceil((double)dist[i]/speed);
            }
        }
        return count_time<=hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high=1e9;
        if(hour<=dist.size()-1) return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool check=f(dist,hour,mid);
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