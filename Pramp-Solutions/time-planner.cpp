#include <iostream>
#include <vector>

using namespace std;

vector<int> meetingPlanner(const vector<vector<int>>& slotsA, const vector<vector<int>>& slotsB, int dur) {

    vector<int> res;
    if (slotsA.size() == 0 || slotsB.size() == 0) return res;

    int idxA = 0, idxB = 0;
    while (idxA < slotsA.size() && idxB < slotsB.size()) {
        int startA = slotsA[idxA][0], endA = slotsA[idxA][1];
        int startB = slotsB[idxB][0], endB = slotsB[idxB][1];
        int start = max(startA, startB), end = min(endA, endB);
        int len = end - start;
        if (len >= dur) {
            return { start, start + dur };
        }
        if (endA < endB) {
            idxA++;
        } else {
            idxB++;
        }
    }
    return res;

}

int main() {
    return 0;
}
