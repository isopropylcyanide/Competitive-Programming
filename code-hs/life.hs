
main :: IO()
main = do
        a <- getContents
        putStrLn . unlines . take (length . drop 1 $ lines a) $ cycle ["Alice"]
