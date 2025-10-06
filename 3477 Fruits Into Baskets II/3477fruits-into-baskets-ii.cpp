class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced=0;
        int placed=0;
        vector<int> check(baskets.size(),-1);
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(fruits[i]<=baskets[j] && check[j]==-1){
                    placed++;
                    check[j]=1;
                    break;
                }
            }
        }
        return fruits.size()-placed;   
    }
};