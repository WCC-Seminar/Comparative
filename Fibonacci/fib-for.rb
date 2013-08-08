#!/usr/bin/ruby

def fib(n)
  a,b = 1,1
  fibs = []
  (1..n).each do ||
    fibs << a
    a,b = b, a+b
  end
  return fibs
end

def main()
  print fib(50)
  puts ''
end

main()
