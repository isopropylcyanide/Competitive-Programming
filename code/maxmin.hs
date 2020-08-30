import           Control.Monad

solver :: IO()
solver = do
        n <- readLn :: IO Int
        arr_temp <- getLine
        let arr = map read $ words arr_temp :: [Int]
        putStrLn $ show $ subtract (minimum arr) (maximum arr)

main :: IO()
main = do
        tests <- readLn :: IO Int
        replicateM_ tests solver
