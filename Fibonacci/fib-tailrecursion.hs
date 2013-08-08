fibTail :: Integral a => Int -> [a] -> [a]

fibTail 0 fibs  = fibs
fibTail n []    = fibTail (n-1) [1]
fibTail n [1]   = fibTail (n-1) [1,1]
fibTail n (first:second:fibs) = fibTail  (n-1) ((first+second):first:second:fibs)

fib :: Integral a => Int -> [a]
fib n = fibTail n []

main = putStrLn $ show $ (reverse.fib) 50
-- MUCH faster!
