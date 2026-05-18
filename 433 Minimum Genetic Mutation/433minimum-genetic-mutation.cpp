class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> gene={'A','C','G','T'};
        //{gene,moves}...
        queue<pair<string,int>> q;
        q.push({startGene,0});
        unordered_set<string> set1;
        unordered_set<string> set_bank;
        for(auto it:bank){
            set_bank.insert(it);
        }
        set1.insert(startGene);
        while(!q.empty()){
            string genetic=q.front().first;
            int moves=q.front().second;
            q.pop();
            if(genetic==endGene) return moves;
            for(int i=0;i<8;i++){
                string temp2=genetic;
                for(int j=0;j<4;j++){
                    temp2[i]=gene[j];
                    if(!set1.count(temp2) && set_bank.count(temp2)){
                        q.push({temp2,moves+1});
                        set1.insert(temp2);
                    }
                }
            }
        }
        return -1;
    }
};