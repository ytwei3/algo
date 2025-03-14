'''
'-' represents an empty cell,
'#' represents an obstacle,
'F' corresponds to a cell of a connected figure.

The shape of the figure is unchangable and is represented by 'F' cells.
'''
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


print("unchangable solution: ")
print_matrix(gravity(matrix=matrix))


"""
What if the shape of the figure is changable?

"""
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



expected_reuslt = [
    ['-', '-', '-'],
    ['-', '-', '-'],
    ['F', '-', '-'],
    ['#', 'F', '-'],
    ['-', 'F', 'F'],
    ['-', 'F', 'F'],
    ['-', 'F', '#'],
    ['F', 'F', '-'],
]
def gravity_changable(matrix):
    rows = len(matrix)
    cols = len(matrix[0])

    for col in range(cols):
        count_f = 0
        for row in range(rows):
            if row == rows - 1:
                falling_row = row 
                while count_f > 0:
                    matrix[falling_row][col] = 'F'
                    falling_row -= 1
                    count_f -= 1

            elif matrix[row][col] == '#':
                falling_row = row - 1
                while count_f > 0:
                    matrix[falling_row][col] = 'F'
                    falling_row -= 1
                    count_f -= 1
            
            elif matrix[row][col] == 'F':
                matrix[row][col] = '-'
                count_f += 1
    
    return matrix

print("changable solution: ")
print_matrix(gravity_changable(matrix))