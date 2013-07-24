#!/usr/bin/python
import sys
import time

class Brainsth(object):
    def __init__(self, n, doesprint = True, wait = 0.05):
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
        self.command  = ''
        self.wait = wait

    def refresh(self):
        self.tape = [0] * self.tapelength
        self.pointer = 0
        self.reader = 0
        self.printed_chars = ""

    def give_command(self,command):
        self.command = command

    def add_to_command(self,command):
        self.command += command

    def execute(self):
        self.refresh()
        commandlength = len(self.command)
        while True:
            try:
                currentcommand = self.command[self.reader]
            except:
                break

            if self.doesprint:
                self.printtape()
                self.printcommand()
                self.reprint()
                time.sleep(self.wait)

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
                    self.printed_chars += chr(self.tape[self.pointer])
            elif currentcommand == self.accept:
                self.tape[self.pointer] = input('\n')
            elif currentcommand == self.whileb:
                if not self.tape[self.pointer]:
                    self.reader += self.command[self.reader:].find(self.end) 
            elif currentcommand == self.end:
                if self.tape[self.pointer]:
                    self.reader -= self.command[:self.reader][::-1].find(self.whileb) + 1
            else:
                pass
            self.reader += 1
            if self.doesprint:
                sys.stdout.write('\n')

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

    def printcommand(self):
        for c in self.command[:self.reader]:
            sys.stdout.write("%s" %(c))
        self.emph(self.command[self.reader])
        for c in self.command[self.reader+1:]:
            sys.stdout.write("%s" %(c))
        sys.stdout.write('\n')

    def reprint(self):
        print self.printed_chars



def hello_world():
   command = '++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.' 
   brain = Brainsth(10)
   brain.give_command(command)
   brain.execute()

if __name__ == '__main__':
    hello_world()
