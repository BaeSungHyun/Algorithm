import sys

opti_input = sys.stdin.readline


def DFS(edges: [[]], ver_start: int, visited: [bool], answer: []):
    visited[ver_start] = True

    answer.append(str(ver_start))

    for neighbor in edges[ver_start]:
        if not visited[neighbor]:
            DFS(edges, neighbor, visited, answer)


def BFS(edges: [[]], ver_start: int, visited: [bool], answer: []):
    queueBFS = []
    queueBFS.append(ver_start)
    visited[ver_start] = True

    while queueBFS: # len(queueBFS) != 0
        temp = queueBFS.pop(0)

        answer.append(str(temp))

        for neighbor in edges[temp]:
            if not visited[neighbor]:
                queueBFS.append(neighbor)
                visited[neighbor] = True


def solution():
    ver_num, edge_num, start_ver = map(int, opti_input().split(' '))

    edges = [[] for j in range(0, ver_num + 1, 1)]  # 1-indexing
    for i in range(edge_num):
        v1, v2 = map(int, opti_input().split(' '))
        edges[v1].append(v2)
        edges[v2].append(v1)

    for i in range(ver_num + 1):
        edges[i].sort()

    visited = [False for i in range(0, ver_num + 1, 1)]

    answerDFS = []
    DFS(edges, start_ver, visited, answerDFS)
    print(' '.join(answerDFS))

    # for i in visited: COPIES NEW ELEMENT
    #     i = True
    for i in range(len(visited)):
        visited[i] = False

    answerBFS = []
    BFS(edges, start_ver, visited, answerBFS)
    print(' '.join(answerBFS))


solution()
