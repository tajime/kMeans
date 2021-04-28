import numpy as np
import matplotlib.pyplot as plt
import os


color = ['r', 'b', 'g', 'y']


def resultplot():
    filename = "data/result.csv"
    # ファイルが開けなかったら終了
    if not os.path.exists(filename):
        print("file open failed : "+filename)
        return
    for line in open(filename):
        tokens = line.replace('\n', '').split(',')
        plt.scatter(float(tokens[1]), float(tokens[2]),
                    color=color[int(tokens[0])])
    plt.scatter(3.73363, -5.25654, facecolor='0.9',
                edgecolor='0.1', marker=',', s=40)
    plt.scatter(-5.19009, -4.23884, facecolor='0.9',
                edgecolor='0.1', marker=',', s=40)
    plt.scatter(-3.20514, 5.81573, facecolor='0.9',
                edgecolor='0.1', marker=',', s=40)
    plt.scatter(4.01269, 4.22311, facecolor='0.9',
                edgecolor='0.1', marker=',', s=40)
    plt.show()


if __name__ == "__main__":
    resultplot()
