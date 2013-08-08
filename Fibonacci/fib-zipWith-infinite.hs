fibs = 1 : 1 : zipWith (+) fibs (tail fibs)

main = putStrLn $ show $ take 50 fibs
