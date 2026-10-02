class Solution {
public:
    int tribonacci(int n) {
        vector<int>T = {0, 1, 1};
        if (n < 3) return T[n];
        for(int i = 0; i <= n-3; i++) {
            int next = T[0] + T[1] + T[2];
            T[0] = T[1];
            T[1] = T[2];
            T[2] = next;
        }
        return T[2];
    }
};