sumupto n = foldl (+) 0 $ filter ismultiple [1..n]
    where
        ismultiple n = ( n `mod` 3 == 0 || n `mod` 5 == 0)

main = putStrLn $ show $ sumupto 999
