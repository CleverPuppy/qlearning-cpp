#! /usr/bin/python3

from matplotlib import pyplot as plt
import numpy as np
import sys

def drawLoss(filename: str):
    data = np.loadtxt(filename)
    
    plt.plot(data[:,2])
    plt.show()
    print(data)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print('需要一个参数: log file')
        exit(-1)
    filename = sys.argv[1]
    drawLoss(filename)