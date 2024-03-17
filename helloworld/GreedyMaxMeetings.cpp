#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meeting {
    int start;
    int end;
} mt[100'000];

bool compare(const meeting& m1, const meeting& m2) {
    if (m1.end == m2.end) { // if same end time, ascending order in start time
        return (m1.start < m2.start);
    }

    return (m1.end < m2.end); // ascending order in end time
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numMeeting;

    cin >> numMeeting;

    for (int i = 0; i < numMeeting; i++) {
        int tempStart, tempEnd;
        cin >> tempStart >> tempEnd;
        mt[i].start = tempStart;
        mt[i].end = tempEnd;
    }

    sort(mt, mt + numMeeting, compare);

    // for (auto i : meetings) {
    //     cout << i->end << " " << i->start << "\n";
    // }

    int numMeetings {1};
    int index{0};
    meeting limitMeeting = mt[index];

    while (index < numMeeting - 1) {
        while (index < numMeeting - 1 && mt[++index].start < limitMeeting.end);

        if (mt[index].start >= limitMeeting.end) {
            limitMeeting = mt[index];
            numMeetings++;
        }
    }

    cout << numMeetings;
}