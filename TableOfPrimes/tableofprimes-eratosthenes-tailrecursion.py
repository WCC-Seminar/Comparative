#!/usr/bin/python
def sieve_t(table, primes):
    # table has to be given as a list.
    if len(table) == 1:
        return primes + table
    else:
        p = table.pop(0)
        primes.append(p)
        for pn in xrange(p*p, table[-1]+1, p):
            try:
                table.remove(pn)
            except:
                pass
        return sieve_t(table, primes)

def sieve_of_eratosthenes(n):
    return sieve_t(range(2,n), []) #thus xrange won't work.
 
def main():
    N = 1000
    print sieve_of_eratosthenes(N)

if __name__ == '__main__':
    main()
