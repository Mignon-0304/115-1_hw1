#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

#include <cstddef>

class CircularQueue {
public:
    explicit CircularQueue(std::size_t initial_capacity = 4);
    ~CircularQueue();

    CircularQueue(const CircularQueue&) = delete;
    CircularQueue& operator=(const CircularQueue&) = delete;

    bool empty() const;
    std::size_t size() const;
    std::size_t capacity() const;
    int front() const;
    void enqueue(int value);
    void dequeue();

private:
    int* data_;
    std::size_t capacity_;
    std::size_t size_;
    std::size_t front_;
    std::size_t rear_;

    // Double the capacity and rearrange the elements in the queue's logical order.
    void grow();
};

#endif
