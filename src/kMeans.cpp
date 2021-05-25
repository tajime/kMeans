#include "kMeans.hpp"

using namespace std;

kMeans::kMeans(string filename, unsigned int k, unsigned int maxLoop)
{
    string datafilePath = "../data/" + filename;
    this->k = k;
    this->maxLoop = maxLoop;
    init(datafilePath, k);
    this->dim = points[0].attribute.size();
    computeCenter();
    fit();
}

void kMeans::init(string datafilePath, int k)
{
    ifstream ifs(datafilePath);
    if (ifs.fail())
    {
        cerr << "Failed to open file : " << datafilePath << endl;
        exit(1);
    }
    int buf_size = 1024;
    char line[buf_size];
    int i = 0;
    while (ifs.getline(line, buf_size))
    {
        istringstream iss(line);
        vector<double> attribute;
        double d;
        while (iss >> d)
            attribute.push_back(d);
        Point point(attribute, i++ % k);
        points.push_back(point);
    }
}

void kMeans::fit()
{
    for (int iterate = 0; iterate < maxLoop; ++iterate)
    {
        bool endflag = true;
        for (Point &point : points)
        {
            double min = DBL_MAX;
            unsigned int old_cid = point.cid;
            for (int i = 0; i < k; ++i)
            {
                double dist = distance(point.attribute, clusterCenters[i]);
                if (min > dist)
                {
                    point.cid = i;
                    point.min_dist = dist;
                    min = dist;
                }
            }
            if (point.cid != old_cid)
                endflag = false;
        }
        if (endflag)
            break;
        cout << iterate << endl;
        computeCenter();
    }
}

double kMeans::distance(const vector<double> &v, const vector<double> &u)
{
    double result = 0;
    if (v.size() != u.size())
    {
        cerr << "Failed to compute distance : v.size=" << v.size() << ", u.size=" << u.size() << endl;
        exit(1);
    }
    for (int i = 0; i < v.size(); ++i)
        result += (v[i] - u[i]) * (v[i] - u[i]);
    return sqrt(result);
}

void kMeans::computeCenter()
{
    clusterCenters.clear();
    for (int i = 0; i < k; ++i)
    {
        vector<double> sum(dim);
        int count = 0;
        for (const Point &point : points)
        {
            if (point.cid == i)
            {
                for (int j = 0; j < dim; ++j)
                    sum[j] += point.attribute[j];
                count++;
            }
        }
        if (count != 0)
        {
            for (int j = 0; j < dim; ++j)
                sum[j] /= count;
        }
        else
            sum = points[i].attribute;
        clusterCenters.push_back(sum);
    }
    for (vector<double> &vd : clusterCenters)
    {
        for (double d : vd)
            cout << d << ", ";
        cout << endl;
    }
    cout << endl;
}