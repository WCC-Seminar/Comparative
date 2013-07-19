sumuptotail :: Integer -> Integer -> Integer
sumuptotail 0 m = m
sumuptotail n m 
    | (n `mod` 3 == 0 || n `mod` 5 == 0 )   = sumuptotail (n-1) (m+n)
    | otherwise = sumuptotail (n-1) m

sumupto :: Integer -> Integer
sumupto n = sumuptotail n 0

main = putStrLn $ show (sumupto 999)
