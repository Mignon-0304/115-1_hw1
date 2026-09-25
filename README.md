# Data Structures Homework 1: Dynamic Circular Queue

Student ID: 114703020　Name: 張又琦

Environment: Operating system: Ubuntu 24.04.5, compiler: g++ 13.3.0

This assignment does not prescribe a development environment. The commands below are exactly the commands used for grading; there are no hidden conditions. Please make sure your program passes all of them.

## 1. File responsibilities

- You complete: `circular_queue.cpp`, `tests.cpp`, `answer_sheet.md`, `ai_disclosure.md`, `README.md` (fill in the environment).
- Provided and must not be modified: `naive_shift_queue.hpp`, `public_tests.cpp`, `benchmark.cpp`, `plot_results.py`.
- The public interface in `circular_queue.hpp` must not be modified; you may use the provided private helper `grow()`.

## 2. Build and run the public tests

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic \
    public_tests.cpp circular_queue.cpp -o public_tests
./public_tests
```

The output should be `All public tests passed.`, and the build should produce no warnings.

## 3. Build and run your own tests

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic \
    tests.cpp circular_queue.cpp -o tests
./tests
```

Record the random seed used by the randomized differential test as a named constant in `tests.cpp`.

## 4. Check memory safety

Memory safety is graded with AddressSanitizer and UndefinedBehaviorSanitizer. Please run the following check yourself:

```bash
g++ -std=c++20 -g -Wall -Wextra -pedantic \
    -fsanitize=address,undefined -fno-omit-frame-pointer \
    tests.cpp circular_queue.cpp -o tests_asan
./tests_asan
```

The run should report no memory leaks, out-of-bounds accesses, double frees, use-after-free, or any other undefined behaviour.

On Linux, LeakSanitizer is enabled by default, so the command above already detects memory leaks and no extra option is needed. macOS does not support LeakSanitizer, and adding options will not help: if you develop on macOS, please rerun this check on a Linux machine or container before submitting. Otherwise, if you forget to release memory in the destructor, you will see no error message at all on your own machine.

## 5. Run the performance experiment

```bash
g++ -std=c++20 -O2 -Wall -Wextra -pedantic \
    benchmark.cpp circular_queue.cpp -o benchmark
./benchmark > results.csv
python3 plot_results.py results.csv performance.png
```

`plot_results.py` requires Python 3 and Matplotlib (install it with `pip install matplotlib`). It produces `performance.png` and prints the median running time of both implementations at each input size to the terminal; copy those numbers onto the answer sheet.

If you cannot install Matplotlib, you may compute the medians from `results.csv` yourself and draw `performance.png` with any tool, as long as it meets the requirements (axis labels, time unit, and two curves). `results.csv` must still be the raw 18 measurements produced directly by `benchmark.cpp`.

## 6. Before submitting

1. Convert `answer_sheet.md` into `answer_sheet.pdf` of at most 2 pages.
2. Fill in the operating system and compiler version you actually used at the top of this file.
3. Confirm that the commands in sections 2 to 5 reproduce your results from scratch in a clean directory.
4. Build `studentID_HW1.zip` according to the file list in the assignment specification.
5. The provided `public_tests.cpp`, `naive_shift_queue.hpp`, `benchmark.cpp` and `plot_results.py` do not need to be included in the submission archive.
