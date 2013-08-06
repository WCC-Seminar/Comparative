#!/usr/bin/ruby
# generates a table of primes <=N.

N = 10000 # upper cases for global variable (language specification)
def sieve(n)
    table = [false, false] + [true]* (n-1) 
    # [0(not prime), 1(not prime), 2 (not sure yet)..]
    for i in (1..n)
        if table[i]
            upto = n/i
            for j in (i..upto)
                table[i*j] = false
            end
        end
    end # I don't like all the end-s written down like this.

    # now making a list of primes out of those trues and falses. 
    list_of_primes = []
    for i in (1..n)
        if table[i]
            list_of_primes.push(i)
        end
    end 

    return list_of_primes
end


def print_sieve(n)
    list_of_primes = sieve(n)
    puts "list of primes upto #{n}:"
    list_of_primes.each do |p| # same as 'for p in list_of_primes'
        print "#{p}, "
    end
    puts ''  #clear line
end


# execution 
print_sieve(N) 
