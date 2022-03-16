--
-- EPITECH PROJECT, 2022
-- B-FUN-400-LIL-4-1-wolfram-thibault2.brumaire
-- File description:
-- Args
--

-- Arguments handling module
module Args where

-- Imports
import System.IO ( stderr, hPutStrLn )
import System.Exit ( exitWith, ExitCode(ExitFailure) )
import Text.Read ( readMaybe )

-- Types
data Settings = Settings { rId :: Int, start :: Int, nbLines :: Int,
    width :: Int, move :: Int } deriving (Show)

-- Exit with error message
throw :: String -> IO ()
throw msg = hPutStrLn stderr msg >> exitWith (ExitFailure 84)

-- Check arguments input
isInt :: String -> Bool
isInt a = case readMaybe a :: Maybe Int of
    Just _ -> True
    Nothing -> False

isPos :: String -> Bool
isPos a = case readMaybe a :: Maybe Int of
    Just x -> x >= 0
    Nothing -> False

testNull :: [String] -> IO ()
testNull [] = throw "Usage: ./wolfram --rule n (...)"
testNull _ = return ()

--Settings getters
getSettings :: [String] -> Settings
getSettings args = Settings {
    rId = getId args,
    start = getStart args,
    nbLines = getLines args,
    width = getWindow args,
    move = getMove args
}

getId :: [String] -> Int
getId ("--rule":"30":_) = 30
getId ("--rule":"90":_) = 90
getId ("--rule":"110":_) = 110
getId (_:xs) = getId xs
getId _ = 30

getStart :: [String] -> Int
getStart ("--start":x:_) = 1 + read x :: Int
getStart (_:xs) = getStart xs
getStart _ = 1

getLines :: [String] -> Int
getLines ("--lines":x:_) = read x :: Int
getLines (_:xs) = getLines xs
getLines _ = -1


getWindow :: [String] -> Int
getWindow ("--window":x:_) = read x :: Int
getWindow (_:xs) = getWindow xs
getWindow _ = 80

getMove :: [String] -> Int
getMove ("--move":x:_) = read x :: Int
getMove (_:xs) = getMove xs
getMove _ = 0

-- Settings checkers
testArgs :: [String] -> IO ()
testArgs [] = return ()
testArgs ("--rule":xs) = testRule xs
testArgs ("--start":xs) = testStart xs
testArgs ("--lines":xs) = testLines xs
testArgs ("--window":xs) = testWindow xs
testArgs ("--move":xs) = testMove xs
testArgs _ = throw "Usage: ./wolfram --rule (30|90|110) (...)"

testRuleInArgs :: [String] -> IO ()
testRuleInArgs ("--rule":xs) = return ()
testRuleInArgs (_:xs) = testRuleInArgs xs
testRuleInArgs _ = throw "Usage: ./wolfram --rule (30|90|110) (...)"

testRule :: [String] -> IO ()
testRule ("30":xs) = testArgs xs
testRule ("90":xs) = testArgs xs
testRule ("110":xs) = testArgs xs
testRule _ = throw "Rule must be 30, 90 or 110"

testStart :: [String] -> IO ()
testStart (x:xs)
    | isInt x && isPos x = testArgs xs
    | otherwise = throw "Start must be a positive integer"
testStart _ = throw "Start must be a positive integer"

testLines :: [String] -> IO ()
testLines (x:xs)
    | isInt x && isPos x = testArgs xs
    | otherwise = throw "Lines must be a positive integer"
testLines _ = throw "Lines must be a positive integer"

testWindow :: [String] -> IO ()
testWindow (x:xs)
    | isInt x && isPos x = testArgs xs
    | otherwise = throw "Window must be a positive integer"
testWindow _ = throw "Window must be a positive integer"

testMove :: [String] -> IO ()
testMove (x:xs)
    | isInt x = testArgs xs
    | otherwise = throw "Move must be an integer"
testMove _ = throw "Move must be an integer"