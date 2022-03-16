--
-- EPITECH PROJECT, 2022
-- B-FUN-400-LIL-4-1-wolfram-thibault2.brumaire
-- File description:
-- Main
--

-- main module
module Main where

-- imports
import Args ( testNull, testRuleInArgs, testArgs, getSettings )
import Compute ( wolfram )
import System.Environment ( getArgs )
import System.Exit ( exitSuccess )

main :: IO ()
main = do
    args <- getArgs
    testNull args
    testRuleInArgs args
    testArgs args
    wolfram (getSettings args)
    exitSuccess
