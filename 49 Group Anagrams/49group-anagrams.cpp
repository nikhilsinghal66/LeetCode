class Solution {
public:
    // int make_int(string str) {
    //     int sum = 0;
    //     for (auto c : str) {
    //         sum += (int)(c);
    //     }
    //     return sum;
    // }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec;
        map<string, vector<string>> mpp;

        for (int i = 0; i < strs.size(); i++) {
            string key=strs[i];
            sort(key.begin(),key.end());
            mpp[key].push_back(strs[i]);
        }

        for (auto &it : mpp) {
            vec.push_back(it.second);
        }

        return vec;
    }
};