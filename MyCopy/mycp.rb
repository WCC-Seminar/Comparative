#!/usr/bin/ruby

def mycp(fromfile, tofile)
  # checks if a file fromfile exists.
  if not File.exists? fromfile
    puts "File #{fromfile} not found. Abort."
    return
  else
    begin 
      # tries to read data
      fr = File.open(fromfile,'r')
      data = fr.read()
      fr.close()
    rescue
      puts "Can't read the file (maybe permission denied). Abort."
      return 
    end

    # writes data
    if File.exists? tofile
      puts "File #{tofile} already exists. Overwrite? [Y/n]"
      print ('> ')
      yourcommand = STDIN.gets.chomp()
      if yourcommand != 'Y'
        puts "Abort."
        return
      end
    end

    # if tofile doesn't exist or you said 'ok, overwrite.'
    fw = File.open(tofile,'w')
    fw.write(data)
    fw.close()
  end
end


def main()
  fromfile, tofile = ARGV
  mycp(fromfile,tofile)
end

main()
