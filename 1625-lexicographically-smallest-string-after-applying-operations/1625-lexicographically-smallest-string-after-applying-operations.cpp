class Solution {
public:
    string add(int a,string s){
        string ans=s;
        for(int i=1;i<s.size();i+=2){
            int sum=((s[i]-'0')+a)%10;
            ans[i]=sum+'0';
        }
        return ans;
    }

    string rotate(int b,string s){
        string ans="";
        ans=s.substr(s.size()-b)+s.substr(0,s.size()-b);
        return ans;
    }

    string findLexSmallestString(string s, int a, int b) {
        int n=s.size();
        queue<string> q;
        q.push(s);
        unordered_set<string> set1;
        set1.insert(s);
        string ans=s;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans=min(ans,it);
            //add...
            if(set1.find(add(a,it))==set1.end()){
                set1.insert(add(a,it));
                q.push(add(a,it));
            }
            //rotate...
            if(set1.find(rotate(b,it))==set1.end()){
                set1.insert(rotate(b,it));
                q.push(rotate(b,it));
            }
        }
        return ans;
    }
};