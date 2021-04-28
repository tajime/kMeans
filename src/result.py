import numpy as np
import matplotlib.pyplot as plt
import os


color = ['r', 'b', 'g', 'y']


def resultplot():
    filename = "../data/result.csv"
    # ファイルが開けなかったら終了
    if not os.path.exists(filename):
        print("file open failed : "+filename)
        return
    for line in open(filename):
        tokens = line.replace('\n', '').split(',')
        if len(tokens) == 4:
            plt.scatter(float(tokens[1]), float(tokens[2]),
                        color=color[int(tokens[0])])
        elif len(tokens) == 2:
            plt.scatter(float(tokens[0]), float(tokens[1]), facecolor='0.9',
                        edgecolor='0.1', marker=',', s=40)
    plt.show()


if __name__ == "__main__":
    resultplot()
