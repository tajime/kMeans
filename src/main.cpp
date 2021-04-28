#include "kMeans.hpp"

using namespace std;

int main()
{
    kMeans km("test.txt", 4);
    vector<Point> pvec = km.getPoints();
    ofstream result("data/result.csv");
    for (Point point : pvec)
    {
        result << point.cid << ",";
        for (double attri : point.attribute)
            result << attri << ",";
        result << point.min_dist << endl;
    }
}