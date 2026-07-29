class Solution {
public:

    void solve(int index, string digits, string curr,
               vector<string> &ans, vector<string> &mp) {

        if(index == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for(char ch : letters) {
            solve(index + 1, digits, curr + ch, ans, mp);
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;

        solve(0, digits, "", ans, mp);

        return ans;
    }
};