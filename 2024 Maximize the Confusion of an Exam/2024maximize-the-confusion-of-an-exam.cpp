class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int l1=0;
        int l2=0;
        int count=0;
        int count1=0;
        int ans=0;
        for(int i=0;i<n;i++){
            //For T first...
            if(answerKey[i]=='T'){
                count++;
            }
            while(count>k){
                if(answerKey[l1]=='T'){
                    count--;
                }
                l1++;
            }
            ans=max(ans,i-l1+1);
            //For F second...
            if(answerKey[i]=='F'){
                count1++;
            }
            while(count1>k){
                if(answerKey[l2]=='F'){
                    count1--;
                }
                l2++;
            }
            ans=max(ans,i-l2+1);
        }
        return ans;
    }
};