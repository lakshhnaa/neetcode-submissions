class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows cls box undordered set
        vector<unordered_set<char>>rows(9);
        vector<unordered_set<char>>cols(9);
        vector<unordered_set<char>>boxes(9);
        // traverse two loop
        for(int r =0;r<9;r++){
            for(int c=0;c<9;c++){
                // if . continue
                if(board[r][c]=='.') continue;
                // compute box number
                int box = (r/3)*3+(c/3);
                // check duplicate
                 if(rows[r].count(board[r][c]) ||
                   cols[c].count(board[r][c]) ||
                   boxes[box].count(board[r][c]))
                {
                    return false;
                }
                // if no duplicate insert
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                boxes[box].insert(board[r][c]);
            }
        }

        return true;
    }
};
