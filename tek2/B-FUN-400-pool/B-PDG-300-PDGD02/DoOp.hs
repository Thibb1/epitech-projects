--
-- EPITECH PROJECT, 2022
-- Documents
-- File description:
-- DoOp.hs
--
import System.Environment
import System.Exit (exitWith, ExitCode (ExitFailure))

myElem :: Eq a => a -> [a] -> Bool
myElem n [] = False
myElem n (x:xs)
    | n == x = True
    | otherwise = myElem n xs

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv x y = Just (x `div` y)

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (x:xs) 0 = Just x
safeNth (x:xs) n = safeNth xs (n - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just x) = Just (x + 1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup n (x:xs)
    | fst x == n = Just (snd x)
    | otherwise = myLookup n xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo _ Nothing _ = Nothing
maybeDo _ _ Nothing = Nothing
maybeDo g (Just a) (Just b) = Just (g a b)

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt c = if myIsSigned c False then Just (read c :: Int) else Nothing

myIsDigit :: Char -> Bool
myIsDigit c = myElem c ['0' .. '9']

getLineLength :: IO Int
getLineLength = length <$> getLine

printAndGetLength :: String -> IO Int
printAndGetLength s = putStrLn s >> return (length s)

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox n
    | n <= 0 = return ()
    | otherwise =
        putStrLn ("+" ++ replicate (n * 2 - 2) '-' ++ "+") >>
        myPrintNString (n - 2) ("|" ++ replicate (n * 2 - 2) ' ' ++ "|") >>
        putStrLn ("+" ++ replicate (n * 2 - 2) '-' ++ "+")

myPrintNString :: Int -> String -> IO ()
myPrintNString n s
    | n <= 0 = return ()
    | otherwise = putStrLn s >> myPrintNString (n-1) s

concatLines :: Int -> IO String
concatLines n
    | n <= 0 = return ""
    | otherwise = do
        c <- getLine
        str <- concatLines (n - 1)
        return (c ++ str)

getInt :: IO (Maybe Int)
getInt = readInt <$> getLine

myIsSigned :: [Char] -> Bool -> Bool
myIsSigned [] _ = False
myIsSigned ('-':xs) False = myIsSigned xs True
myIsSigned c _ = all myIsDigit c

getNb :: [Char] -> Maybe Int
getNb [] = Nothing
getNb str
    | myIsSigned str False = Just (read str :: Int)
    | not (myIsSigned str False) = Nothing
    | otherwise = Nothing

checkOp :: String -> Maybe Int -> Bool
checkOp op Nothing = False
checkOp "+" _ = True
checkOp "*" _ = True
checkOp "-" _ = True
checkOp "/" (Just 0) = False
checkOp "%" (Just 0) = False
checkOp "/" _ = True
checkOp "%" _ = True
checkOp _ _ = False

doOp :: String -> Maybe Int -> Maybe Int -> IO()
doOp op Nothing _ = exitWith (ExitFailure 84)
doOp op _ Nothing = exitWith (ExitFailure 84)
doOp "+" (Just a) (Just b) = print (a + b)
doOp "-" (Just a) (Just b) = print (a - b)
doOp "*" (Just a) (Just b) = print (a * b)
doOp "/" (Just a) (Just b) = print (a `div` b)
doOp "%" (Just a) (Just b) = print (a `mod` b)
doOp _ _ _ = exitWith (ExitFailure 84)

main :: IO ()
main = do
    args <- getArgs
    if length args == 3 
        then checkArgs (args !! 0) (args !! 1) (args !! 2)
        else exitWith (ExitFailure 84)

checkArgs :: String -> String -> String -> IO()
checkArgs [] _ _ = exitWith (ExitFailure 84)
checkArgs _ _ [] = exitWith (ExitFailure 84)
checkArgs _ [] _ = exitWith (ExitFailure 84)
checkArgs a op b = if checkOp op (getNb b)
    then doOp op (getNb a) (getNb b) 
    else exitWith (ExitFailure 84)