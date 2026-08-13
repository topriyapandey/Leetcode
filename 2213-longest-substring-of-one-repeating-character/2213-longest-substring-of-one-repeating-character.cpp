#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int maxLen = 0;
    int prefLen = 0;
    int suffLen = 0;
    char leftChar = ' ';
    char rightChar = ' ';
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right, int leftLen, int rightLen) {
        Node res;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;

        res.maxLen = max(left.maxLen, right.maxLen);
        res.prefLen = left.prefLen;
        if (left.prefLen == leftLen && left.rightChar == right.leftChar) {
            res.prefLen = leftLen + right.prefLen;
        }

        res.suffLen = right.suffLen;
        if (right.suffLen == rightLen && left.rightChar == right.leftChar) {
            res.suffLen = rightLen + left.suffLen;
        }

        // Check combined segment across the middle boundary
        if (left.rightChar == right.leftChar) {
            res.maxLen = max(res.maxLen, left.suffLen + right.prefLen);
        }

        return res;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        
        int leftLen = mid - start + 1;
        int rightLen = end - mid;
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], leftLen, rightLen);
    }

    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {1, 1, 1, val, val};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }

        int leftLen = mid - start + 1;
        int rightLen = end - mid;
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], leftLen, rightLen);
    }

public:
    SegmentTree(const string& s) {
        n = s.length();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
    }

    void update(int idx, char val) {
        update(1, 0, n - 1, idx, val);
    }

    int getMax() const {
        return tree[1].maxLen;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            st.update(queryIndices[i], queryCharacters[i]);
            ans[i] = st.getMax();
        }

        return ans;
    }
};