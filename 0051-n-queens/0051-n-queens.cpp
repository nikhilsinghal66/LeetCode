class Solution {
public:
    void f(int ind,int n,vector<vector<string>> &ans,vector<vector<char>> &temp,unordered_map<int ,set<char>> &col_check,unordered_map<int ,set<char>> &D_right,unordered_map<int ,set<char>> &D_left){
        if(ind==n){
            vector<string> var;
            for(int i=0;i<n;i++){
                string ans="";
                for(int j=0;j<n;j++){
                    ans+=temp[i][j];
                }
                var.push_back(ans);

            }
            ans.push_back(var);
            return;
        }
        for(int i=0;i<n;i++){
            if(col_check[i].count('Q') || D_right[ind+i].count('Q') || D_left[ind-i].count('Q') ){
                continue;
            }
            temp[ind][i]='Q';
            col_check[i].insert('Q');
            D_right[ind+i].insert('Q');
            D_left[ind-i].insert('Q');
            f(ind+1,n,ans,temp,col_check,D_right,D_left);
            temp[ind][i]='.';
            col_check[i].erase('Q');
            D_right[ind+i].erase('Q');
            D_left[ind-i].erase('Q');
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> temp(n,vector<char>(n,'.'));
        unordered_map<int ,set<char>> col_check;
        unordered_map<int,set<char>> D_right;
        unordered_map<int,set<char>> D_left;
        f(0,n,ans,temp,col_check,D_right,D_left);
        return ans;
    }
};