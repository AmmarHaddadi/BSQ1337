def maximalSquare(matrix):
    #todo: save full, empty, obstacle chars in vars.
    #todo: check maps conditions
    if not matrix or not matrix[0]:
        return matrix

    rows, cols = len(matrix), len(matrix[0])
    # DP table to store the size of the largest square submatrix ending at each position
    dp = [[0] * cols for _ in range(rows)]
    atwal_9otr = 0  # Maximum side length of the square found
    max_bottom_right = (0, 0)  # Bottom-right corner of the largest square

    # Iterate over the matrix to fill the DP table
    for y in range(rows):
        for x in range(cols):
            if matrix[y][x] == '1':
                # For the first row or column, the square can only be of size 1 if matrix[i][j] is '1'
                if y == 0 or x == 0:
                    dp[y][x] = 1
                else:
                    # DP relation: min of top, left, and top-left diagonal + 1
                    dp[y][x] = min(dp[y-1][x], dp[y][x-1], dp[y-1][x-1]) + 1

                # Update max side length and the bottom-right corner of the largest square
                if dp[y][x] > atwal_9otr:
                    atwal_9otr = dp[y][x]
                    max_bottom_right = (y, x)

    # Retrieve the bottom-right corner and side length of the largest square
    y_bot_r, x_bot_r = max_bottom_right

    # Replace the largest square with 'X'
    for y in range(y_bot_r - atwal_9otr + 1, y_bot_r + 1):
        for x in range(x_bot_r - atwal_9otr + 1, x_bot_r + 1):
            matrix[y][x] = 'X'

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
