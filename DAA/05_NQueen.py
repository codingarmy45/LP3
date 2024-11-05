def is_safe(row, col, board, n):
    dup_row, dup_col = row, col

    # Check upper diagonal on the left side
    while col >= 0 and row >= 0:
        if board[row][col] == 'Q':
            return False
        col -= 1
        row -= 1

    # Reset to original row and column for further checks
    row, col = dup_row, dup_col

    # Check left side in the same row
    while col >= 0:
        if board[row][col] == 'Q':
            return False
        col -= 1

    # Reset to original row and column for further checks
    row, col = dup_row, dup_col

    # Check lower diagonal on the left side
    while row < n and col >= 0:
        if board[row][col] == 'Q':
            return False
        row += 1
        col -= 1

    return True

def solve(col, ans, board, n):
    if col == n:
        ans.append(["".join(row) for row in board])  # Add the solution to the answer list
        return

    for row in range(n):
        if is_safe(row, col, board, n):
            board[row][col] = 'Q'  # Place the queen
            solve(col + 1, ans, board, n)  # Recurse to place next queen
            board[row][col] = '.'  # Backtrack

def n_queens(n):
    ans = []
    board = [["." for _ in range(n)] for _ in range(n)]  # Initialize an empty board
    solve(0, ans, board, n)  # Start the recursive solution
    return ans

# Get user input for the board size
n = int(input("Enter the size of the board: "))
solutions = n_queens(n)

# Display each arrangement of queens
for idx, arrangement in enumerate(solutions):
    print(f"Arrangement {idx + 1}:")
    for row in arrangement:
        print(row)
    print()
