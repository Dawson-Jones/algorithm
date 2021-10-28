class Solution {
public:
    bool check(vector<vector<char>> &board, vector<vector<int>> &visited, int i, int j, string &s, int k) {
        if (board[i][j] != s[k])
            return false;

        // s[k] equals current board[i][j]
        if (k == s.length() - 1)
            return true;
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (auto &dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (visited[newi][newj])
                    continue;
                if ((result = check(board, visited, newi, newj, s, k+1)))
                    break;
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (check(board, visited, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};