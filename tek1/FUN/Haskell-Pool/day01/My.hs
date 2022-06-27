--
-- EPITECH PROJECT, 2022
-- Documents
-- File description:
-- My.hs
--

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x = if myIsNeg x then -x else x

myMin :: Int -> Int -> Int
myMin x y = if x < y then x else y

myMax :: Int -> Int -> Int
myMax x y = if x > y then x else y

myTuple :: a -> b -> (a, b)
myTuple x y = (x, y)

myTruple :: a -> b -> c -> (a , b , c )
myTruple x y z = (x, y, z)

myFst :: (a , b) -> a
myFst (x, y) = x

mySnd :: (a , b) -> b
mySnd (x, y) = y

mySwap :: (a , b) -> (b , a)
mySwap (x, y) = (y, x)

myHead :: [a] -> a
myHead [] = error "myHead: empty list"
myHead (x:_) = x

myTail :: [a] -> [a]
myTail [] = error "myTail: empty list"
myTail (_:x) = x

myLength :: [a] -> Int
myLength [] = 0
myLength (_:l) = myLength l + 1 

myNth :: [a] -> Int -> a
myNth [] _ = error "myNth: index out of bounds"
myNth (x:xs) 0 = x
myNth (x:xs) n = myNth xs (n - 1)

myTake :: Int -> [a] -> [a]
myTake 0 _ = []
myTake _ [] = []
myTake n (x:xs) = x : myTake (n - 1) xs

myDrop :: Int -> [a] -> [a]
myDrop 0 xs = xs
myDrop _ [] = []
myDrop n (_:xs) = myDrop (n - 1) xs

myAppend :: [a] -> [a] -> [a]
myAppend [] ys = ys
myAppend x y = myHead x : myAppend (myTail x) y

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

myInit :: [a] -> [a]
myInit [] = error "myInit: empty list"
myInit (x:xs) = if myLength xs == 0 then [] else x : myInit xs

myLast :: [a] -> a
myLast [] = error "myLast: empty list"
myLast (x:xs) = if myLength xs == 0 then x else myLast xs

myZip :: [a] -> [b] -> [(a, b)]
myZip [] _ = []
myZip _ [] = []
myZip (x:xs) (y:ys) = (x, y) : myZip xs ys

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip x = (myMap myFst x, myMap mySnd x)

myMap :: (a -> b) -> [a] -> [b]
myMap g [] = []
myMap g (x:xs) = g x : myMap g xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter g [] = []
myFilter g (x:xs) = if g x then x : myFilter g xs else myFilter g xs

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl g b [] = b
myFoldl g b (x:xs) = myFoldl g (g b x) xs

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr g b [] = b
myFoldr g b (x:xs) = g x (myFoldr g b xs)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition g [] = ([], [])
myPartition g x = (myFilter g x, myNotFilter g x)

myNotFilter :: (a -> Bool) -> [a] -> [a]
myNotFilter g [] = []
myNotFilter g (x:xs) = if g x then myNotFilter g xs else x : myNotFilter g xs

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort p (x:xs) = myAppend (myAppend(myQuickSort p (myHelper p x xs)) [x])
    (myQuickSort p (myHelp p x xs))

myHelp :: (a -> a -> Bool) -> a -> [a] -> [a]
myHelp _ _ [] = []
myHelp p n (x:xs) = if (p n x) then x : myHelp p n xs else myHelp p n xs

myHelper :: (a -> a -> Bool) -> a -> [a] -> [a]
myHelper _ _ [] = []
myHelper p n (x:xs) = if (p n x) then myHelper p n xs else x : myHelper p n xs