class Solution {
public:
    string majorityFrequencyGroup(string s) {
        string str="";
        if(s.size()==0) return str;
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        unordered_map<int,vector<char>> mpp1;
        for(auto it:mpp){
            mpp1[it.second].push_back(it.first);
        }
        int size1 =0;
        int result=0;
        for(auto it: mpp1){
            if(it.second.size()>size1){
                size1=it.second.size();
                result=it.first;
            }
            else if(it.second.size()==size1){
                result=max(it.first,result);
            }
        }
        // string str="";
        vector<char> vec;
        vec=mpp1[result];
        for(int i=0;i<vec.size();i++){
            str+=vec[i];
        }
        return str;
    }
};