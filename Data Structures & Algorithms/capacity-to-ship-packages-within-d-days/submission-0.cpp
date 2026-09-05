class Solution {
public:
    int numOfDays(int w, vector<int>& weights) {
        int ans = 1, curr_w = 0;
        for(auto &i: weights) {
            if (curr_w + i  > w) {
                curr_w = 0;
                ans++;
            }
            curr_w += i;
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), r = 1e8, ans = 1e8;
        while(l <= r) {
            int mid = (l+r)/2;
            if (numOfDays(mid, weights) <= days) ans = mid, r = mid-1;
            else l = mid+1;
        }
        return ans;
    }
};