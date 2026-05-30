class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix;
        vector<int> sufix;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }
        long long sum1=0;
        for(int i=n-1;i>=0;i--){
            sum1+=nums[i];
            sufix.push_back(sum1);
        }
        reverse(sufix.begin(),sufix.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(i==0){
                int result=sufix[i+1]-(num*(n-i-1));
                ans.push_back(result);
            }
            else if(i==n-1){
                int result=(num*i)-prefix[i-1];
                ans.push_back(result);
            }
            else{
                int result=(((num*i)-prefix[i-1]) + sufix[i+1]-(num*(n-i-1)));
                ans.push_back(result);
            }
        }
        return ans;
    }
};