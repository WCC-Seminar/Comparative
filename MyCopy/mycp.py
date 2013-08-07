#!/usr/bin/python
import os
import sys

def mycp(fromfile,tofile):
    if not os.path.isfile(fromfile):
        # Checks if a file fromfile exists.
        print "file %s not found, or is a directory or something. Abort."%(fromfile)
        # I could've called raise IOError, but I didn't want to mess it up.
        return 0
    else:
        try:
            fr = file(fromfile,'r')
            data = fr.read()
            fr.close() 
        except:
            print "Can't read the file (maybe permission denied). Abort."
            return 0
        # input file read. Now write the data to the specified file.

        if os.path.isfile(tofile):
            print ("%s already exists. Overwrite? [Y/n]"%(tofile))
            your_command = raw_input(" > ")
            if your_command != 'Y':
                print ("Abort.")
                return 0

        # when fromfile doesn't exists yet or You said 'yes, overwrite it.'
        fw = file(tofile,'w')
        fw.write(data)
        fw.close() 

        
def main():
    try:
        fromfile = sys.argv[1]
        tofile = sys.argv[2]
    except:
        print ("Please specify TWO files. Abort.")
        return 0
    mycp(fromfile,tofile)


if __name__ == '__main__':
    main()
