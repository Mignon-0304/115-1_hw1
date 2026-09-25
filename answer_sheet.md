# Data Structures Homework 1: Answer Sheet

Student ID: 114703020　Name: 張又琦

At most 2 pages after conversion to PDF. For sections 2 and 3, the explanatory text you write yourself should total no more than about 800 English words, excluding the printed prompts and the bare numbers in the tables. You do not need to use the full allowance.

---

## 1. Shortest counterexample for the faulty growth strategy

### 1.1 Shortest operation sequence

The initial capacity is 2. Fill in at most 5 `enqueue()`/`dequeue()` operations:

```CPP
CircularQueue myQ(2);
myQ.enqueue(1);
myQ.enqueue(2);
myQ.dequeue();
myQ.enqueue(3);
myQ.enqueue(4);
```

### 1.2 Step-by-step state

| Operation | `front_` | `rear_` | `size_` | Logical order | Actual array layout |
|---|---:|---:|---:|---|---|
| .enqueue(1) | 0 | 1 | 1 | (1,_) | (1,_) |
| .enqueue(2) | 0 | 0 | 2 | (1, 2) | (1, 2) |
| .dequeue() | 1 | 0 | 1 | (2,_) | (1, 2) |
| .enqueue(3) | 1 | 1 | 2 | (2, 3) | (3, 2) |
| .enqueue(4) | 0 | 0 | 3 | (3, 2, 4, _) | (3, 2, 4, _) |

### 1.3 Correct versus faulty result

- Elements removed in order by the correct implementation: 2->3->4
- Elements removed in order by the faulty implementation: 3->2->4

### 1.4 Which invariant is broken

the First-In First-Out principle.

---

## 2. Operation counts and growth trend

Big-O notation is not required in this section.

### 2.1 `CircularQueue`

- When timing starts, what are `size()` and `capacity()`?
The `size()` and `capacity()` are both `n`, which represents the elements stored in `sizes[]`. During the whole opteration, it has been 2^9, 2^12, and 2^15.
- Each round runs `dequeue()` first and then `enqueue()`. How many existing elements does each of the two operations move? [fill in]
The existing elements are never moved. The `front_` and `rear_` are moved, but not the elements themselves.
- Why does no capacity growth occur during the timed phase?
Because there is no need. `dequeue()` leaves one space unused, and `enqueue()` uses that space. Minus 1 and plus 1, so it never runs out of spaces.

### 2.2 `NaiveShiftQueue`

- With `n` elements in the queue, roughly how many elements does each `dequeue()` shift forward?
n-1
- After `n` consecutive rounds, roughly how many element moves are performed in total?
n-1 + n-2 + n-3 + ... + 1 + 0

### 2.3 Growth when the input size increases

| Implementation | When `n` grows 8 times, the number of basic operations grows roughly how many times? | Reasoning |
|---|---:|---|
| `CircularQueue` | 8 | every `enqueue()` and `dequeue()` only requires one basic operation |
| `NaiveShiftQueue` | 64 | `enqueue()` only requires one basic operation, but `dequeue()` traversels the whole queue, so the whole `measure()` requires roughly square of the size of the queue. |

---

## 3. Experimental results and discussion

### 3.1 Median running times and growth ratios

| `n` | `CircularQueue` median (ms) | Ratio to previous size | `NaiveShiftQueue` median (ms) | Ratio to previous size |
|---:|---:|---:|---:|---:|
| $2^9$ |  | n/a |  | n/a |
| $2^{12}$ |  |  |  |  |
| $2^{15}$ |  |  |  |  |

### 3.2 Comparing operation counts with measured times

Compare the measured growth ratios with the ratios you derived from operation counts in the previous section. Do the measurements follow the same growth trend? If they do not match exactly, give one reasonable explanation. You may briefly mention fixed costs, memory access efficiency, or compiler optimisation; you do not need to discuss hardware details in depth.

[fill in]
