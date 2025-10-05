class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int freeBottles=numBottles;
        int result=numBottles;
        while(freeBottles>=numExchange){
            freeBottles-=numExchange;
            result++;
            freeBottles++;
            numExchange++;
        }
        return result; 
    }
};