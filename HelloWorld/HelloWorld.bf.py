#!/usr/bin/python
import sys

class Brainsth(object):
    def __init__(self, n):
        self.tapelength = n
        self.tape = [0] * n
        self.pointer = 0
        self.reader = 0
        self.right = '>'
        self.left  = '<'
        self.incr  = '+'
        self.decr  = '-'
        self.output= '.'
        self.accept= ','
        self.whileb= '['
        self.end   = ']'

    def refresh(self):
        self.tape = [0] * self.tapelength
        self.pointer = 0
        self.reader = 0

    def execute(self,command):
        self.refresh()
        commandlength = len(command)
        while True:
            try:
                currentcommand = command[self.reader]
            except:
                break

            if currentcommand == self.right:
                self.pointer += 1
            elif currentcommand == self.left:
                self.pointer -= 1
            elif currentcommand == self.incr:
                self.tape[self.pointer] += 1
            elif currentcommand == self.decr:
                self.tape[self.pointer] -= 1
            elif currentcommand == self.output:
                sys.stdout.write(chr(self.tape[self.pointer]))
            elif currentcommand == self.accept:
                self.tape[self.pointer] = input('\n')
            elif currentcommand == self.whileb:
                if not self.tape[self.pointer]:
                    self.reader += command[self.reader:].find(self.end) 
            elif currentcommand == self.end:
                if self.tape[self.pointer]:
                    self.reader -= command[:self.reader][::-1].find(self.whileb) + 1
            else:
                pass
            self.reader += 1
        return 0


def hello_world():
   command = '++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.' 
   brain = Brainsth(10)
   brain.execute(command)

if __name__ == '__main__':
    hello_world()
