# Data Structures Homework 1: Answer Sheet

Student ID: 114703020　Name: 張又琦

At most 2 pages after conversion to PDF. For sections 2 and 3, the explanatory text you write yourself should total no more than about 800 English words, excluding the printed prompts and the bare numbers in the tables. You do not need to use the full allowance.

---

## 1. Shortest counterexample for the faulty growth strategy

### 1.1 Shortest operation sequence

The initial capacity is 2. Fill in at most 5 `enqueue()`/`dequeue()` operations:

```text
CircularQueue myQ(2);
myQ.enqueue(1);
myQ.enqueue(2);
myQ.dequeue();
myQ.enqueue(3);
```

### 1.2 Step-by-step state

| Operation | `front_` | `rear_` | `size_` | Logical order | Actual array layout |
|---|---:|---:|---:|---|---|
| [fill in] |  |  |  |  |  |
|  |  |  |  |  |  |
|  |  |  |  |  |  |
|  |  |  |  |  |  |
|  |  |  |  |  |  |

### 1.3 Correct versus faulty result

- Elements removed in order by the correct implementation: [fill in]
- Elements removed in order by the faulty implementation: [fill in]

### 1.4 Which invariant is broken

[fill in]

---

## 2. Operation counts and growth trend

Big-O notation is not required in this section.

### 2.1 `CircularQueue`

- When timing starts, what are `size()` and `capacity()`? [fill in]
- Each round runs `dequeue()` first and then `enqueue()`. How many existing elements does each of the two operations move? [fill in]
- Why does no capacity growth occur during the timed phase? [fill in]

### 2.2 `NaiveShiftQueue`

- With `n` elements in the queue, roughly how many elements does each `dequeue()` shift forward? [fill in]
- After `n` consecutive rounds, roughly how many element moves are performed in total? [fill in]

### 2.3 Growth when the input size increases

| Implementation | When `n` grows 8 times, the number of basic operations grows roughly how many times? | Reasoning |
|---|---:|---|
| `CircularQueue` |  |  |
| `NaiveShiftQueue` |  |  |

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
