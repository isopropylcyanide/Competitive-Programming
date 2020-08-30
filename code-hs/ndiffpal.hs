
solver :: Int -> String
solver n = take n $ cycle ['a'..'z']

main :: IO()
main = do
    a <- getContents
    putStrLn . unlines . map solver . map (read :: String -> Int) . drop 1 $ lines a
