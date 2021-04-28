#ifndef KMEANS_HPP
#define KMEANS_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <float.h>
#include <cmath>

using namespace std;

class Point
{
public:
    unsigned int cid;
    double min_dist;
    vector<double> attribute;

    Point(vector<double> attribute, unsigned int cid) { this->attribute = attribute, this->cid = cid, this->min_dist = DBL_MAX; };
};

class kMeans
{
private:
    unsigned int dim;                      //属性の次元数
    unsigned int k;                        // クラス数
    unsigned int maxLoop;                  // 最大ループ数
    vector<Point> points;                  // 各点の集合
    vector<vector<double>> clusterCenters; //クラスタ中心の集合
    void init(string datafilePath, int k); // データを読み込み，各点にランダムにラベルを与える
    void fit();
    void computeCenter();
    double distance(const vector<double> &v, const vector<double> &u);

public:
    kMeans(string filename, unsigned int k, unsigned int maxLoop = 100);
    vector<Point> getPoints() { return points; };
    vector<vector<double>> getClusterCenters() { return clusterCenters; };
};

#endif