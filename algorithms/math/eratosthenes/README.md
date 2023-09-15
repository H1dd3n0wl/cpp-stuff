## Algorithm description

The classic eratosthenes sieve helps us to find all prime numbers up to any given limit. 

There we have some versions of algorithm. Classic version uses less memory than linear-time version, but it can only give us answer about primality of numbers and it's time completion is $O(nloglogn)$. 

With the help of linear-time version you can factorise the number for $O(d(n))$, where $d(n)$ is count of prime divisors of n and check for prime for $O(1)$.

The block version of eratosthenes sieve give us possibility to use prime numbers in about classical time but with $O(\sqrt n)$ memory complexity.