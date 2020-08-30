import           Data.Char

wrapCharLeft :: Char -> Char
wrapCharLeft x = chr $ 97 +(ord x - 97 -1) `mod` 26

solve :: String -> String
solve []  = []
solve ('a' : xs)  =
            if all (\x -> x == 'a') xs then
                (take (length xs)  $ cycle "a") ++ "z"
            else
                let
                conv = takeWhile (\x -> x/='a') xs
                noConv = dropWhile (\x -> x/='a') xs
                in ['a'] ++ (map wrapCharLeft conv) ++ noConv
-- No more conversions possible
solve (x: xs)  = let
            conv = takeWhile (\x -> x/='a') (x:xs)
            noConv = dropWhile (\x -> x/='a') (x:xs)
            in (map wrapCharLeft conv) ++ noConv


main :: IO()
main = do
    a <- getContents
    putStrLn . unlines .  map (\x -> solve x) . drop 1 $ lines a
