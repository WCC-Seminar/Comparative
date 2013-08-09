#!/usr/bin/ruby

def sumupto(n, answer = 0)
  if n==0 then return answer
  elsif n % 3 == 0 or n % 5 == 0
    return sumupto(n-1, answer+n)
  else
    return sumupto(n-1, answer)
  end
end

# execution
puts sumupto(999)
