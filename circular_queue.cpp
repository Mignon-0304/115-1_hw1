#include "circular_queue.hpp"

#include <stdexcept>

CircularQueue::CircularQueue(std::size_t initial_capacity)
    : data_(nullptr), capacity_(0), size_(0), front_(0), rear_(0) {
    // TODO 1: If initial_capacity is 0, throw std::invalid_argument;
    //         otherwise allocate the dynamic array and initialise the members.
    if(initial_capacity==0) throw std::invalid_argument("無效的初始值");
    else{
        data_ = new int[initial_capacity];
        capacity_ = initial_capacity;
    }
}

CircularQueue::~CircularQueue() {
    // TODO 2: Release the dynamic array.
    delete[] data_;
}

bool CircularQueue::empty() const {
    // TODO 3: Report whether the queue is currently empty.
    if(size_==0) return true;
    return false;
}

std::size_t CircularQueue::size() const {
    // TODO 4: Report the current number of elements.
    return size_;
}

std::size_t CircularQueue::capacity() const {
    // TODO 5: Report the capacity of the currently allocated array.
    return capacity_;
}

int CircularQueue::front() const {
    // TODO 6: If the queue is empty, throw std::underflow_error;
    //         otherwise return the front element.
    //         This function does not need to move any element.
    if(empty()) throw std::underflow_error("陣列為空");
    return data_[front_];
}

void CircularQueue::grow() {
    // TODO 7:
    // 1. Double the capacity.
    // 2. Copy the elements in their logical order.
    // 3. Release the old array and update front_, rear_ and capacity_.
    int* newData = new int[2 * capacity_];
    for(size_t i=0 ; i<capacity_ ; i++) newData[i] = i + front_ >= capacity_ ? data_[i+front_-capacity_] : data_[i+front_];
    capacity_ *= 2;
    front_ = 0;
    rear_ = size_;
    delete[] data_;
    data_ = newData;
}

void CircularQueue::enqueue(int value) {
    // TODO 8: Grow the capacity first if necessary, then append value at the rear.
    if(size_!=0 && rear_==front_) grow();
    data_[rear_] = value;
    rear_ = (rear_ + 1) % capacity_;
    size_++;
}

void CircularQueue::dequeue() {
    // TODO 9: If the queue is empty, throw std::underflow_error;
    //         otherwise remove the front element.
    //         This function does not need to move any element.
    if(empty()) throw std::underflow_error("陣列為空");
    front_ = (front_ + 1) % capacity_;
    size_--;
}
