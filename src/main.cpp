#include "kMeans.hpp"

using namespace std;

int main()
{
    kMeans km("test.txt", 4);
    vector<vector<double>> cc = km.getClusterCenters();
    vector<Point> pvec = km.getPoints();
    ofstream result("../data/result.csv");
    for (Point point : pvec)
    {
        result << point.cid << ",";
        for (double attri : point.attribute)
            result << attri << ",";
        result << point.min_dist << endl;
    }
    result << endl;
    for (vector<double> vd : cc)
    {
        for (int i = 0; i < vd.size(); ++i)
        {
            if (i == vd.size() - 1)
                result << vd[i];
            else
                result << vd[i] << ",";
        }
        result << endl;
    }
}