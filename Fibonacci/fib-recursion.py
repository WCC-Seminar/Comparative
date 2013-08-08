#!/usr/bin/python

def fib(n):
    """
    returns n terms of fibonacci sequence.
    """
    if n == 1:
        return [1]
    elif n == 2:
        return [1,1]
    else:
        terms_before = fib(n-1)
        return terms_before + [ terms_before[-1] + terms_before[-2] ]

def main():
    print fib(50)

if __name__ == '__main__':
    main()
