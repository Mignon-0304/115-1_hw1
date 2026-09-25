#include "circular_queue.hpp"

#include <iostream>
#include <queue>
#include <random>
#include <stdexcept>
#include <string>

namespace {

int failures = 0;
constexpr unsigned int kSeed = 520u;  // TODO: replace with the fixed seed you choose and record.

void check(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "[FAIL] " << message << '\n';
        ++failures;
    }
}

void test_empty_and_one_element() {
    // TODO: Write the "empty queue and single element" test.
    CircularQueue myQ(10);
    check(myQ.empty(), "hasn't enqueued any elements but empty() returns false");
    check(myQ.size()==0, "hasn't enqueued any elements but size() doesn't return 0");
    myQ.enqueue(10);
    check(myQ.size()==1, "one element has been enqueued but size() doesn't return 1");
    check(!myQ.empty(), "there's one element in the queue but empty() returns true");
}

void test_wrap_then_grow() {
    // TODO: Write the "wrap-around then grow" test.
    // Use the same operation sequence as the shortest counterexample on the answer sheet.
    CircularQueue myQ(3);
    myQ.enqueue(1); myQ.enqueue(2); myQ.enqueue(3);

    myQ.dequeue(); myQ.dequeue();
    check(myQ.front()==3, "'dequeue()' has been called and 'front_' isn't as expected (should be: 3, instead it is: " + std::to_string(myQ.front()) + ")");

    myQ.enqueue(4);
    check(myQ.size()==2, "two elements in the queue but 'size()' doesn't return 2");

    myQ.enqueue(5); myQ.enqueue(6);
    check(myQ.size()==4, "two elements in the queue but 'size()' doesn't return 4");
    check(myQ.capacity()==6, "capacity should be doubled up but isn't");
}

void test_randomized_differential() {
    // TODO:
    // 1. Seed the random number generator with kSeed above.
    // 2. Generate at least 2,000 legal enqueue()/dequeue() operations.
    // 3. Apply the same operations to CircularQueue and to std::queue<int>.
    // 4. After each step compare size() and empty(), and compare front() when non-empty.
    CircularQueue myQ(1000);
    std::queue<int> stdQ;
    std::srand(kSeed);
    for(int i=0;i<2000;i++){
        int randomNum = rand();
        if(randomNum%2==0){
            myQ.enqueue(randomNum);
            stdQ.push(randomNum);
        } else {
            if(!myQ.empty()) myQ.dequeue();
            if(!stdQ.empty()) stdQ.pop();
        }
        check(myQ.size()==stdQ.size(),"CircularQueue not functioning like std::queue (size not match)");
        if(!myQ.empty() && !stdQ.empty()) check(myQ.front()==stdQ.front(), "CircularQueue not functioning like std::queue (front not match)");
        else check(myQ.empty()==stdQ.empty(),"CircularQueue not functioning like std::queue (one is empty while the other isn't)");
    }
}

}  // namespace

int main() {
    std::cout << "kSeed = " << kSeed << std::endl;

    std::cout << "executing test_empty_and_one_element..." << std::endl;
    test_empty_and_one_element();
    std::cout << "executing test_wrap_then_grow..." << std::endl;
    test_wrap_then_grow();
    std::cout << "executing test_randomized_differential..." << std::endl;
    test_randomized_differential();

    if (failures == 0) {
        std::cout << "All student tests passed.\n";
        return 0;
    }
    std::cerr << failures << " student check(s) failed.\n";
    return 1;
}
