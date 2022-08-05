#include <iostream>
#include <algorithm>
#include <vector> 
#include <chrono> 
#include <iomanip>

using namespace std;





struct segment {
    int start, end;
};
bool compareInterval(segment i1, segment i2)
{
    return (i1.start < i2.start);
}


vector<int> fast_count_segments(vector<segment> s, vector<int> points) {
    vector<int> cnt(points.size());
    vector<int> cnt2(points.size());
    sort(s.begin(), s.end(), compareInterval);
    for (int i = 0; i < points.size(); i++) {
        int left = 0, right = s.size() - 1;
        while (true) {
            int mid = 0.5 * ((double)left + (double)right);

            if (mid == s.size() - 1 && points[i] >= s[mid].start) {
                cnt[i] = mid;
                break;
            }
            if ((points[i] == s[mid].start && points[i] != s[mid + 1].start) || (points[i] > s[mid].start && left == right)) {
                cnt[i] = mid;
                break;
            }
            if ((points[i] < s[mid].start && left == right)) {
                (mid != 0) ? (cnt[i] = mid - 1) : (cnt[i] = -1);
                break;
            }
            if (points[i] > s[mid].start || points[i] == s[mid + 1].start) {
                left = mid + 1;
            }
            if (points[i] < s[mid].start) {
                right = mid - 1;
            }
        }
        for (int x = 0; x <= cnt[i]; x++) {
            if (points[i] <= s[x].end) {
                cnt2[i]++;
            }
        }


    }



    return cnt2;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<segment> segments(n);
    vector<int> starts(n), ends(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> segments[i].start >> segments[i].end;
        starts[i] = segments[i].start;
        ends[i] = segments[i].end;
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        std::cin >> points[i];
    }

    vector<int> cnt = fast_count_segments(segments, points);
    for (size_t i = 0; i < cnt.size(); i++) {
        std::cout << cnt[i] << ' ';
    }


}
