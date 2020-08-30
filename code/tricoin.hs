
f x = floor (0.5 * ((sqrt (8 * x + 1)) -1))

main :: IO()
main = do
    a <- getContents
    putStrLn . unlines . map show $ [f (fromIntegral x) | x <-  map (read :: String -> Int) . drop 1  $ lines a]
