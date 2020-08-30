

import           Control.Monad

-- f :: [Int] -> [Int] -> Int -> Int -> (Int, Int)
f [] [] a b = (a, b)
f [x] [y] a b = (x + b, y + a)
f (x:y:xs) (a:b:as) c d = f xs as (c + x + b) (d + y + a)

main :: IO()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $  \_ -> do
        n <- readLn :: IO Int
        a <- getLine
        let b = 0 :: Int
        let xenny = map (read :: String -> Int) $ words a
        let yana = map (read :: String -> Int) $ words a
        print . minimum $ f xenny yana b b
