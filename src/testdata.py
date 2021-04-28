import numpy as np
import matplotlib.pyplot as plt

# 適当なデータセットを作成する
N = 100
np.random.seed(0)
points1 = np.random.randn(N, 2)*1.5 + np.array([4, 4])
points2 = np.random.randn(N, 2)*1.9 + np.array([4, -5])
points3 = np.random.randn(N, 2)*1.7 + np.array([-3, 6])
points4 = np.random.randn(N, 2)*1.8 + np.array([-5, -4])

points = np.r_[points1, points2, points3, points4]
np.random.shuffle(points)
np.savetxt('../data/test.txt', points)
for p in points:
    plt.scatter(p[0], p[1], color='b')
plt.show()
