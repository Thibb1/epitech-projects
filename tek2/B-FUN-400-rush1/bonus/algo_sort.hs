--
-- EPITECH PROJECT, 2022
-- Documents
-- File description:
-- algo_sort.hs
--
import System.Random ( Random(randomR), StdGen, newStdGen )
import Data.List ( unfoldr )

randomList :: Int -> StdGen -> [Int]
randomList n = take n . unfoldr (Just . randomR (0, 10000))

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [x] = True
isSorted (x:y:xs) = x <= y && isSorted (y:xs)

mySort :: ([Int], [Int]) -> Bool -> ([Int], [Int])
mySort (x, []) _ = if isSorted x then (x, []) else mySort (pb (x,[])) True
mySort ([], y) True = mySort (pa ([], y)) False
mySort (x, y) True = mySort (sortToBStack (x, y)) True
mySort (x, y) False = mySort (sortToAStack (x, y)) False

sortToBStack :: ([Int], [Int]) -> ([Int], [Int])
sortToBStack (x, y:z:ys)
    | head x > y = pb (x, y:z:ys)
    | head x < last (z:ys) = rb $ pb (x, y:z:ys)
    | abs (last (z:ys) - head x) > abs (y - head x) = sb $ pb (x, y:z:ys)
    | otherwise = rb $ rb $ sb $ rrb $ pb (x, y:z:ys)
sortToBStack x
    | head (snd x) > head (fst x) = rb $ pb x
    | otherwise = pb x

sortToAStack :: ([Int], [Int]) -> ([Int], [Int])
sortToAStack (x:z:xs, y)
    | head y < x = pa (x:z:xs, y)
    | head y > last (z:xs) = ra $ pa (x:z:xs, y)
    | abs (last (z:xs) - head y) > abs (head y - x) = sa $ pa (x:z:xs, y)
    | otherwise = ra $ ra $ sa $ rra $ pa (x:z:xs, y)
sortToAStack x
    | head (fst x) > head (snd x) = pa x
    | otherwise = ra $ pa x


sa :: ([Int],[Int]) -> ([Int],[Int])
sa (x:z:xs, y) = (z:x:xs, y)
sa (x, y) = (x, y)

sb :: ([Int],[Int]) -> ([Int],[Int])
sb (x, y:z:ys) = (x, z:y:ys)
sb (x, y) = (x, y)

pa :: ([Int], [Int]) -> ([Int], [Int])
pa (x, y:ys) = (y:x, ys)
pa (x, y) = (x, y)

pb :: ([Int], [Int]) -> ([Int], [Int])
pb (x:xs, y) = (xs, x:y)
pb (x, y) = (x, y)

ra :: ([Int], [Int]) -> ([Int], [Int])
ra (x:xs, y) = (tail (x:xs) ++ [head (x:xs)], y)
ra (x, y) = (x, y)

rb :: ([Int], [Int]) -> ([Int], [Int])
rb (x, y:ys) = (x, tail (y:ys) ++ [head (y:ys)])
rb (x, y) = (x, y)

rra :: ([Int], [Int]) -> ([Int], [Int])
rra (x:xs, y) = (last (x:xs) : init (x:xs), y)
rra (x, y) = (x, y)

rrb :: ([Int], [Int]) -> ([Int], [Int])
rrb (x, y:ys) = (x, last (y:ys) : init (y:ys))
rrb (x, y) = (x, y)

main :: IO ()
main = do
    gen <- newStdGen
    let list = randomList 100 gen
    let sorted = mySort (list, []) True
    putStrLn "unsorted list: "
    print list
    putStrLn "sorted list: "
    print (fst sorted)
    putStr "is sorted: "
    print (isSorted (fst sorted))