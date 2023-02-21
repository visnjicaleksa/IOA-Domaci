import copy
import random
import numpy as np
import matplotlib.pyplot as plt


def main():
    file = open('file.txt', 'r')
    x = []
    iks = np.arange(1, 1000001)
    sred = np.array([])
    for line in file:
        s = line.split()
        if (len(s) != 0):
            x.append(s)
    i = 1
    red = 0.0
    green = 0.0
    blue = 0.0
    for ar in x:
        niz2 = np.array(ar)
        niz = niz2.astype(float)
        if (i == 1):
            sred = np.copy(niz)
        else:
            for cnt in range(0, 1000000):
                sred[cnt] += niz[cnt]
        strl = "iteracija " + str(i)
        plt.plot(np.log10(iks), np.log10(niz), color=(red, green, blue), linewidth=3, linestyle="-", label=strl)
        plt.xlabel("Iteracija")
        plt.ylabel("Minimum")
        if (i < 5):
            red += 0.25
        elif (i < 9):
            blue += 0.25
        elif (i < 13):
            red -= 0.25
        elif (i < 17):
            green += 0.25
        else:
            blue -= 0.25
        i += 1
    plt.show()
    file.close()
    for cnt in range(0, 1000000):
        sred[cnt] /= 20
    plt.figure()
    plt.plot(np.log10(iks), np.log10(sred), color="red", linewidth=3, linestyle="-")
    plt.xlabel("Iteracija")
    plt.ylabel("Minimum")
    plt.show()


if __name__ == "__main__":
    main()