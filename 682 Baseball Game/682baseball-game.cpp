class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> result;
        int size1=0;
        int ans=0;
        for(auto val:operations){
            if(val=="C"){
                ans-=result.back();
                result.pop_back();
            }
            else if(val=="D"){
                int aa=result.back();
                result.push_back(aa*2);
                ans+=aa*2;
            }
            else if(val=="+"){
                
                int ans1=result.back()+result[result.size()-2];
                result.push_back(ans1);
                ans+=ans1;
            }
            else{
                int a=stoi(val);
                result.push_back(a);
                ans+=a;
            }
        }
        return ans;
    }
};