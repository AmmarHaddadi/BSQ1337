def maximalSquare(matrix):
    #todo: save full, empty, obstacle chars in vars.
    #todo: check maps conditions
    if not matrix or not matrix[0]:
        return matrix

    rows, cols = len(matrix), len(matrix[0])
    # DP table to store the size of the largest square submatrix ending at each position
    dp = [[0] * cols for _ in range(rows)]
    max_side = 0  # Maximum side length of the square found
    max_bottom_right = (0, 0)  # Bottom-right corner of the largest square

    # Iterate over the matrix to fill the DP table
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == '1':
                # For the first row or column, the square can only be of size 1 if matrix[i][j] is '1'
                if i == 0 or j == 0:
                    dp[i][j] = 1
                else:
                    # DP relation: min of top, left, and top-left diagonal + 1
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1

                # Update max side length and the bottom-right corner of the largest square
                if dp[i][j] > max_side:
                    max_side = dp[i][j]
                    max_bottom_right = (i, j)

    # Retrieve the bottom-right corner and side length of the largest square
    r, c = max_bottom_right

    # Replace the largest square with 'X'
    for i in range(r - max_side + 1, r + 1):
        for j in range(c - max_side + 1, c + 1):
            matrix[i][j] = 'X'

    return matrix

# Example usage
matrix = [
    ["1","1","1","1","1","1"],
    ["1","0","1","0","1","1"],
    ["1","1","1","1","1","0"],
    ["1","1","0","1","1","1"],
    ["1","1","1","1","1","1"],
    ["1","1","1","1","1","1"]
]

result = maximalSquare(matrix)

for row in result:
    print(" ".join(row))
