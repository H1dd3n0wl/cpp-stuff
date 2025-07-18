## Алгоритм Евклида поиска наибольшего общего делителя

Несмотря на то, что в стандартной библиотеке C++ есть встроенная реализация поиска наибольшего общего делителя (или НОД), а именно `constexpr int std::__gcd<int>(int __m, int __n)`, стоит упоминания его реализация. Сам алгоритм описывается следующей формулой:
$$
gcd(a, b) = 
    \begin{cases}
        a, \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ b = 0 \\
        gcd(b, a \ \% \  b), \ b \ne 0
    \end{cases},
$$

где $a \ \% \ b$ — остаток от деления $a$ на $b$.

Таким образом несложно реализовать алгоритм Евклида для поиска наибольшего общего делителя:

```
int gcd(int a, int b) {
    return b ? gcd (b, a % b) : a;
}
```

Или, не рекурсивная версия:

```
int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}
```

## Расширенный алгоритм Евклида

Расширенный алгоритм Евклида находит помимо НОД также коэффициенты $x$ и $y$ такие, что $a \cdot x + b \cdot y = gcd(a, b)$. Т.е. он находит коэффициенты, с помощью которых НОД двух чисел выражается через сами эти числа.
