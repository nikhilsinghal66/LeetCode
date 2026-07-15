class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // vector<vector<int>> pascal(numRows,1);
        vector<vector<int>> pascal;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                temp.push_back(1);
            }
            pascal.push_back(temp);
        }
        if(numRows==1){
            return pascal;
        }
        if(numRows==2){
            return pascal;
        }
        for(int i=2;i<numRows;i++){
            for(int j=1;j<i;j++){
                pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
            }
        }
        return pascal;
    }
};