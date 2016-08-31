class Queue {
  private:
    stack<int> a, b;

  public:
    // Push element x to the back of queue.
    void push(int x) {
        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }
        b.push(x);
        while (!b.empty()) {
            a.push(b.top());
            b.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) { a.pop(); }

    // Get the front element.
    int peek(void) { return a.top(); }

    // Return whether the queue is empty.
    bool empty(void) { return a.empty(); }
};
