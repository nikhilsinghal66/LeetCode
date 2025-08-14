class Solution {
public:
    string largestGoodInteger(string num) {
        string largest = "";
        for (int i = 2; i < num.size(); i++) {
            if (num[i] == num[i-1] && num[i-1] == num[i-2]) {
                string triplet(3, num[i]); // direct constructor instead of make_string()
                if (triplet > largest) {
                    largest = triplet;
                }
            }
        }
        return largest;
    }
};