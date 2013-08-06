#!/usr/bin/ruby

def sumupto(n)
    answer = 0
    (1..n).each do |i|
        if i%3 == 0 or i%5 ==0
            answer += i
        end
    end
    return answer
end

# execution
puts sumupto(999)
