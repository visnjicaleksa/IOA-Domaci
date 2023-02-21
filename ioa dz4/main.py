import numpy as np
import matplotlib.pyplot as plt
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
    delta = np.linspace(0, 2*cmath.pi, 100)
    plt.figure(figsize=(8, 6))
    arr = []
    for i in delta:
        arr.append(abs(fun(n, i, beta, d, eta)))
    plt.plot(delta, arr, color="blue", linewidth=3, linestyle="-")
    plt.xlabel("delta")
    plt.ylabel("|Fs(delta)|")
    plt.show()


if __name__ == "__main__":
    main()

