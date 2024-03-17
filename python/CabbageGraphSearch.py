import sys

optimizedInput = sys.stdin.readline

testCase = int(optimizedInput())


def solution(row: int, col: int, num: int) -> int:
    worm = 0
    cabbage_matrix = [[0 for _ in range(col)] for _ in range(row)]
    coordinates = []

    for _ in range(num):
        r, c = map(int, optimizedInput().split())
        cabbage_matrix[r][c] = 1
        coordinates.append([r, c])

    for i in range(num):
        current_row = coordinates[i][0]
        current_col = coordinates[i][1]

        if cabbage_matrix[current_row][current_col] == 1:
            worm += 1
        else:
            continue

        stack = [[current_row, current_col]]

        while len(stack) > 0:
            cr, cc = stack.pop()
            # down
            if cr - 1 >= 0 and cabbage_matrix[cr - 1][cc] == 1:
                stack.append([cr - 1, cc])
                cabbage_matrix[cr - 1][cc] = 0
            # up
            if cr + 1 < row and cabbage_matrix[cr + 1][cc] == 1:
                stack.append([cr + 1, cc])
                cabbage_matrix[cr + 1][cc] = 0
            # right
            if cc + 1 < col and cabbage_matrix[cr][cc + 1] == 1:
                stack.append([cr, cc + 1])
                cabbage_matrix[cr][cc + 1] = 0
            # left
            if cc - 1 >= 0 and cabbage_matrix[cr][cc - 1] == 1:
                stack.append([cr, cc - 1])
                cabbage_matrix[cr][cc - 1] = 0
    return worm


while testCase > 0:
    ROW, COL, NUM = map(int, optimizedInput().split())
    print(solution(ROW, COL, NUM))
    testCase -= 1
