#!/usr/bin/python

def fib(n):
    a,b = 1,1
    fibs = []
    for i in xrange(n):
        fibs.append(a)
        a,b = b, a+b
    return fibs

def main():
    print fib(50)

if __name__ == '__main__':
    main()
