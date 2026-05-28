class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> pq;
        int n=nums.size();
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            pq.push(it);
        }
        if(pq.size()<=2){
            return pq.top();
        }
        int max=-1;
        for(int i=0;i<3;i++){
            max=pq.top();
            pq.pop();
        }
        return max;
    }
};