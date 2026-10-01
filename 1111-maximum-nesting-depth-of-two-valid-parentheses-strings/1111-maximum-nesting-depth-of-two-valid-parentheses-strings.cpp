class Solution {
public:
    vector<int> maxDepthAfterSplit(auto s) {
        int n = s.size(); vector<int> res(n);
        
        for (int i = 1; i < n; i++)
            res[i] = (i ^ s[i]) & 1;

        return res;
    }
};