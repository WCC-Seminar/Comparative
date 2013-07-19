#!/usr/bin/python
def sumbelow(n):
    answer = 0
    for i in range(1,n):
        answer += (i % 3 == 0 or i % 5 == 0) and i
    return answer

if __name__ == "__main__":
    print sumbelow(1000)
