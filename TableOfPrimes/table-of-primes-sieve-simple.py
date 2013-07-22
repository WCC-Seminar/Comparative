#!/usr/bin/python
def sieve_of_Eratosthenes(n):
    """ returns a list of primes <= n """
    table = [False,False] + ( [True]*(n-1) ) # (perhaps unnecessary) initialisation. table[n] corresponds to integer n.

    upperlimit = int(n/2)
    for i in xrange(2, upperlimit+1):
        if table[i]:
            jupper = int(n/i)
            for j in xrange(2, jupper+1):
                table[i*j] = False

    return [p for p in xrange(n+1) if table[p] ]

def main():
    N = 1000 # this program will find primes <= N.
    print sieve_of_Eratosthenes(N)

if __name__ == '__main__':
    main()
