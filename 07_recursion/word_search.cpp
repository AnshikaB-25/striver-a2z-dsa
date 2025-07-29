class Solution {
public:
    bool searchnext(vector<vector<char>>& board, string word, int i, int j,
                    int index, int rows, int cols) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i == rows || j == cols ||
            board[i][j] != word[index] || board[i][j] == '!')
            return false;
        char c = board[i][j];
        board[i][j]='!';
        bool left = searchnext(board, word, i+1, j, index+1, rows, cols);
        bool right = searchnext(board, word, i-1, j, index+1, rows, cols);
        bool top = searchnext(board, word, i, j+1, index+1, rows, cols);
        bool bottom = searchnext(board, word, i, j-1, index+1, rows, cols);
        board[i][j]=c;
        return left||right||top||bottom;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        int index = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (searchnext(board, word, i, j, index, rows, cols))
                        return true;
                }
            }
        }
        return false;
    }
};
