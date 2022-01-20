#!/usr/bin/env python3
import math
import sys
import matrix as M

def exp(M1, precision, n):
    M2 = M.base(n)
    for x in range (1, precision):
        M3 = M.pow(M1, x)
        M3 = M.divide(M3, math.factorial(x))
        M2 = M.add(M2, M3)
    return M2

def cos(M1, precision, n):
    M2 = M.base(n)
    for x in range (1, precision):
        y = x * 2
        M3 = M.pow(M1, y)
        M3 = M.divide(M3, math.factorial(y))
        if x % 2 == 0:
            M2 = M.add(M2, M3)
        else:
            M2 = M.sub(M2, M3)
    return M2

def sin(M1, precision, n):
    M2 = M1
    for x in range (1, precision):
        y = x * 2 + 1
        M3 = M.pow(M1, y)
        M3 = M.divide(M3, math.factorial(y))
        if x % 2 == 0:
            M2 = M.add(M2, M3)
        else:
            M2 = M.sub(M2, M3)
    return M2

def cosh(M1, precision, n):
    M2 = M.base(n)
    for x in range (1, precision):
        y = x * 2
        M3 = M.pow(M1, y)
        M3 = M.divide(M3, math.factorial(y))
        M2 = M.add(M2, M3)
    return M2

def sinh(M1, precision, n):
    M2 = M1
    for x in range (1, precision):
        y = x * 2 + 1
        M3 = M.pow(M1, y)
        M3 = M.divide(M3, math.factorial(y))
        M2 = M.add(M2, M3)
    return M2