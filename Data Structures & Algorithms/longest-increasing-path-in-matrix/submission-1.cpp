class Solution {
public:
    vector<vector<int>>dir{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int dfs(int x, int y, vector<vector<int>>& path, vector<vector<int>>& matrix) {
        int ans = 0, n = matrix.size(), m = matrix[0].size();
        for(auto &d: dir) {
            auto nxt_x = x + d[0], nxt_y = y + d[1];
            if(nxt_x < 0 || nxt_x >= n || nxt_y < 0 || nxt_y >= m) continue;
            if(matrix[x][y] >= matrix[nxt_x][nxt_y]) continue;
            ans = max(ans, path[nxt_x][nxt_y] != -1 ? path[nxt_x][nxt_y] : dfs(nxt_x, nxt_y, path, matrix));
        }
        return path[x][y] = ans + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>path(n, vector<int>(m, -1)); // to store path length

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, path[i][j] != -1 ? path[i][j] : dfs(i, j, path, matrix));
            }
        }
        return ans; 
    }
};
