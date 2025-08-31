# Sudoku Solver — Explanation

## Approach
We use **backtracking** (depth-first search):

1. Traverse the grid row by row, column by column.
2. If the cell is empty ('.'):
   - Try digits '1' to '9'.
   - For each digit, check if it's valid (not in the same row, column, or 3x3 subgrid).
   - If valid, place it and recursively continue.
   - If later we get stuck, backtrack (reset to '.') and try next digit.
3. Continue until all cells are filled.

This guarantees a valid solution if it exists.

-------------------

## Complexity
- **Time Complexity:**  
  - Worst case: `O(9^m)` where `m` = number of empty cells.  
  - Each empty cell can have up to 9 choices.

  - **Space Complexity:**  
  - Board storage: `O(81)` = constant (since board is always 9x9).  
  - Recursion depth: up to 81 calls → `O(1)` (constant).
