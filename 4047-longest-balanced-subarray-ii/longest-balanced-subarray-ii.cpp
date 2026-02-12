#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    struct Node {
        int min_val;
        int max_val;
        int lazy;
    };

    vector<Node> tree;
    int n;

    void push(int node) {
        if (tree[node].lazy != 0) {
            tree[2 * node].min_val += tree[node].lazy;
            tree[2 * node].max_val += tree[node].lazy;
            tree[2 * node].lazy += tree[node].lazy;

            tree[2 * node + 1].min_val += tree[node].lazy;
            tree[2 * node + 1].max_val += tree[node].lazy;
            tree[2 * node + 1].lazy += tree[node].lazy;

            tree[node].lazy = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (l > end || r < start) return;
        if (l <= start && end <= r) {
            tree[node].min_val += val;
            tree[node].max_val += val;
            tree[node].lazy += val;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        tree[node].min_val = min(tree[2 * node].min_val, tree[2 * node + 1].min_val);
        tree[node].max_val = max(tree[2 * node].max_val, tree[2 * node + 1].max_val);
    }

    // Initialize position p with value v (effectively a point update without lazy impact on others initially)
    void set_val(int node, int start, int end, int p, int v) {
        if (start == end) {
            tree[node].min_val = v;
            tree[node].max_val = v;
            tree[node].lazy = 0;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        if (p <= mid) set_val(2 * node, start, mid, p, v);
        else set_val(2 * node + 1, mid + 1, end, p, v);
        tree[node].min_val = min(tree[2 * node].min_val, tree[2 * node + 1].min_val);
        tree[node].max_val = max(tree[2 * node].max_val, tree[2 * node + 1].max_val);
    }

    int find_leftmost_zero(int node, int start, int end) {
        // Optimization: if 0 is not in the range [min, max], return -1
        if (tree[node].min_val > 0 || tree[node].max_val < 0) return -1;
        
        if (start == end) {
            return (tree[node].min_val == 0) ? start : -1;
        }
        
        push(node);
        int mid = (start + end) / 2;
        
        // Try left child first to find the longest subarray (smallest index)
        int res = find_leftmost_zero(2 * node, start, mid);
        if (res != -1) return res;
        
        return find_leftmost_zero(2 * node + 1, mid + 1, end);
    }

public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return 0;

        // Initialize tree with a safe large value so unvisited indices don't trigger 0
        tree.resize(4 * n);
        // Using a loop to init effectively or just handle via set_val logic. 
        // We will initialize indices to a sentinel as we go or just rely on the fact 
        // that we only query valid ranges? 
        // Safer: fill with Infinity.
        fill(tree.begin(), tree.end(), Node{n + 1, n + 1, 0}); 

        vector<int> last_pos(100001, -1);
        int max_len = 0;

        for (int j = 0; j < n; ++j) {
            int val = nums[j];
            int type = (val % 2 == 0) ? 1 : -1;
            
            // 1. Initialize the state for the new subarray starting at j (nums[j...j])
            // Before adding type, the conceptual sum is 0. 
            // We set it to 0, then apply the update.
            set_val(1, 0, n - 1, j, 0);

            // 2. Update ranges based on distinct element contribution
            int prev = last_pos[val];
            // Range to update: (prev, j] -> [prev + 1, j]
            update(1, 0, n - 1, prev + 1, j, type);

            // 3. Update last position
            last_pos[val] = j;

            // 4. Find smallest i <= j such that Tree[i] == 0
            // Since we initialized with infinity, indices > j won't be 0.
            int i = find_leftmost_zero(1, 0, n - 1);
            
            if (i != -1) {
                max_len = max(max_len, j - i + 1);
            }
        }

        return max_len;
    }
};