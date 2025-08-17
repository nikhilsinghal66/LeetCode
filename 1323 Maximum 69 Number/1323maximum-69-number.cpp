class Solution {
public:
    vector<int> make_vector(int num){
        vector<int> number;
        while(num>0){
            int temp=num%10;
            number.push_back(temp);
            num=num/10;
        }
        reverse(number.begin(),number.end());
        return number;
    }
    int make_int(vector<int> number) {
        int num = 0;
        for (int i = 0; i < number.size(); i++) {
            num = num * 10 + number[i];
        }
        return num;
    }

    int make_greater(vector<int> &number){
        int n=number.size();
        int maxi=make_int(number);
        for(int i=0;i<n;i++){
            if(number[i]==6){
                number[i]=9;
                int num=make_int(number);
                maxi=max(num,maxi);
                break;
            }
        }
        return maxi;
    }

    int maximum69Number (int num) {
        vector<int> number;
        number=make_vector(num);
        int num1=make_greater(number);
        return num1;    
    }
};