#!/usr/bin/ruby

def fib_tail(n, fibs)
  if n == 0
    return fibs
  elsif fibs.length == 0
    return fib_tail(n-1, [1])
  elsif fibs.length == 1
    return fib_tail(n-1, [1,1])
  else
    return fib_tail(n-1, fibs.push( fibs[-1] + fibs[-2]))
  end
end

def fib(n)
  return fib_tail(n, [])
end

def main()
  print fib(50)
  puts ''
end

main()
