import numpy as np
import matplotlib.pyplot as plt

def main():
    file = open('file.txt', 'r')
    x = []
    for line in file:
        s = line.split()
        if (len(s) != 0):
            x.append(s)
    H=np.array(x[0])
    r=np.array(x[1])
    pf=np.array(x[2])
    H = H.astype(float)
    r = r.astype(float)
    pf = pf.astype(int)
    plt.scatter(H, r, color="blue")
    Hp=[]
    rp=[]
    for i in pf:
        Hp.append(H[i])
        rp.append(r[i])
    Hp=np.array(Hp)
    rp=np.array(rp)
    plt.scatter(Hp,rp,color="red")
    plt.xlabel("H")
    plt.ylabel("r")
    plt.show()

if __name__ == "__main__":
    main()