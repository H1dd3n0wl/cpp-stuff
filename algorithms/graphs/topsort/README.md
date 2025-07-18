## Топологическая сортировка графа

Задача топологической сортировки графа звучит так: дан ориентированный граф, и требуется найти такой порядок вершин, в котором все рёбра графа вели из более ранней вершины в более позднюю.

Во-первых, сразу заметим, что граф с циклом топологически отсортировать не получится — как ни располагай цикл в массиве, все время идти вправо по ребрам цикла не получится.

Во-вторых, верно обратное. Если цикла нет, то его обязательно можно топологически отсортировать.

## Описание алгоритма

Заметим, что вершину, из которой не ведет ни одно ребро, можно всегда поставить последней, а такая вершина в ациклическом графе всегда есть (иначе можно было бы идти по обратным рёбрам бесконечно). Из этого сразу следует конструктивное доказательство: будем итеративно класть в массив вершину, из которой ничего не ведет, и убирать ее из графа. После этого процесса массив надо будет развернуть.

Этот алгоритм проще реализовать, обратив внимание на времена выхода вершин в DFS. Вершина, из которой мы выйдем первой — та, у которой нет новых исходящих ребер. Дальше мы будем выходить только из тех вершин, которые если и имеют исходящие ребра, то только в те вершины, из которых мы уже вышли.

Следовательно, достаточно просто выписать вершины в порядке выхода из DFS, а затем полученный список развернуть, и мы получим какую-то из корректных топологических сортировок.