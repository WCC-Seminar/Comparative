#!/usr/bin/python
from math import sqrt
import bisect
from primes import primes

# we will assume that a module named primes is available,
# which gives a sorted list (preferably, tuple) of primes.
# Perhaps these functions should better be implemented in class.


def isprime(n, primes = primes):
    """
     Can be used for numbers upto N**2,
     where N = max(primes).
     Algorithm:
        simple brute force using list. 
        looks up n mod p for p <= sqrt n. 

    """
    upto = sqrt(n)
    for p in primes:
        if p > upto:
            return True
        if number % p == 0:
            return False

def isprime_bisect(n, primes = primes):
    """
    Uses bisection algorithm to find if n is in the list of primes.
    The list of primes MUST be sorted beforehands.
    Can be used for numbers upto N.

    """
    i = bisect.bisect_left(primes, n)
    if i != len(primes):
        if primes[i] == n:
            return True
        else:
            return False
    raise ValueError, "Upper limit exceeded."

def isprime_in(n, primes = primes):
    """
    uses built-in function in to find if n is in primes.
    This is a simple one-liner, and doesn't require primes to be sorted,
    but painfully slower than the _bisect.
    """
    return n in primes

"""
no main function is inplemented.
"""
