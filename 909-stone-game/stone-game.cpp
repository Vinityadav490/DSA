class Solution {
private:
    bool helper(vector<int>& piles, int left, int right, int asum, int bsum, bool isA){
        if (left>=right){
            return asum>bsum;
        }

        bool takeLeft = false, takeRight = false;

        if (isA){
            takeLeft = helper(piles, left+1, right, asum+piles[left], bsum, false);
            takeRight = helper(piles, left, right-1, asum+piles[right], bsum, false);
        }else{
            takeLeft = helper(piles, left+1, right, asum, bsum+piles[left], true);
            takeRight = helper(piles, left, right-1, asum, bsum+piles[right], true);
        }

        return takeLeft || takeRight;
    }
public:
    bool stoneGame(vector<int>& piles) {
        return true;
        return helper(piles, 0, piles.size()-1, 0, 0, true);
    }
};