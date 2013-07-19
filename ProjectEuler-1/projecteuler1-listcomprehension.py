#!/usr/bin/python
if __name__ == "__main__":
    print sum( [n for n in xrange(1,1000) if n % 3 == 0 or n % 5 == 0] )
