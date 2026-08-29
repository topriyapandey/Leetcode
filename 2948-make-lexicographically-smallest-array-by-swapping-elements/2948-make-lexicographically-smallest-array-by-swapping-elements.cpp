class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> ans(n);

        int i = 0;

        while (i < n) {
            int j = i;

            vector<int> values;
            vector<int> indices;

            while (j < n - 1 && v[j + 1].first - v[j].first <= limit) {
                values.push_back(v[j].first);
                indices.push_back(v[j].second);
                j++;
            }

            values.push_back(v[j].first);
            indices.push_back(v[j].second);

            sort(indices.begin(), indices.end());

            for (int k = 0; k < values.size(); k++) {
                ans[indices[k]] = values[k];
            }

            i = j + 1;
        }

        return ans;
    }
};