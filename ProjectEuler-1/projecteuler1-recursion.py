#!/usr/bin/python
import sys  # we have to change the recursion limit.
sys.setrecursionlimit(1001)

def sumupto(n):
    if n == 0:
        return 0
    elif n % 3 == 0 or n % 5 == 0:
        return sumupto(n-1) + n
    else:
        return sumupto(n-1)
if __name__ == '__main__':
    print sumupto(999)
