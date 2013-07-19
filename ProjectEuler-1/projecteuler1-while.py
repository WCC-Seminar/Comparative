#!/usr/bin/python
def sumupto(n):
    answer = 0
    while n:
        if n % 3 == 0 or n % 5 == 0:
            answer += n
        n -= 1
    return answer

def anotherway(n):
    answer = 0
    i = 0
    while i <= n:
        if n % 3 == 0 or n % 5 == 0:
            answer += i
        i += 1
    return answer

if __name__ == "__main__":
    print sumupto(999)
