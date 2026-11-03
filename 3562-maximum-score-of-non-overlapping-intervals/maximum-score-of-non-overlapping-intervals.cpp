
class Solution {
public:
    struct Node {
        long long score = 0;
        vector<int> idxs;
    };

    int n;
    vector<int> nextIdx;

    int findNext(vector<vector<int>>& intervals, int r) {
        int l = 0, h = n - 1;
        int result = n;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (intervals[mid][0] > r) {
                result = mid;
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {
            nextIdx[i] = findNext(intervals, intervals[i][1]);
        }

        int k = 4;

        vector<vector<Node>> dp(
            n + 1, vector<Node>(k + 1)
        );

        // Base cases:
        // dp[n][k] = 0
        // dp[i][0] = 0

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {

                // Skip current interval
                Node skip = dp[i + 1][j];

                // Take current interval
                Node temp = dp[nextIdx[i]][j - 1];

                Node take;
                take.score = temp.score + intervals[i][2];

                take.idxs = temp.idxs;
                take.idxs.push_back(intervals[i][3]);

                sort(take.idxs.begin(), take.idxs.end());

                // Choose the better answer
                if (skip.score > take.score) {
                    dp[i][j] = skip;
                }
                else if (skip.score < take.score) {
                    dp[i][j] = take;
                }
                else {
                    dp[i][j] =
                        (skip.idxs < take.idxs) ? skip : take;
                }
            }
        }

        return dp[0][4].idxs;
    }
};
