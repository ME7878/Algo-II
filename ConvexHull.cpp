#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isAnticlockwise(vector<int> &A, vector<int> &B, vector<int> &C)
{
    return ((B[0] - A[0]) * (C[1] - A[1])) - ((B[1] - A[1]) * (C[0] - A[0])) > 0;
}
vector<vector<int>> convexHull(vector<vector<int>> &points)
{
    if (points.size() <= 3)
        return points;
    sort(points.begin(), points.end());
    vector<vector<int>> hull;
    for (int i = 0; i < points.size(); i++)
    {
        while (hull.size() >= 2 && isAnticlockwise(hull[hull.size() - 2], hull[hull.size() - 1], points[i]))
        {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    int hullsize = hull.size();
    for (int i = points.size() - 2; i >= 0; i--)
    {
        while (hull.size() > hullsize && isAnticlockwise(hull[hull.size() - 2], hull[hull.size() - 1], points[i]))
        {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    sort(hull.begin(), hull.end());
    hull.erase(unique(hull.begin(), hull.end()), hull.end());
    return hull;
}
int main()
{
    vector<vector<int>> points = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}, {2, 1}};
    vector<vector<int>> Result = convexHull(points);
    cout << "Convex Hull Points:" << endl;
    for (const auto &p : Result)
    {
        cout << "(" << p[0] << ", " << p[1] << ")" << endl;
    }
    return 0;
}