from typing import Union, Any

import numpy as np
import cmath


def fun(n, delta, beta, d, eta):
    zbir=0
    for i in range(0, n):
        fi = delta+(beta*d*np.cos(eta))
        ex = complex(0, fi*i)
        zbir += cmath.e**ex
    return zbir
def main():
    n = 5
    beta = 20*cmath.pi
    eta = cmath.pi/4
    d = 1/20
    x1 = 3.6
    x2 = 3.8
    x3 = 4.5
    while(1):
        arr1 = [[x1**2, x1, 1], [x2**2, x2, 1], [x3**2, x3, 1]]
        arr2 = [[abs(fun(n, x1, beta, d, eta))], [abs(fun(n, x2, beta, d, eta))], [abs(fun(n, x3, beta, d, eta))]]
        mat1 = np.array(arr1)
        mat2 = np.array(arr2)
        matf = np.matmul(np.linalg.inv(mat1), mat2)
        a = matf[0][0]
        b = matf[1][0]
        c = matf[2][0]
        xmax = (-b)/(2*a)
        fxmax=abs(fun(n, xmax, beta, d, eta))
        app=a*(xmax**2)+b*xmax+c
        if(abs(fxmax-app)<0.0000001):
            return xmax
        arrs = [x1, x2, x3, xmax]
        i = x1
        for j in arrs:
            if(abs(fun(n, j, beta, d, eta)) > abs(fun(n, i, beta, d, eta))):
                i = j
        arrs.remove(i)
        x1_n=i
        i = arrs[0]
        for j in arrs:
            if(abs(fun(n, j, beta, d, eta)) > abs(fun(n, i, beta, d, eta))):
                i = j
        arrs.remove(i)
        x2_n=i
        i = arrs[0]
        for j in arrs:
            if(abs(fun(n, j, beta, d, eta)) > abs(fun(n, i, beta, d, eta))):
                i = j
        arrs.remove(i)
        x1=x1_n
        x2=x2_n
        x3=i

if __name__ == "__main__":
    xmax=main()
    n = 5
    beta = 20*cmath.pi
    eta = cmath.pi/4
    d = 1/20
    print('Maksimum funkcije je: ', abs(fun(n, xmax, beta, d, eta)),'\n')
    print('X= ', xmax)