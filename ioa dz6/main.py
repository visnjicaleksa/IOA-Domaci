import numpy as np
import math
import scipy.optimize as opt

def opt_fun(x11,x12,x13,x14,x21,x22,x23,x24,x31,x32,x33,x34):
    return 10*x11+8*x12+6*x13+9*x14+18*x21+20*x22+15*x23+17*x24+15*x31+16*x32+13*x33+17*x34;

def main():
    f=np.array([10,8,6,9,18,20,15,17,15,16,13,17])
    a=np.array([[1,1,1,1,0,0,0,0,0,0,0,0],[0,0,0,0,1,1,1,1,0,0,0,0],[0,0,0,0,0,0,0,0,1,1,1,1],[5,0,0,0,6,0,0,0,13,0,0,0],[0,7,0,0,0,12,0,0,0,14,0,0],[0,0,4,0,0,0,8,0,0,0,9,0],[0,0,0,10,0,0,0,15,0,0,0,17]])
    b=np.array([1000,600,500,2880,2880,2880,2880])
    res=opt.linprog(-f, a, b, method='simplex')
    x0=res.x
    x=[]
    for i in x0:
        x.append(round(i))
    dali=0
    x=np.array(x)
    p=np.matmul(a,x)
    dali=1
    for i in range(0,len(b)):
        if(p[i]>b[i]):
            dali=0
    if(dali==0):
        x=[]
        for i in x0:
            x.append(math.floor(i))
    z=0
    for i in x:
        print(i," ")
    z=opt_fun(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9],x[10],x[11])
    print("\nUkupna zarada je: ",z)
if __name__ == "__main__":
    main()