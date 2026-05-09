class Solution {
public:
    bool isprime(int num){
        if(num<2) return false;
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n=nums.size();
        //{dist,index};
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<int> vis(n,0);
        //finding prime number and its multiples...
        // unordered_map<int,vector<pair<int,int>>> mpp;
        // for(int i=0; i<n; i++) {
        unordered_map<int, vector<pair<int,int>>> mpp;
        for(int i=0; i<n; i++) {
            int num = nums[i];
            for(int p=2; p*p<=num; p++) {
                if(num % p == 0) {
                    if(isprime(p)) {
                        mpp[p].push_back({nums[i], i});
                    }
                    while(num % p == 0) {
                        num /= p;
                    }
                }
            }
            // remaining prime factor
            if(num > 1) {
                mpp[num].push_back({nums[i], i});
            }
        }
        vis[0] = 1;
        while(!q.empty()){
            int dist=q.front().first;
            int ind=q.front().second;
            q.pop();
            if(ind==n-1){
                return dist;
            }
            //i-1 && i+1;
            if(ind-1>=0 && !vis[ind-1]){
                vis[ind-1]=1;
                q.push({dist+1,ind-1});
            }
            //i+1;
            if(ind+1<n && !vis[ind+1]){
                vis[ind+1]=1;
                q.push({dist+1,ind+1});
            }

            //Teleport...
            if(isprime(nums[ind])){
                if(mpp.find(nums[ind])!=mpp.end()){
                    for(auto it:mpp[nums[ind]]){
                        if(!vis[it.second]){
                            vis[it.second]=1;
                            q.push({dist+1,it.second});
                        }
                    }
                }
                mpp[nums[ind]].clear();
            }
        }
        return -1;  
    }
};