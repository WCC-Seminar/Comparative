#!/usr/bin/ruby

def fib(n)
  if n == 1
    return [1]
  elsif n == 2
    return [1,1]
  else
    terms_before = fib(n-1)
    return  terms_before.push(terms_before[-1] + terms_before[-2])
  end
end

def main()
  print fib(50)
  puts ''
end

main()
