class Solution {
public:
    double angleClock(int hour, int minutes) {
        //Angle finding...
        double ans=abs((double)6*minutes-((double)((double)(hour%12)*30)+((double)minutes*0.5)));
        double ans1=360-ans;
        return min(ans,ans1);
    }
};