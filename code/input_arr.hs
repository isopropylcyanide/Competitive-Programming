--Given a list repeat each element of the list n times.

rep_n n x = take n $ repeat x

f :: Int -> [Int] -> [Int]
f n [] = []
f n (x:xs) =  rep_n n x ++ f n xs

-- This part handles the Input and Output and can be used as it is. Do not modify this part.
main :: IO ()
main = getContents >>=
       mapM_ print. (\(n:arr) -> f n arr). map read. words


--Filter a given array of integers and leave only that values which are less than a specified
--value X. The integers in the output should be in the same sequence as they were in the input.

f :: Int -> [Int] -> [Int]
f n arr = --Fill up this function
    [x | x<- arr, x<n]

-- The Input/Output section. You do not need to change or modify this part
main = do
    n <- readLn :: IO Int
    inputdata <- getContents
    let
        numbers = map read (lines inputdata) :: [Int]
    putStrLn . unlines $ (map show . f n) numbers


--For a given list with N integers, return a new list removing the elements at odd positions.

f :: [Int] -> [Int]
f lst = -- Fill up this Function
    [y | (x,y) <- zip [0..] lst , x `mod` 2 /=0 ]

-- This part deals with the Input and Output and can be used as it is. Do not modify it.
main = do
   inputdata <- getContents
   mapM_ (putStrLn. show). f. map read. lines $ inputdata





--Reverse a list without using the reverse function
rev [] = []
rev l = [last l] ++ rev (init l)


--Return sum of odd elements from an list.
f arr = -- Fill up this function body
        sum [x | x <-arr , x `mod` 2 /= 0]
-- This part handles the Input/Output and can be used as it is. Do not change or modify it.
main = do
   inputdata <- getContents
   putStrLn $ show $ f $ map (read :: String -> Int) $ lines inputdata


--Print length of a list without length | size
len :: [a] -> Int
len [] = 0
len lst = 1 + len (init lst)


--The series expansion of ex is given by:
--1 + x + x2/2! + x3/3! + x4/4! + .......
--Evaluate e^x for given values of x, by using the above expansion for the first 10 terms.
fact :: Double  -> Double
fact n = foldl (*) 1 [1..n]

solve :: Double -> Double
solve x = sum [x**i/fact (i) | i<- [0.0..9]]

main :: IO ()
main = getContents >>= mapM_ print. map solve. map (read::String->Double). tail. words



--GCD of two numbers
module Main where


gcd' :: Integral a => a -> a -> a
gcd' n 0 = n
gcd' n m = gcd m $ n `mod` m


-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
  input <- getLine
  print . uncurry gcd' . listToTuple . convertToInt . words $ input
 where
  listToTuple (x:xs:_) = (x,xs)
  convertToInt = map (read :: String -> Int)


--Fibonacci Sequence-> Nth fibonacci number
--Contributed by Ron Watkins
module Main where

fib 1 = 0
fib 2 = 1
fib n = fib (n-1) + fib (n-2)


-- This part is related to the Input/Output and can be used as it is
-- Do not modify it
main = do
    input <- getLine
    print . fib . (read :: String -> Int) $ input


--For a given integer K, print the first K rows of Pascal's Triangle.
--Print each row with values separated by spaces. The value at nthrow
--and rth column of the triangle is equal to n! / (r! * (n-r)!)

f :: Int -> Int
f n = product [1..n]

ncr :: Int -> Int -> Int
ncr n r = f n `div` f (n-r) `div` f r

pasc row = do
    let a = [ [ncr y x | x <- [0..y] ] | y <- [0..row-1] ]
    putStr $ unlines $map (unwords. map show) a

main = do
    input <- getLine
    pasc . (read :: String -> Int) $ input


--Mingle two strings entered by the user
