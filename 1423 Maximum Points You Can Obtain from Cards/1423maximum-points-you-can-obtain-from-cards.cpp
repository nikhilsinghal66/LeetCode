class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0;
        int r=n-k;
        int sum=0;
        int total_sum=0;
        for(int i=0;i<n;i++){
            total_sum+=cardPoints[i];
        }
        if(r==0){
            return total_sum;
        }
        for(int i=0;i<r;i++){
            sum+=cardPoints[i];
        }
        int result=sum;
        for(int i=r;i<n;i++){
            sum-=cardPoints[l];
            l++;
            sum+=cardPoints[i];
            result=min(sum,result);
        }
        return total_sum-result;
    }
};