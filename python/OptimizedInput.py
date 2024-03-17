import sys

optimizedInput = sys.stdin.readline
# sys.stdin.readline can be faster when reading multiple lines of input
# standard 'input()' vs 'sys.stdin.readline()'
# input : stripping the trailing newline - additional work
# sys.stdin.readline : single line from standard input without any
#                 additional processing. No operation like stripping
#                 trailing newlines. Also buffered.

N, M = map(int, input().split()) # split() returns list which is iterable that map() can take


print(type("sds"))