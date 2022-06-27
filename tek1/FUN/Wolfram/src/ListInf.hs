--
-- EPITECH PROJECT, 2022
-- B-FUN-400-LIL-4-1-wolfram-thibault2.brumaire
-- File description:
-- ListInf
--

-- ListInf module
module ListInf where

-- Imports
import Prelude hiding (map, iterate, take, repeat)

-- Types
data ListInf a = a ::: (ListInf a)

instance Functor ListInf where
    fmap = map

-- Functions
map :: (a -> b) -> ListInf a -> ListInf b
map f (x ::: xs) = f x ::: map f xs

iterate :: (a -> a) -> a -> ListInf a
iterate f x = x ::: iterate f (f x)

(+++) :: [a] -> ListInf a -> ListInf a
[] +++ xs = xs
(x:xs) +++ ys = x ::: (xs +++ ys)

take :: Int -> ListInf a -> [a]
take n (x ::: xs)
    | n <= 0 = []
    | otherwise = x : take (n - 1) xs

repeat :: a -> ListInf a
repeat x = x ::: repeat x