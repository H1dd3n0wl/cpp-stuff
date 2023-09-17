## Algorithm description

Suppose we are given a string $s$ of length $n$. The **Z-function** for this string is an array of length $n$ where $i$-th element is equal to the greatest number of characters starting from the position $i$ that coincide with the first characters of $s$.

In other words, $z[i]$ is the length of the longest common prefix of $s$ and it's suffix that started from $i$.