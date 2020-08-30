import           Data.List

solver :: [Int] -> [Int] -> Int
solver [] [] = 0
solver (x: xs) (y : ys) = if x /= y then 1 + solver xs ys
                        else solver xs ys

main :: IO()
main = do
    arr <- map (read :: String -> Int) . words <$> getLine
    print $ solver arr (sort arr)
