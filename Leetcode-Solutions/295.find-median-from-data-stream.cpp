/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (51.10%)
 * Likes:    9267
 * Dislikes: 179
 * Total Accepted:    574.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * The median is the middle value in an ordered integer list. If the size of
 * the list is even, there is no middle value, and the median is the mean of
 * the two middle values.
 *
 *
 * For example, for arr = [2,3,4], the median is 3.
 * For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
 *
 *
 * Implement the MedianFinder class:
 *
 *
 * MedianFinder() initializes the MedianFinder object.
 * void addNum(int num) adds the integer num from the data stream to the data
 * structure.
 * double findMedian() returns the median of all elements so far. Answers
 * within 10^-5 of the actual answer will be accepted.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * Output
 * [null, null, null, 1.5, null, 2.0]
 *
 * Explanation
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 *
 *
 *
 * Constraints:
 *
 *
 * -10^5 <= num <= 10^5
 * There will be at least one element in the data structure before calling
 * findMedian.
 * At most 5 * 10^4 calls will be made to addNum and findMedian.
 *
 *
 *
 * Follow up:
 *
 *
 * If all integer numbers from the stream are in the range [0, 100], how would
 * you optimize your solution?
 * If 99% of all integer numbers from the stream are in the range [0, 100], how
 * would you optimize your solution?
 *
 *
 */

// @lc code=start
class MedianFinder
{
private:
    // MIN HEAP
    priority_queue<int, vector<int>, greater<int>> up;
    // MAX HEAP
    priority_queue<int> down;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        // insert to left part
        if (down.empty() || num <= down.top())
        {
            down.push(num);
            // if the size of left part is bigger than right
            // move the biggest number to right part keeping balance
            if (down.size() > up.size() + 1)
            {
                up.push(down.top());
                down.pop();
            }
        }
        else
        {
            // if the number bigger than the max number in left part
            // we will insert it to right part
            up.push(num);
            // balancing
            if (up.size() > down.size())
            {
                down.push(up.top());
                up.pop();
            }
        }
    }

    double findMedian()
    {
        // if the counter of number is odd, just return the max number in left part
        if ((down.size() + up.size()) % 2)
            return down.top();
        return (down.top() + up.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
