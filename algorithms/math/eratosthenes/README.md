## Algorithm description

The eratosthenes sieve helps us to find all prime numbers up to any given limit. In this version of algorithm we have all of maximum prime divisor for all numbers from 1 to n. So you can factorise the number for $O(d(n))$, where $d(n)$ is count of prime divisors of n and check for prime for $O(1)$. The summary time of building the sieve is $O(n loglogn)$.