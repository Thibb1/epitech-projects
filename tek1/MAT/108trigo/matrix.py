#!/usr/bin/env python3
import math
import sys

def show(M):
    for y in range(len(M)):
        for x in range(len(M[y])):
            if len(M[y]) - 1 == x:
                print("%.2f" %M[y][x])
            else:
                print("%.2f\t" %M[y][x], end='')

def base(n):
    M2 = []
    for y in range(n):
        M2.append([])
        for x in range(n):
            M2[y].append(1 if y == x else 0)
    return M2

def add(M1, M2):
    M3 = []
    for y in range(len(M1)):
        M3.append([])
        for x in range(len(M1[y])):
            M3[y].append(M1[y][x] + M2[y][x])
    return M3

def sub(M1, M2):
    M3 = []
    for y in range(len(M1)):
        M3.append([])
        for x in range(len(M1[y])):
            M3[y].append(M1[y][x] - M2[y][x])
    return M3

def divide(M1, d):
    if d == 0:
        print("%s: error can't divide by zero. Try %s -h" %(sys.argv[0], sys.argv[0]))
        sys.exit(84)
    for y in range(len(M1)):
        for x in range(len(M1[y])):
            M1[y][x] /= d
    return M1

def product(M1, M2):
    M3 = []
    for y in range(len(M1)):
        M3.append([])
        for x in range(len(M2[y])):
            M3[y].append(0)
            for z in range(len(M1[y])):
                M3[y][x] += M1[y][z] * M2[z][x]
    return M3

def pow(M1, p):
    M2 = M1
    for _ in range(p - 1):
        M2 = product(M1, M2)
    return M2