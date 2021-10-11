#!/usr/bin/env bash
clear

set -e
# BASH COLORS
red() { printf "\033[38;5;196m${1}\033[0m\n"; }
green() { printf "\033[32m${1}\033[0m\n\n"; }
orange() { printf "\033[38;5;208m${1}\033[0m\n"; }
blue() { printf "\033[38;5;27m${1}\033[0m\n" ; }
purpl() { printf "\033[38;5;92m${1}\033[0m\n" ; }
yellow() { printf "\033[38;5;226m${1}\033[0m\n" ; }

if [ -z "$1" ]
then
    red "please provide a file path"
    exit 84
fi
yellow "ImageMagick and netpbm packages required !"
orange "generating map $1"
./../solver $1 > map_solved.txt
sed -i 's/o/M/g' "map_solved.txt"
asciitopgm $(wc -lL "map_solved.txt") | convert - "$1"".jpeg"
green "Done"
blue "Provided by Thibault Brumaire - 2020 - Epitech Lille Promo 2025"