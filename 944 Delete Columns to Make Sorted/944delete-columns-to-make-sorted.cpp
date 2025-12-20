class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        for(int i=0;i<strs[0].size();i++){
            int check=0;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]<strs[j-1][i]){
                    check=-1;
                }
            }
            if(check==-1){
                ans++;
            }
        }
        return ans;
        
    }
};