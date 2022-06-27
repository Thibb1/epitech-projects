--
-- EPITECH PROJECT, 2022
-- rush1
-- File description:
-- pushswap_checker
--

-- Imports
import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode (ExitFailure))

-- Main function
main :: IO()
main = do
    nb <- getArgs
    op <- getLine
    if not (null nb) && checkInput nb op
        then printSorted $ pushswap (convertArgs nb, []) (split op)
        else exitWith (ExitFailure 84)

-- Parse a string into a list of string, cutting it by spaces
split :: String -> [String]
split [] = [[]]
split str = takeWhile (/= ' ') str :
    split (dropWhile (== ' ') $ dropWhile (/= ' ') str)

-- Check if the input is valid
checkInput :: [String] -> String -> Bool
checkInput nb op = checkSignedInt nb && checkOp (split op)

-- Check if the operators are valid
checkOp :: [String] -> Bool
checkOp [[]] = True
checkOp ("sa":xs) = checkOp xs
checkOp ("sb":xs) = checkOp xs
checkOp ("sc":xs) = checkOp xs
checkOp ("pa":xs) = checkOp xs
checkOp ("pb":xs) = checkOp xs
checkOp ("ra":xs) = checkOp xs
checkOp ("rb":xs) = checkOp xs
checkOp ("rr":xs) = checkOp xs
checkOp ("rra":xs) = checkOp xs
checkOp ("rrb":xs) = checkOp xs
checkOp ("rrr":xs) = checkOp xs
checkOp _ = False

-- False or True on wether the Char is a integer
isInt :: Char -> Bool
isInt c = c `elem` ['0' .. '9']

-- False or True on wether the String can be a signed int
isSignedInt :: String -> Bool -> Bool
isSignedInt [] _ = True
isSignedInt ('-':xs) True = isSignedInt xs False
isSignedInt s _ = all isInt s

-- Convert arguments into a list of int, return nothing if all aren't signed int
checkSignedInt :: [String] -> Bool
checkSignedInt [] = True
checkSignedInt (x:xs) = isSignedInt x True && checkSignedInt xs

convertArgs :: [String] -> [Int]
convertArgs [] = []
convertArgs list = map read list

pushswap :: ([Int], [Int]) -> [String] -> ([Int], [Int])
pushswap lists [[]] = lists
pushswap lists ("sa":xs) = pushswap (sa lists) xs
pushswap lists ("sb":xs) = pushswap (sb lists) xs
pushswap lists ("sc":xs) = pushswap (sc lists) xs
pushswap lists ("pa":xs) = pushswap (pa lists) xs
pushswap lists ("pb":xs) = pushswap (pb lists) xs
pushswap lists ("ra":xs) = pushswap (ra lists) xs
pushswap lists ("rb":xs) = pushswap (rb lists) xs
pushswap lists ("rr":xs) = pushswap (rr lists) xs
pushswap lists ("rra":xs) = pushswap (rra lists) xs
pushswap lists ("rrb":xs) = pushswap (rrb lists) xs
pushswap lists ("rrr":xs) = pushswap (rrr lists) xs
pushswap _ _ = ([],[])

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [x] = True
isSorted (x:y:xs) = x <= y && isSorted (y:xs)

printSorted :: ([Int], [Int]) -> IO()
printSorted (a, []) = if isSorted a
    then putStrLn "OK"
    else putStrLn "KO" >> exitWith (ExitFailure 84)
printSorted _ = putStrLn "KO" >> exitWith (ExitFailure 84)

---------------------
--- Actions functions
---------------------

-- "sa" swap the first two elements of l_a
-- (nothing will happen if there aren’t enough elements).
sa :: ([Int],[Int]) -> ([Int],[Int])
sa (x:z:xs, y) = (z:x:xs, y)
sa (x, y) = (x, y)
-- "sb" swap the first two elements of l_b
-- (nothing will happen if there aren’t enough elements).
sb :: ([Int],[Int]) -> ([Int],[Int])
sb (x, y:z:ys) = (x, z:y:ys)
sb (x, y) = (x, y)
-- "sc" sa and sb at the same time.
sc :: ([Int],[Int]) -> ([Int],[Int])
sc x = sa $ sb x

-- "pa" take the first element from l_b
-- move it to the first position on the l_a list 
-- (nothing will happen if l_b is empty).
pa :: ([Int], [Int]) -> ([Int], [Int])
pa (x, y:ys) = (y:x, ys)
pa (x, y) = (x, y)

-- "pb" take the first element from l_a
-- move it to the first position on the l_b list
-- (nothing will happen if l_a is empty).
pb :: ([Int], [Int]) -> ([Int], [Int])
pb (x:xs, y) = (xs, x:y)
pb (x, y) = (x, y)

-- "ra" rotate l_a toward the beginning
-- the first element will become the last.
ra :: ([Int], [Int]) -> ([Int], [Int])
ra (x:xs, y) = (tail (x:xs) ++ [head (x:xs)], y)
ra (x, y) = (x, y)

-- "rb" rotate l_b toward the beginning
-- the first element will become the last.
rb :: ([Int], [Int]) -> ([Int], [Int])
rb (x, y:ys) = (x, tail (y:ys) ++ [head (y:ys)])
rb (x, y) = (x, y)

-- "rr" rotate l_a and l_b toward the beginning
-- the first element of each list will become the last.
rr :: ([Int], [Int]) -> ([Int], [Int])
rr x = ra $ rb x

-- "rra" rotate l_a toward the end
-- the last element will become the first.
rra :: ([Int], [Int]) -> ([Int], [Int])
rra (x:xs, y) = (last (x:xs) : init (x:xs), y)
rra (x, y) = (x, y)

-- "rrb" rotate l_b toward the end
-- the last element will become the first.
rrb :: ([Int], [Int]) -> ([Int], [Int])
rrb (x, y:ys) = (x, last (y:ys) : init (y:ys))
rrb (x, y) = (x, y)

rrr :: ([Int], [Int]) -> ([Int], [Int])
rrr x = rra $ rrb x