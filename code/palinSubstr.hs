
import           Control.Monad
import           Data.List


listIntersect :: String -> String -> IO()
listIntersect a b = do
    if (length $ intersect a b) == 0
        then putStrLn "No"
        else putStrLn "Yes"

main :: IO()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $  \_ -> do
        a <- getLine
        b <- getLine
        listIntersect a b
