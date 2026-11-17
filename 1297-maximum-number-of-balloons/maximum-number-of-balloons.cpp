class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s="abllnoo";
        unordered_map<char,int>mp;
        for(auto &it:text) mp[it-'a']++;
        return min({mp['b'-'a'],mp['a'-'a'],mp['l'-'a']/2,mp['o'-'a']/2,mp['n'-'a']});
    }
};