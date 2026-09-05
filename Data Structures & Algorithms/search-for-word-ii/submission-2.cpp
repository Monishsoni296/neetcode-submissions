class TrieNode {
public:
    TrieNode*children[26];
    bool isWord;

    TrieNode() {
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        isWord = false;
    }
};
class Solution {
public:
    vector<vector<bool>>visit;
    vector<string>ans;
    void dfs (int r, int c, TrieNode* node, vector<vector<char>>& board, string& word) {
        int n = board.size(), m = board[0].size();
        if (r < 0 || r >= n || c < 0 || c >= m || visit[r][c]) return;
        if (node->children[board[r][c] - 'a'] == nullptr) return;

        visit[r][c] = true;
        node = node->children[board[r][c] - 'a'];
        word += board[r][c];
        if (node->isWord) {
            ans.push_back(word);
            node->isWord = false;
        }
    
        dfs(r+1, c, node, board, word);
        dfs(r, c+1, node, board, word);
        dfs(r-1, c, node, board, word);
        dfs(r, c-1, node, board, word);
        visit[r][c] = false;
        word.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size(), m = board[0].size();
        visit = vector<vector<bool>>(n, vector<bool>(m, false));
        TrieNode*root = new TrieNode();

        for(auto &word: words) {
            int n = word.size();
            TrieNode*curr = root;

            for(int i = 0; i < n; i++) {
                if(curr->children[word[i] - 'a'] == nullptr) {
                    curr->children[word[i] - 'a'] = new TrieNode();
                }
                curr = curr->children[word[i] - 'a'];
            }
            curr->isWord = true;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                string word = "";
                dfs(i, j, root, board, word);
            }
        }
        return ans;
    }
};
