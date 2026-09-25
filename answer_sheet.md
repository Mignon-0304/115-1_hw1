## Data Structures Homework 1: Answer Sheet

---

<small>Student ID: 114703020　Name: 張又琦</small>

---

### 1. Shortest counterexample for the faulty growth strategy

#### 1.1 Shortest operation sequence

The initial capacity is 2. Fill in at most 5 `enqueue()`/`dequeue()` operations:

```CPP
CircularQueue myQ(2);
myQ.enqueue(1); myQ.enqueue(2);
myQ.dequeue();
myQ.enqueue(3); myQ.enqueue(4);
```

#### 1.2 Step-by-step state

<div style="font-size: 10px;">
  <table>
    <thead>
      <tr>
        <th>Operation</th>
        <th><code>front_</code></th>
        <th><code>rear_</code></th>
        <th><code>size_</code></th>
        <th>Logical order</th>
        <th>Actual array layout</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>.enqueue(1)</td>
        <td>0</td>
        <td>1</td>
        <td>1</td>
        <td>(1,_)</td>
        <td>(1,_)</td>
      </tr>
      <tr>
        <td>.enqueue(2)</td>
        <td>0</td>
        <td>0</td>
        <td>2</td>
        <td>(1,2)</td>
        <td>(1,2)</td>
      </tr>
      <tr>
        <td>.dequeue()</td>
        <td>1</td>
        <td>0</td>
        <td>1</td>
        <td>(2,_)</td>
        <td>(1,2)</td>
      </tr>
      <tr>
        <td>.enqueue(3)</td>
        <td>1</td>
        <td>1</td>
        <td>2</td>
        <td>(2,3)</td>
        <td>(3,2)</td>
      </tr>
      <tr>
        <td>.enqueue(4)</td>
        <td>0</td>
        <td>3</td>
        <td>3</td>
        <td>(3, 2, 4, _)</td>
        <td>(3, 2, 4, _)</td>
      </tr>
    </tbody>
  </table>
</div>

#### 1.3 Correct versus faulty result

- Elements removed in order by the correct implementation: 2->3->4
- Elements removed in order by the faulty implementation: 3->2->4

#### 1.4 Which invariant is broken

<small><span style="color:red">Ans:</span>the First-In First-Out principle.</small>

---

### 2. Operation counts and growth trend

<small><span style="color:red">Ans:</span>Big-O notation is not required in this section.</small>

#### 2.1 `CircularQueue`

- When timing starts, what are `size()` and `capacity()`? &nbsp;&nbsp;<small><span style="color:red">Ans:</span>The `size()` and `capacity()` are both `n`, which represents the elements stored in `sizes[]`. During the whole opteration, it has been $2^9$, $2^{12}$, and $2^{15}$.</small>
- Each round runs `dequeue()` first and then `enqueue()`. How many existing elements does each of the two operations move?&nbsp;&nbsp;<small><span style="color:red">Ans:</span>The existing elements are never moved. The `front_` and `rear_` are moved, but not the elements themselves.</small>
- Why does no capacity growth occur during the timed phase?&nbsp;&nbsp;<small><span style="color:red">Ans:</span>Because there is no need. `dequeue()` leaves one space unused, and `enqueue()` uses that space. Minus 1 and plus 1, so it never runs out of spaces.</small>

#### 2.2 `NaiveShiftQueue`

- With `n` elements in the queue, roughly how many elements does each `dequeue()` shift forward?&nbsp;&nbsp;<small><span style="color:red">Ans:</span>n-1</small>
- After `n` consecutive rounds, roughly how many element moves are performed in total?&nbsp;&nbsp;<small><span style="color:red">Ans:</span>n-1 + n-1 + n-1 + ... = n(n-1)</small>

#### 2.3 Growth when the input size increases

<table style="font-size:10px">
<thead>
<tr>
<th>Implementation</th>
<th>When <code>n</code> grows 8 times, the number of basic operations grows roughly how many times?</th>
<th>Reasoning</th>
</tr>
</thead>
<tbody>
<tr>
<td><code>CircularQueue</code></td>
<td style="text-align:center">8</td>
<td>every <code>enqueue()</code> and <code>dequeue()</code> only requires one basic operation</td>
</tr>
<tr>
<td><code>NaiveShiftQueue</code></td>
<td style="text-align:center">64</td>
<td><code>enqueue()</code> only requires one basic operation, but <code>dequeue()</code> traverses the whole queue, so the whole <code>measure()</code> requires roughly the square of the queue's size.</td>
</tr>
</tbody>
</table>

---

### 3. Experimental results and discussion

#### 3.1 Median running times and growth ratios

| <small>`n`</small> | <small>`CircularQueue` median (ms)</small> | <small>Ratio to previous size</small> | <small>`NaiveShiftQueue` median (ms)</small> | <small>Ratio to previous size</small> |
|---:|---:|---:|---:|---:|
| $2^9$| <small>0.008</small> | <small>n/a </small>| <small>0.647</small> | <small>n/a</small> |
| $2^{12}$ | <small>0.066</small> | <small>8.25</small> | <small>19.248</small> | <small>29.750</small> |
| $2^{15}$ | <small>0.214</small> | <small>3.242</small> | <small>864.558</small> | <small>44.917</small> |

#### 3.2 Comparing operation counts with measured times

<small><span style="color:red">Ans:</span>The ratio of `CircularQueue`: $2^{12}$/$2^9$ is very close to 8, but that of `CircularQueue`: $2^{15}$/$2^{12}$ is less than expected. That might be because the CPU spent more resources on the operation when `n` got bigger and therefore increased the efficiency.
The ratio of both `NaiveShiftQueue`: $2^{12}$/$2^9$ and $2^{15}$/$2^{12}$ are less than expected. That might have resulted from the fixed costs like initializing the variables, which make the calculated ratio not showing obviously when n is not very big.</small>