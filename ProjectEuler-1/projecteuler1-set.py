#!/usr/bin/python

def sumbelow(n):
    multiples_of_3 = set(range(0,n,3))
    multiples_of_5 = set(range(0,n,5))
    return sum(multiples_of_3.union(multiples_of_5))

#one linear:
# return sum(set(range(0,n,3)).union(set(range(0,n,5)))),
# or rather,
# return sum(set(range(0,n,3) + range(0,n,5)))

if __name__ == '__main__':
    print sumbelow(1000)
    n = 1000

