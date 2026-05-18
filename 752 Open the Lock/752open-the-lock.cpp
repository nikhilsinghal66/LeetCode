class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> mpp;
        //Mapping deadends...
        for(auto it:deadends){
            mpp.insert(it);
        }
        if(mpp.count("0000")){
            return -1;
        }
        //Start with 0000...
        queue<pair<string,int>> q;
        q.push({"0000",0});
        unordered_set<string> set1;
        set1.insert("0000");
        while(!q.empty()){
            string nums=q.front().first;
            int moves=q.front().second;
            q.pop();
            if(nums==target) return moves;
            string number=nums;
            for(int i=0;i<4;i++){
                //9->0;
                if(nums[i]=='9'){
                    nums[i]='0';

                }
                else{
                    nums[i]=nums[i]+1;
                }
                //if(mpp.count(nums)) continue;
                if(!set1.count(nums) && !mpp.count(nums)){
                    q.push({nums,moves+1});
                    set1.insert(nums);
                }
                nums=number;
            }
            for(int i=0;i<4;i++){
                //0->9;
                if(nums[i]=='0'){
                    nums[i]='9';
                }
                else{
                    nums[i]=nums[i]-1;
                }
                //if(mpp.count(nums)) continue;
                if(!set1.count(nums) && !mpp.count(nums)){
                    q.push({nums,moves+1});
                    set1.insert(nums);
                }
                nums=number;
            }
        }
        return -1;
    }
};