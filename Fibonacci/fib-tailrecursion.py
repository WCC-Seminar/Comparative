#!/usr/bin/python

def fib_tail(n, fibs):
    if n == 0:
        return fibs
    elif len(fibs)==0:
        return fib_tail(n-1,[1])
    elif len(fibs)==1:
        return fib_tail(n-1,[1,1])
    else:
        return fib_tail(n-1, fibs + [ fibs[-1] + fibs[-2] ])

def fib(n):
    """
    returns n terms of fibonacci sequence.
    """
    return fib_tail(n,[])

def main():
    print fib(50)

if __name__ == '__main__':
    main()

