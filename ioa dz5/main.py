import random

import numpy as np
import matplotlib.pyplot as plt
from scipy import optimize


def izlaz_mreze(x,w):
    yout=w[15]
    for i in range(0,5):
        suma=w[i+10]
        ulaz=w[i]*x+w[i+5]
        suma*=np.tanh(ulaz)
        yout+=suma
    return yout

def trening(x):
    ytrening=-1
    zag=2*((np.sin(np.pi/2*(x+1)))**4+((np.sin(np.pi/2*((1-np.abs(np.cos(np.pi/4*(x+1))))**4)))**4)/4)
    ytrening+=zag
    return ytrening

def opt_fun(w):
    x=np.arange(-1,1.02,0.02)
    sum=0
    for i in x:
        sum+=(izlaz_mreze(i,w)-trening(i))**2
    sum/=101
    for i in w:
        if((i>5) or (i<-5)):
            sum+=300
            break
    return sum


def main():
    neww=np.array([])
    while(1):
        minimum = -25
        for i in range(0, 100):
             w = np.array([random.uniform(-5, 5), random.uniform(-5, 5), random.uniform(-5, 5), random.uniform(-5, 5),
                           random.uniform(-5, 5), random.uniform(-5, 5), random.uniform(-5, 5), random.uniform(-5, 5),
                           random.uniform(-5, 5), random.uniform(-5, 5), random.uniform(-5, 5), random.uniform(-5, 5),
                           random.uniform(-5, 5), random.uniform(-5, 5), random.uniform(-5, 5), random.uniform(-5, 5)])
             res=opt_fun(w)
             if((minimum==-25)or(minimum>res)):
                minimum=res
                neww=w
        w=neww
        res=minimum
        if (res < 1e-4):
            break

        k=1
        while(k):
            resu = optimize.minimize(opt_fun, w, method='nelder-mead')
            res = resu.fun
            if (resu.fun < 1e-4):
                w=resu.x
                break
            w = resu.x
            k=res<1e-3
        if (res < 1e-4):
            break

    print("Vrednost funkcije je: \n", res)
    for i in w:
        print(i, " ")
    plt.figure(figsize=(8, 6))
    x = np.arange(-1, 1.02, 0.02)
    arr=[]
    for i in x:
        arr.append(trening(i))
    plt.plot(x, arr, color="blue", linewidth=3, linestyle="-", label="Trening")
    arr = []
    for i in x:
        arr.append(izlaz_mreze(i, w))
    plt.plot(x, arr, color="red", linewidth=3, linestyle="-", label="Izlaz Mreze")
    plt.xlabel("X")
    plt.ylabel("F(x)")
    plt.legend()
    plt.show()
if __name__ == "__main__":
    main()