class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int k) {
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= mid) {
                count++;

                if(count >= k)
                    return true;

                i++; // cannot rob adjacent house
            }
        }

        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while(l <= h) {
            int mid = l + (h - l) / 2;

            if(isPossible(mid, nums, k)) {
                ans = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};