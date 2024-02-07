class Solution(object):
    def isValidSudoku(self, board):
        return self.is_row_valid(board) and \
        self.is_column_valid(board) and \
        self.is_subgrid_valid(board)

    def is_row_valid(self, board):
        for row in board:
            if not self.is_unit_valid(row):
                return False
        return True
    
    def is_column_valid(self, board):
        for column in zip(*board):
            if not self.is_unit_valid(column):
                return False
        return True
    
    def is_subgrid_valid(self, board):
        for i in (0, 3, 6):
            for j in (0, 3, 6):
                subgrid = [board[x][y] for x in range(i, i + 3) for y in range(j, j + 3)]
                if not self.is_unit_valid(subgrid):
                    return False
        return True
    
    def is_unit_valid(self, unit):
        unit = [square for square in unit if square != '.']
        return len(set(unit)) == len(unit)
