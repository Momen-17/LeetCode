class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return isValidRow(board) && isValidColumn(board) && isValidSubgrid(board);
    }

    bool isValidRow(vector<vector<char>>& board) {
        for (vector<char> row : board) {
            if (!isValidUnit(row)) {
                return false;
            }
        }
        return true;
    }
    
    bool isValidColumn(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<char> column;
            for (int j = 0; j < 9; j++) {
                column.push_back(board[j][i]);
            }

            if (!isValidUnit(column)) {
                return false;
            }
        }
        return true;
    }

    bool isValidSubgrid(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<char> subgrid;
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        subgrid.push_back(board[x][y]);
                    }
                }
                if (!isValidUnit(subgrid)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidUnit(vector<char>& unit) {
        vector<char> unitNums;
        unordered_set<char> unitSet;

        for (char square : unit) {
            if (isdigit(square)) unitNums.push_back(square);
        }
        
        for (char square : unitNums) {
            unitSet.insert(square);
        }
        
        return unitNums.size() == unitSet.size();
    }
};