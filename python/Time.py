import time
import sys

start = time.time()

print(sys.maxsize)

for i in range(500000):
    x = i

end = time.time()
print(f"Duration: {end - start} seconds")
