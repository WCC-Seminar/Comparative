sum_of_multiples :: Int -> Int
sum_of_multiples n 
    | n <= 0      = 0
    | ismultiple  = sum_of_multiples (n-1) + n
    | otherwise   = sum_of_multiples (n-1)
        where
        ismultiple = (mod n 3 == 0 || mod n 5 == 0)

answer = sum_of_multiples 999

main = putStrLn $ show answer
