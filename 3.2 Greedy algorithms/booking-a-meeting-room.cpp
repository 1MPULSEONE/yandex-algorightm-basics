#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
};

bool compareIntervals(Interval i1, Interval i2)
{
    return i1.end < i2.end;
}

int main()
{

    vector<Interval> intervals;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        intervals.push_back({start, end});
    }

    sort(intervals.begin(), intervals.end(), compareIntervals);

    int count = 1;
    Interval currInterval = intervals[0];

    for (int i = 1; i < n; i++)
    {
        if (intervals[i].start > currInterval.end)
        {
            currInterval = intervals[i];
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
