# Atividade - Estrutura de Dados
O repositório foi criado com o intuito de realizar a atividade de teste de eficiência de diferentes algoritmos de ordenação em C++, bem como teste de desempenho na criação de árvores e listas, bem como o uso de diferentes métodos de busca nessas mesmas estruturas, proposta na matéria Estrutura de Dados da FGV-EMAp.

## Algorítmos de Ordenação

Os testes aqui realizados foram feitos para estruturas com 10000 dados, usando inteiros aleatórios de **1** a **100**. Foram criadas listas identicas a cada teste, assim, todos os algoritmos ordenaram uma cópia da mesma lista.

Com o csv dos tempos de cada algoritmo, realizamos uma análise sobre cada método de ordenação. Para começar, tiramos algumas estatísticas, como apresentado na tabela 1 abaixo:

Tabela 1: Algoritmos de Ordenação
|                | BubbleSort  | BubbleSortOtimizado | SelectionSort | SelectionSortOtimizado | InsertionSort | BucketSort |
|----------------|-------------|---------------------|---------------|------------------------|---------------|------------|
| Média          | 6,15E+08    | 3,15E+08            | 2,61E+08      | 2,93E+08              | 1,51E+08      | 9,26E+06   |
| Mediana        | 6,08E+08    | 3,10E+08            | 2,60E+08      | 2,91E+08              | 1,49E+08      | 8,95E+06   |
| Desvio Padrão  | 3,58E+07    | 1,95E+07            | 1,51E+07      | 1,63E+07              | 7,52E+06      | 8,77E+05   |

Então, resolvemos usar a **média** para plotar um gráfico, facilitando a comparação:

<img src="analise/grafico.png">

Agora, fica claro que o algoritmo que apresentou a melhor performace foi o **Bucket Sort**, seguido do **Insertion Sort** e do **Selection Sort Otimizado**, nessa ordem. O algoritmo de pior performace foi o **Bubble Sort**.

## Arvores e listas

Aqui, implementamos um código para a criação de uma árvore binária, onde os menores valores sempre são alocados à esquerda. Os algoritmos BFS (Breadth First Search) e DFS (Depth First Search) foram implementados considerando uma aplicação em uma árvore genérica, não necessariamente em uma árvore construída de uma forma específica.

Os testes aqui realizados foram feitos para estruturas com 10000 dados, usando inteiros aleatórios de **1** a **10000**, tanto para árvore quando para lista. Para a busca, escolhemos 5 inteiros aleatóriamente (os mesmos inteiros para todas as estruturas) e aplicamos cada um dos algoritmos. Então, tiramos a média dessas 5 buscas e adicionamos ao csv.

Segue abaixo a tabela 2 com os tempos médios e outras estatísticas relacionadas à criação de estruturas e aos tempos de busca:

Tabela 2: Tempos de Busca e Criação de Estruturas
|                | Tree Creation Time | List Creation Time | DFS Time | BFS Time | List Search Time |
|----------------|--------------------|--------------------|----------|----------|------------------|
| Média          | 1,53E+06           | 2,53E+05           | 1,23E+05 | 2,53E+05 | 4,53E+04         |
| Mediana        | 1,51E+06           | 2,46E+05           | 1,24E+05 | 2,54E+05 | 4,42E+04         |
| Desvio Padrão  | 1,14E+05           | 2,97E+04           | 1,31E+04 | 2,47E+04 | 8,32E+03         |

Esses dados são fundamentais para entendermos a eficiência e o desempenho das estruturas de dados em diferentes cenários e para diferentes propósitos. Vale ressaltar que há o uso de uma lista encadeada generica no algoritmo BFS, não otimizada para essa aplicação. Realizamos alguams otimizações simples, como a adição de um ponteiro apontando ao último elementos, assim podendo acessar esse elemento sem percorrer a lista.

Disclaimer: A execução do algoritmo foi feita usando o Visual Studio Code, executado com a placa de vídeo dedicada (pode ser insignificante) no sistema operaciona Ubuntu 23.10.


**Alunos:**\
Gustavo Tironi\
Luís Felipe de Abreu Marciano
