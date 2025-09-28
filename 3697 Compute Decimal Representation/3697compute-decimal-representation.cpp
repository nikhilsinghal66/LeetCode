class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> vec;
        long long a=1;
        while(n>0){
            long long temp=n%10;
            temp=temp*a;
            n=n/10;
            if(temp!=0){
                vec.push_back(temp);
            }
            
            a*=10;
        }
        reverse(vec.begin(),vec.end());
        return vec;
        
    }
};