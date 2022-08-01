#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>





using std::vector;

struct Segment {
    int start, end;
};
bool compareStart(Segment i1, Segment i2)
{
    return (i1.start < i2.start);
}
bool compareEnd(Segment i1, Segment i2)
{
    return (i1.end < i2.end);
}

vector<int> optimal_points(vector<Segment>& segments) {
    sort(segments.begin(), segments.end(), compareEnd);
    sort(segments.begin(), segments.end(), compareStart);
    vector<int> res;
    int currentIndex = 0;
    vector<int> points;
    vector<int> seg;
    vector<int> z = { 0 };
    vector<vector<int>> segInd;

    while (segments.size() > 0) {
        for (int i = 0; i < (1 + segments[0].end - segments[0].start); i++) {
            segInd.push_back(z);
        }

        for (int i = segments[0].start; i <= segments[0].end; i++) {
            points.push_back(i);
            seg.push_back(0);
            
            for (int ii = 1; ii < segments.size(); ii++) {
                if (i >= segments[ii].start && i <= segments[ii].end) {
                    seg[currentIndex]++;
                    segInd[currentIndex].push_back(ii);
                }
            }
            currentIndex++;
        }

        int maxInd = max_element(seg.begin(), seg.end()) - seg.begin();
        res.push_back(points[maxInd]);
        for (int i = 0; i < segInd[maxInd].size(); i++) {
            int index = segInd[maxInd][i] - i;
            segments.erase(segments.begin() +index);
        }
        points.clear();
        seg.clear();
        segInd.clear();
        currentIndex = 0;
    }
        return res;
}

vector<int> optimal_points0(vector<Segment> segments) {

    // sort the vector according to the end points
    std::sort(segments.begin(), segments.end(), [](const Segment& a, const Segment& b) -> bool {
        return a.end < b.end;
        });

    vector<int> points; // create a vector to store the common points in the segments
    int point = segments[0].end; // set the point to the first end point i-e shortest end point
    points.push_back(point);

    for (size_t i = 1; i < segments.size(); ++i) {
        if (point < segments[i].start || point > segments[i].end) { // if the point is not in the segment
            point = segments[i].end; // update the point to the end point of the current segment
            points.push_back(point); // store it in the vector
        }
    }

    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points0(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}
