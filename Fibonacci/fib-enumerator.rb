#!/usr/bin/ruby

Fib_seqs = Enumerator.new do |fibs|
  a,b = 1,1
  loop do
    fibs.yield a
    a, b = b, a+b
  end
end

def fib(n)
  return Fib_seqs.take(n)
end

def main()
  print fib(50)
  puts ''
end

main()
