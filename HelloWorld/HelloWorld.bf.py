#!/usr/bin/python
import sys
import time

class BrainSth(object):
    def __init__(self, tapelength, print_every_step = True, wait = 0.05):
        # body
        self.code = None
        self.tape = BFTape(tapelength)
        self.commands = BFCommands()
        self.printed_chars = ""
        # settings
        self.print_every_step = print_every_step
        self.wait = wait
    
    def give_code(self, code):
        self.code = BFCode(code)
    
    def add_to_code(self, codetoadd):
        self.code.add_to_code(codetoadd)
    
    def clearcode(self):
        self.code = None
    
    def refresh(self):
        self.code.reset(None)
        self.tape.refresh()
        self.printed_chars = ''
    
    def execute_command(self, command):
        if self.print_every_step:
            print self.tape
            print self.code
            self.reprint()
            time.sleep(self.wait)
        
        if command == self.commands.right:
            self.tape.right()
        elif command == self.commands.left:
            self.tape.left()
        elif command == self.commands.incr:
            self.tape.incr()
        elif command == self.commands.decr:
            self.tape.decr()
        elif command == self.commands.output:
            sys.stdout.write( chr(self.tape.read()) )
            self.printed_chars += chr(self.tape.read())
        elif command == self.commands.accept:
            self.tape.accept( input('\n') )
        elif command == self.commands.whileb:
            if self.tape.read() == 0:
                self.code.jump_to_match()
        elif command == self.commands.whilee:
            if self.tape.read() != 0:
                self.code.jump_to_match()
        else:
            pass
        
        self.code.proceed()
        if self.print_every_step:
            sys.stdout.write('\n')
        
    def reprint(self):
        print self.printed_chars
    
    def execute(self):
        self.refresh()
        while True:
            # try to read
            try:
                currentcommand = self.code.read()
            except:
                break
            # execute read command 
            self.execute_command(currentcommand)
        if self.print_every_step:
            self.reprint()
        return 0




class BFCode(object):
    def __init__(self, code):
        self.code = code
        self.reader = 0
        self.obracs = ()
        self.cbracs = ()
        self.match_brackets()
    
    def read(self):
        return self.code[self.reader]
    
    def proceed(self):
        self.reader += 1
    
    def add_to_code(self, codetoadd):
        self.code += codetoadd
    
    def set_reader_at(self, loc):
        self.reader = loc
    
    def jump_to_match(self):
        try:
            self.set_reader_at(self.cbracs[self.obracs.index(self.reader)])
        except:
            try:
                self.set_reader_at(self.obracs[self.cbracs.index(self.reader)])
            except:
                return None
    
    def reset(self, code):
        if code != None:
            self.code = code
        else:
            pass
        self.match_brackets()
        self.reader = 0 
    
    def match_brackets(self):
        open_buffer = []
        matches = []
        open_brackets = []
        close_brackets = []
        for i in range(len(self.code)):
            if self.code[i] == '[':
                open_buffer.append(i)
            elif self.code[i] == ']':
                open_brackets.append(open_buffer.pop(-1)) 
                close_brackets.append(i)
        self.obracs = tuple(open_brackets)
        self.cbracs = tuple(close_brackets)
    
    def __repr__(self):
        expression = ''
        for c in self.code[ :self.reader ]:
            expression += ("%s" %(c))
        expression += emph(self.read())
        for c in self.code[ self.reader+1: ]:
            expression += ("%s" %(c))
        expression += '\n'
        return expression




class BFTape(object):
    def __init__(self, tapelength):
        self.tapelength = tapelength
        self.tape = [0] * tapelength
        self.pointer = 0
    
    def refresh(self):
        self.tape = [0] * self.tapelength
        self.pointer = 0
    
    def right(self):
        # moves the pointer 1 cell to the right.
        # bf command : >
        self.pointer += 1
    
    def left(self):
        # moves the pointer 1 cell to the left.
        # bf command : <
        self. pointer -= 1
    
    def incr(self):
        # increment the byte at the pointer.
        self.tape[ self.pointer ] += 1
    
    def decr(self):
        # decrement the byte at the pointer.
        self.tape[ self.pointer ] -= 1
    
    def accept(self, value):
        # accepts input, storing its value at the pointer
        self.tape[ self.pointer ] = value
    
    def read(self):
        return self.tape[ self.pointer ] 
    
    def __repr__(self):
        expression = ''
        for x in self.tape[ :self.pointer ]:
            expression += ("%d\t" %(x) )
        expression += emph(self.read())
        expression += "\t"
        for x in self.tape[ self.pointer+1: ]:
            expression += ("%d\t" %(x) )
        expression += '\n'
        return expression



class BFCommands(object):
    def __init__(self):
        self.right = '>'
        self.left  = '<'
        self.incr  = '+'
        self.decr  = '-'
        self.output= '.'
        self.accept= ','
        self.whileb= '['
        self.whilee= ']'
    
def emph(chars):
    return("\033[0;31m%s\033[0m" %(chars))


def hello_world():
   code = '++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.' 
   hellobf = BrainSth(10)
   hellobf.give_code(code)
   hellobf.execute()

if __name__ == '__main__':
    hello_world()
