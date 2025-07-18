## Компоненты сильной связности

Две вершины ориентированного графа связаны сильно (англ. strongly connected), если существует путь из одной в другую и наоборот. Иными словами, они обе лежат в каком-то цикле.

Понятно, что такое отношение транзитивно: если $a$ и $b$ сильно связны, и $b$ и $c$ сильно связны, то $a$ и $c$ тоже сильно связны. Поэтому все вершины распадаются на компоненты сильной связности — такое разбиение вершин, что внутри одной компоненты все вершины сильно связаны, а между вершинами разных компонент сильной связности нет.

## Описание алгоритма

Часто рассматривают граф, составленный из самих компонент сильной связности, а не индивидуальных вершин. Очевидно, такой граф уже будет ациклическим, и с ним проще работать. Задачу о сжатии каждой компоненты сильной связности в одну вершину называют _конденсацией графа_.

Если мы уже знаем, какие вершины лежат в каждой компоненте сильной связности, то построить граф конденсации несложно: нужно провести некоторые манипуляции со списками смежности, заменив для всех ребер номера вершин номерами их компонент, а затем объединив списки смежности для всех вершин каждой компоненты. Поэтому сразу сведем исходную задачу к нахождению самих компонент.

Заметим следущий факт: пусть $A$ и $B$ — две различные компоненты сильной связности, и пусть в графе конденсации между ними есть ребро $A \longrightarrow B$. Тогда:
$$
\max\limits_{a \in A}(tout_a) > \max\limits_{b\in B}(tout_b),
$$
где $tout_i$ — время выхода из вершины $i$ при запуске DFS.

Из этого факта следует первая часть алгоритма. Отсортируем вершины по убыванию времени выхода. Рассмотрим компоненту сильной связности первой вершины в сортировке. В эту компоненту точно не входят никакие рёбра из других компонент — иначе нарушилось бы условие леммы, ведь у первой вершины $tout$ максимальный. Поэтому, если развернуть все рёбра в графе, то из этой вершины будет достижима своя компонента сильной связности $C$, и больше ничего — если в исходном графе не было рёбер **из** других компонент, то в транспонированном не будет ребер **в** другие компоненты.

После того, как мы сделали это с первой вершиной, мы можем пойти по топологически отсортированному списку дальше и делать то же самое с вершинами, для которых компоненту связности мы ещё не отметили.