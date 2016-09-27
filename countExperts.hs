

main :: IO()
main = do
    arr <-  getContents
    let n = length . filter (\x -> x >= 1600 && x <= 1900) . map (read :: String -> Int) . words . unwords . drop 1 $ lines arr
    print n
