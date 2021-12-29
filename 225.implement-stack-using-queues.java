import java.util.LinkedList;
import java.util.Queue;

/*
 * @lc app=leetcode id=225 lang=java
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
    Queue<Integer> mainQueue, tempQueue;
    int size, top;

    // init value
    public MyStack() {
        mainQueue = new LinkedList<>();
        tempQueue = new LinkedList<>();
        size = 0;
    }

    public void push(int x) {
        mainQueue.offer(x);
        top = x;
        size++;
    }

    public int pop() {

        // move [0, size-2] values to temp queue
        int index = 0;
        // at the same time, you need update new top value
        while (index++ < size - 1) {
            int val = mainQueue.poll();
            tempQueue.offer(val);
            top = val;
        }
        // the last value in main queue is the top value
        int ans = mainQueue.poll();
        // put [0, size-2] values back to main queue
        while (!tempQueue.isEmpty()) {
            mainQueue.offer(tempQueue.poll());
        }
        // pop val means size subtract 1
        size--;
        return ans;
    }

    public int top() {
        return top;
    }

    public boolean empty() {
        return size == 0;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
// @lc code=end
