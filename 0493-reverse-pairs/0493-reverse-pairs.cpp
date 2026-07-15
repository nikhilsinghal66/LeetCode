class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high) {

        // Count reverse pairs
        int cnt = 0;
        int j = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }

        // Merge the two sorted halves
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy back
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return cnt;
    }

    int merge_sort(vector<int>& nums, int low, int high) {

        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        int cnt = 0;

        cnt += merge_sort(nums, low, mid);
        cnt += merge_sort(nums, mid + 1, high);
        cnt += merge(nums, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {

        return merge_sort(nums, 0, nums.size() - 1);
    }
};