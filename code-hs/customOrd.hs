import           Control.Monad
import           Data.List

comparator :: (Ord a, Num a) => a -> a -> Ordering
comparator a b
    | abs(a) < abs (b) = LT
    | otherwise = GT

main :: IO()
main = do
    a <- getContents
    let arr = map read $ words . unwords . drop 1 $ lines a :: [Int]
    putStrLn . unwords $ map show (sortBy comparator arr)
