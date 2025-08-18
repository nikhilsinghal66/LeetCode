class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<int,int> mpp1;
        map<int,int> mpp2;
        for(int i=0;i<ransomNote.size();i++){
            mpp1[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++){
            mpp2[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(mpp1[ransomNote[i]]<=mpp2[ransomNote[i]]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;

        
    }
};