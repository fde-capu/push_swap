# push_swap
42 project of sorting algos

All very simple.

Program `checker INTLIST` receives commands in stdin, runs it through INTLIST. If the result is ordered, success!

Program `push_swap INTLIST` generates and outputs to stdout the necessary commands to order the shuffled INTLIST.

Therefore: `pushswap 2 1 3 | checker 2 1 3` should wield `OK`.

INTLIST has no limits, though 500n takes a little time to proccess.

The instructions for sorting the sequence are made of 11 instructions for manipulating two stacks.

Stack A is initialized with the suffled sequence. At the end of the algorithm, Stack A must be in order and Stack B must be empty.

The instructions are:

- *pa*, *pb*: put fist element of B into A and vice-versa.

- *ra", *rb*, *rr*: rotats A, B or both; that is, fist element goes to last.

- *rra*, *rrb*, *rrr*: reverse rotates A, B or both.

- *sa*, *sb*, *ss*: swiches first and second of element of A, B or both.

By combining these instructions in some sort of elegant way, we must aim for the best algorithm performace.

---

This is my score:

|| 2 1 0 | 3 ||
|| 1 5 2 4 3 | 8 ||
|| n n n n n | +/- 8 ||
|| 100n | +/- 650 ||
|| 500n | +/- 7300 ||
