#!/usr/bin/ruby

def sumbelow(n)
  return ((1..n).select {|i| i%3 == 0 or i%5 ==0}).reduce(0,:+) 
  # 0 in reduce(0,:+) is optional.
  # or this should work too: 
  # ((1..n).select {|i| i%3==0 or i%5 ==0}).inject {|sum,j| sum+j}
end

# execution
puts sumbelow(999)
