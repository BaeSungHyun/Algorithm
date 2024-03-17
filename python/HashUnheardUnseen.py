import sys
import time

optimizedInput = sys.stdin.readline

MOD = 1 << 14
BIT = MOD - 1
R = 15

class Node:
    def __init__(self, name, next_node=None):
        self.name = name
        self.next_node = next_node


class HashMap:
    def __init__(self):
        self.node_list = [Node("")] * MOD  # set list size

    def hashFunc(self, input: str):
        mul = 1
        res = 0
        for i in range(len(input)):
            res = (res + mul * ord(input[i])) & BIT
            mul = (mul * R) & BIT

        return res

    def insert(self, input: str):
        h: int = self.hashFunc(input)

        current: Node = self.node_list[h]
        temp: Node = Node(input)

        temp.next_node = current.next_node
        current.next_node = temp

    def contains(self, input: str, names: list):  # list passed by reference but careful with += , +
        h: int = self.hashFunc(input)

        current: Node = self.node_list[h]
        current = current.next_node

        while current is not None:
            if current.name == input:
                names.append(current.name)
                break
            current = current.next_node


def solution():
    n, m = map(int, optimizedInput().split(' '))

    start = time.time()

    hm = HashMap()
    name_list = []

    for i in range(n):
        name = optimizedInput()
        hm.insert(name)

    end = time.time()
    print(f"Duration: {end - start} seconds")

    start = time.time()
    for i in range(m):
        name = optimizedInput()
        hm.contains(name, name_list)
    end = time.time()
    print(f"Duration: {end - start} seconds")

    start = time.time()
    # sorted(name_list)
    name_list.sort()
    answer: str = str(len(name_list)) + "\n"

    for i in name_list:
        answer += i

    end = time.time()
    print(f"Duration: {end - start} seconds")

    return answer


print(solution())
