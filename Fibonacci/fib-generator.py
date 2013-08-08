#!/usr/bin/python
import itertools

def fibgenerator():
    a,b = 1,1
    while True:
        yield a
        a,b = b, a+b

def fib(n):
    fibs = fibgenerator()
    return list(itertools.islice(fibs,n))
    # return [fibs.next() for i in xrange(n)] without importing itertools.
    # not sure which is faster.
def main():
    print fib(50)

if __name__ == '__main__': 
    main()
