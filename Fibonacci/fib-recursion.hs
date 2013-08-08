fib :: Integral a => Int -> [a]

fib 1 = [1]
fib 2 = [1,1]
fib n = (head(fib (n-1)) + (head.tail.fib) (n-1)  : (fib (n-1)))

main = putStrLn $ show $ (reverse.fib) 20
