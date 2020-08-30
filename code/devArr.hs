solver :: Int ->  String
solver n
    | n  `mod` 6 == 0 = "Misha"
    | otherwise = "Chef"

main :: IO()
main = do
    arr <- getContents
    putStrLn . unlines . map solver . map (read :: String -> Int) . drop 1 $ lines arr
