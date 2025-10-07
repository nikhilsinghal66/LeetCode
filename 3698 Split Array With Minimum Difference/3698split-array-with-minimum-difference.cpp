// class Solution {
// public:
//     long long min(int a, int b){
//         long long c=0;
//         if(a<b){
//             c=a;
//         }
//         else {
//             c=b;
//         }
//         return c;
//     }

//     vector<vector<long long>> make_left(vector<int> arr, int start, int end){
//         vector<vector<long long>> vec;
//         if(start==end){
//             vec.push_back({1,arr[start]});
//         }
//         long long comp=arr[start];
//         long long sum1=arr[start];
//         for(int i=start+1;i<=end;i++){
//             if(arr[i]<=comp){
//                 vec.push_back({0,0});
//                 return vec;
//             }
//             else{
//                 comp=arr[i];
//             }
//             sum1+=arr[i]; 
//         }
//         vec.push_back({1,sum1});
//         return vec;
//     }

//     vector<vector<long long>> make_right(vector<int> arr, int start, int end){
//         vector<vector<long long>> vec;
//         if(start==end){
//             vec.push_back({1,arr[start]});
//         }
//         if (start > end) {   
//             vec.push_back({0, 0});
//             return vec;
//         }
//         long long comp=arr[start];
//         long long sum1=arr[start];
//         for(int i=start+1;i<=end;i++){
//             if(arr[i]>=comp){
//                 vec.push_back({0,0});
//                 return vec;
//             }
//             else{
//                 comp=arr[i];
//             }
//             sum1+=arr[i]; 
//         }
//         vec.push_back({1,sum1});
//         return vec;
//     }

//     long long splitArray(vector<int>& nums) {
//         long long minimum1=INT_MAX;
//         int found=0;
//         for(int i=0;i<nums.size();i++){
//             vector<vector<long long>> left=make_left(nums,0,i);
//             vector<vector<long long>> right=make_right(nums,i+1,nums.size()-1);
//             if(left[0][0]==1 && right[0][0]==1){
//                 found=1;
//                 long long number=llabs(left[0][1]-right[0][1]);
//                 minimum1=min(minimum1, number); 
//             }
//         }
//         if(found==0) return -1;
//         return minimum1; 
//     }
// };


// class Solution {
// public:
//     // strict increasing check on [start..end], also return sum
//     vector<vector<long long>> make_left(vector<int>& arr, int start, int end) {
//         vector<vector<long long>> vec;
//         if (start > end) return {{0,0}};  // invalid
//         long long comp = arr[start];
//         long long sum1 = arr[start];
//         for (int i = start + 1; i <= end; i++) {
//             if (arr[i] <= comp) { // must be strictly increasing
//                 vec.push_back({0,0});
//                 return vec;
//             }
//             comp = arr[i];
//             sum1 += arr[i];
//         }
//         vec.push_back({1,sum1});
//         return vec;
//     }

//     // strict decreasing check on [start..end], also return sum
//     vector<vector<long long>> make_right(vector<int>& arr, int start, int end) {
//         vector<vector<long long>> vec;
//         if (start > end) return {{0,0}};  // invalid
//         long long comp = arr[start];
//         long long sum1 = arr[start];
//         for (int i = start + 1; i <= end; i++) {
//             if (arr[i] >= comp) { // must be strictly decreasing
//                 vec.push_back({0,0});
//                 return vec;
//             }
//             comp = arr[i];
//             sum1 += arr[i];
//         }
//         vec.push_back({1,sum1});
//         return vec;
//     }

//     long long splitArray(vector<int>& nums) {
//         long long minimum1 = LLONG_MAX;
//         bool found = false;
//         int n = nums.size();

//         for (int i = 0; i < n-1; i++) { // split at i | i+1
//             vector<vector<long long>> left = make_left(nums, 0, i);
//             vector<vector<long long>> right = make_right(nums, i+1, n-1);

//             if (left[0][0] == 1 && right[0][0] == 1) {
//                 found = true;
//                 long long number = llabs(left[0][1] - right[0][1]);
//                 minimum1 = min(minimum1, number);
//             }
//         }

//         return found ? minimum1 : -1;
//     }
// };


class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n);
        vector<bool> isInc(n);   // strictly increasing prefix
        prefixSum[0] = nums[0];
        isInc[0] = true;

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
            isInc[i] = isInc[i-1] && nums[i] > nums[i-1];
        }

        vector<long long> suffixSum(n);
        vector<bool> isDec(n);   // strictly decreasing suffix
        suffixSum[n-1] = nums[n-1];
        isDec[n-1] = true;

        for (int i = n-2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i+1] + nums[i];
            isDec[i] = isDec[i+1] && nums[i] > nums[i+1];
        }

        long long ans = LLONG_MAX;
        bool found = false;

        for (int i = 0; i < n-1; i++) {
            if (isInc[i] && isDec[i+1]) {
                long long diff = llabs(prefixSum[i] - suffixSum[i+1]);
                ans = min(ans, diff);
                found = true;
            }
        }

        return found ? ans : -1;
    }
};