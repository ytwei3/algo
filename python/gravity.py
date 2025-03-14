matrix = [
    ['F', 'F', 'F'],
    ['-', 'F', '-'],
    ['-', 'F', 'F'],
    ['#', 'F', '-'],
    ['F', 'F', '-'],
    ['-', '-', '-'],
    ['-', '-', '#'],
    ['-', '-', '-'],
]

reuslt = [
    ['-', '-', '-'],
    ['-', '-', '-'],
    ['F', 'F', 'F'],
    ['#', 'F', '-'],
    ['-', 'F', 'F'],
    ['-', 'F', '-'],
    ['F', 'F', '#'],
    ['-', '-', '-'],
]

def gravity(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    min_distance = float('inf')

    # Step 1: calculate minimium distance can move
    for row in range(rows):
        for col in range(cols):
            if matrix[row][col] == 'F':
                distance = 0
                falling_row = row + 1

                while falling_row < rows and matrix[falling_row][col] == '-':
                    distance += 1
                    falling_row += 1

                if falling_row == rows or matrix[falling_row][col] == '#':
                    min_distance = min(min_distance, distance)
    
    if min_distance in [0, float('inf')]:
        return matrix

    # Step 2: move one by one from bottom.
    for row in range(rows - 1, min_distance - 1, -1):
        for col in range(cols):
            char = matrix[row - min_distance][col]
            if char == 'F':
                matrix[row][col] = 'F'
                matrix[row - min_distance][col] = '-'
    
    return matrix

def print_matrix(matrix):
    for row in matrix:
        print(row)

print_matrix(gravity(matrix=matrix))