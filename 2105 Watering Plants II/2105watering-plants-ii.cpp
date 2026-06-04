class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size();
        int sum=0;
        int cap_A=capacityA;
        int cap_B=capacityB;
        int l=0;
        int r=n-1;
        while(l<r){
            int A=0;
            if(plants[l]<=capacityA){
                capacityA-=plants[l];
            }
            else{
                A=1;
                capacityA=cap_A;
                capacityA-=plants[l];
            }
            int B=0;
            if(plants[r]<=capacityB){
                capacityB-=plants[r];
            }
            else{
                B=1;
                capacityB=cap_B;
                capacityB-=plants[r];
            }
            sum+=A+B;
            l++;
            r--;
            if(l==r){
                if(max(capacityA,capacityB)<plants[l]){
                    sum++;
                }
            }
        }
        return sum;
    }
};