# push_swap
42 project of sorting algos

All very simple.

Program `checker INTLIST` receives commands in stdin, runs it through INTLIST. If the result is ordered, success!

Program `push_swap INTLIST` generates and outputs to stdout the necessary commands to order the shuffled INTLIST.

Therefore: `pushswap 2 1 3 | checker 2 1 3` should wield `OK`.

INTLIST has no limits, though 500n takes a little time to proccess.

This is my score:

| 2 1 0 | 3 |
| 1 5 2 4 3 | 8 |
| n n n n n | +/- 8 |
| 100n | +/- 650 |
| 500n | +/- 7300 |
