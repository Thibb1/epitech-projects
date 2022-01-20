--
-- EPITECH PROJECT, 2022
-- Documents
-- File description:
-- Tree.hs
--

data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show, Eq)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree a Empty = Node Empty a Empty
addInTree a (Node l y r)
    | a < y = Node (addInTree a l) y r
    | otherwise = Node l y (addInTree a r)

instance Functor Tree where
    fmap _ Empty = Empty
    fmap g (Node l y r) = Node (fmap g l) (g y) (fmap g r)

listToTree :: Ord a => [a] -> Tree a
listToTree = foldr addInTree Empty

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node l y r) = treeToList l ++ [y] ++ treeToList r

treeSort :: Ord a => [a] -> [a]
treeSort a = treeToList (listToTree a)

instance Foldable Tree where
    foldMap _ Empty = mempty
    foldMap f (Node l y r) = foldMap f l <> f y <> foldMap f r