#!/usr/bin/env bash

set -e

# BASH COLORS
green() { printf "\033[32m${1}\033[0m\n\n"; }
orange() { printf "\033[38;5;208m${1}\033[0m\n"; }
blue() { printf "\033[38;5;27m${1}\033[0m\n" ; }
purpl() { printf "\033[38;5;92m${1}\033[0m\n" ; }

green "Drawer bonus :"
if [ "$3" != "" ]; then
    ../106bombyx $1 $2 $3 > data
    cat drawer.gnu | gnuplot
else
    orange "3 numeric args required !"
    orange "Closing"
    exit 1;
fi
blue "Graph done"
blue "Provided by Thibault Brumaire - 2021 - Epitech Lille Promo 2025"