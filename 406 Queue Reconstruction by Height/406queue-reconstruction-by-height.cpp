class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        //Sort with no. of person ahead ... 2nd index...
        sort(people.begin(),people.end(),[](vector<int>&a , vector<int> &b){
            if(a[0]!=b[0]){
                return a[0]>b[0];
            }
            return a[1]<b[1];
        });
        //lets put in the correct position...
        vector<vector<int>> ans;
        for(auto &p:people){
            ans.insert(ans.begin()+p[1],p);
        }
        return ans;
    }
};