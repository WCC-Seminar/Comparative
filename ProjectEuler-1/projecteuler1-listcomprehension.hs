sumupto :: (Integral a) => a -> a
sumupto n = sum [m | m <- [1..n], m `mod` 3 == 0 || m `mod` 5 ==0]

main = putStrLn $ show $ sumupto 999

