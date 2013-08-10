sieve_t (p:[]) primes = p:primes
sieve_t (p:ns) primes = sieve_t reducedTable ((p):primes)
    where
        reducedTable = reduceMultiples ns p

reduceMultiples :: (Integral a) => [a] -> a -> [a]
reduceMultiples table p = table `setminus` [p*p, p*(p+1) .. maximum(table)]

-- setminus for two sorted lists (not sure if haskell has a built-in function)
setminus [] _  = []
setminus xs  [] = xs
setminus (x:xs) (y:ys) 
    | x < y     = x:(setminus xs (y:ys))
    | x == y    = setminus xs ys
    | x > y     = setminus (x:xs) ys
    

sieve_upto n = sieve_t [2..n] []

main = putStrLn $ show $ (reverse.sieve_upto) 1000

{- note for (my) future reference
sieve_t table primes = sieve_t ( reduced table ) ((head table):primes)
    where 
        reduced (x:xs) = filter ( \ n -> (n `mod` x /= 0)) xs
        reduced (x:xs) = filter (notMultiplesOf x (maximum xs )) xs 
        notMultiplesOf x examinee uplimit = notElem examinee [x*x, x*(x+1)..uplimit]
    -}
