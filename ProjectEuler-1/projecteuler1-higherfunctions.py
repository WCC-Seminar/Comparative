#!/usr/bin/python
def sumupto(n):
    return reduce( lambda x,y: x+y, filter(lambda m: (m%3==0 or m%5==0), range(n)))

if __name__ == '__main__':
    print sumupto(1000)
