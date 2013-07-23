#!/usr/bin/python
import sys

class Brainsth(object):
    def __init__(self, n, doesprint = True):
        self.tapelength = n
        self.tape = [0] * n
        self.pointer = 0
        self.reader = 0
        self.printed_chars = ""
        self.doesprint = doesprint
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
        self.printed_chars = ""

    def execute(self,command):
        self.refresh()
        commandlength = len(command)
        while True:
            try:
                currentcommand = command[self.reader]
            except:
                break

            if self.doesprint:
                self.printtape()
                self.printcommands(command)
                self.reprint()

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
                if self.doesprint:
                    sys.stdout.write('\n')
                    self.printed_chars += chr(self.tape[self.pointer])
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

        if self.doesprint:
            self.reprint()
        return 0
    
    def emph(self,chars):
        sys.stdout.write("\033[0;31m%s\033[0m" %(chars))

    def printtape(self):
        for x in self.tape[:self.pointer]:
            sys.stdout.write("%d\t" %(x))
        self.emph(self.tape[self.pointer])
        sys.stdout.write("\t")
        for x in self.tape[self.pointer +1 :]:
            sys.stdout.write("%d\t"%(x))
        sys.stdout.write('\n')

    def printcommands(self,command):
        for c in command[:self.reader]:
            sys.stdout.write("%s" %(c))
        self.emph(command[self.reader])
        for c in command[self.reader+1:]:
            sys.stdout.write("%s" %(c))
        sys.stdout.write('\n')

    def reprint(self):
        print self.printed_chars



def hello_world():
   command = '++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.' 
   brain = Brainsth(10)
   brain.execute(command)

if __name__ == '__main__':
    hello_world()
