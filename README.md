# Ponteiros em C

Coleção de exercícios em C voltados à manipulação de memória por meio de ponteiros, arrays, estruturas, matrizes e passagem de dados por referência.

Os exemplos foram desenvolvidos utilizando a biblioteca padrão da linguagem C e compilação com GCC.

## Exercícios

### Exercício 01 — Ponteiros e endereços

Introdução ao uso de ponteiros, operadores `&` e `*`, acesso ao conteúdo apontado e alteração de variáveis através de seus endereços.

Também compara o tamanho de um `int` com o tamanho de um ponteiro utilizando `sizeof`.

---

### Exercício 02 — Troca de valores

Implementação de uma função que recebe ponteiros para duas variáveis e realiza a troca de seus valores.

Inclui tratamento de ponteiros `NULL` e demonstra a alteração direta das variáveis originais.

---

### Exercício 03 — Múltiplos valores de saída

Implementação de uma função de divisão inteira que retorna quociente e resto através de ponteiros.

A função também trata divisão por zero e ponteiros de saída inválidos.

---

### Exercício 04 — Estatísticas de um array

Percorre um array utilizando aritmética de ponteiros para calcular:

- menor valor;
- maior valor;
- soma dos elementos.

Os resultados são retornados através de ponteiros de saída.

---

### Exercício 05 — Inversão de array

Inverte os elementos de um array no próprio local, sem utilizar um segundo vetor.

A implementação utiliza dois ponteiros:

- um iniciando no primeiro elemento;
- outro iniciando no último elemento.

Os ponteiros avançam em direções opostas até completar a inversão.

---

### Exercício 06 — Ponteiros para estruturas

Manipulação de uma estrutura `Sensor` através de um ponteiro.

A temperatura é atualizada e o status do sensor é definido de acordo com o valor recebido:

- `B` — temperatura baixa;
- `N` — temperatura normal;
- `A` — temperatura alta.

Também utiliza geração de valores pseudoaleatórios para simular novas temperaturas.

---

### Exercício 07 — Busca em array de estruturas

Busca um sensor pelo seu identificador dentro de um array de estruturas.

A função retorna:

- o endereço do sensor encontrado;
- `NULL` caso o identificador não exista.

O ponteiro retornado permite modificar diretamente o elemento original do array.

---

### Exercício 08 — Matrizes e ponteiros

Percorre uma matriz utilizando ponteiros para linhas.

Cada linha é acessada através de aritmética de ponteiros e sua soma é armazenada em um array de resultados.

Exemplo de acesso utilizado:

```c
*(*(matriz + i) + j)
```

---

### Exercício 09 — Gerenciamento de sensores e amostras

Integra os principais conceitos utilizados nos exercícios anteriores.

Cada sensor possui:

- identificador;
- nome;
- array de amostras;
- quantidade de amostras armazenadas.

O programa permite:

- buscar sensores pelo identificador;
- adicionar novas amostras;
- controlar o limite de armazenamento;
- calcular a média das leituras;
- apresentar os dados atualizados;
- tratar sensores inexistentes e ponteiros inválidos.

## Compilação

Os arquivos podem ser compilados com GCC utilizando:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic exercicio09.c -o exercicio09.exe
```

Para executar:

```bash
./exercicio09.exe
```

Substitua `exercicio09.c` pelo arquivo correspondente ao exercício desejado.

## Estrutura

```text
exercicio01.c
exercicio02.c
exercicio03.c
exercicio04.c
exercicio05.c
exercicio06.c
exercicio07.c
exercicio08.c
exercicio09.c
```