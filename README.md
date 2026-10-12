# Ponteiros em C

Coleção de exercícios em linguagem C voltados ao estudo de ponteiros, endereços de memória, passagem de parâmetros por referência, aritmética de ponteiros e manipulação de arrays.

## Exercícios

### Exercício 1 — Ponteiros e endereços de memória

Introdução aos conceitos básicos de ponteiros.

Principais pontos:
- declaração de ponteiros;
- uso do operador `&` para obter o endereço de uma variável;
- uso do operador `*` para acessar o valor apontado;
- alteração de variáveis por meio de ponteiros;
- impressão de endereços com `%p`;
- uso de `sizeof` para comparar o tamanho de tipos e ponteiros.

### Exercício 2 — Troca de valores com ponteiros

Implementação de uma função que troca os valores de duas variáveis utilizando seus endereços de memória.

Principais pontos:
- passagem de endereços para funções;
- alteração direta das variáveis originais;
- desreferenciamento de ponteiros;
- uso de variável temporária;
- verificação de ponteiros `NULL`.

### Exercício 3 — Múltiplos resultados por meio de ponteiros

Implementação de uma função de divisão inteira que fornece dois resultados: quociente e resto.

Principais pontos:
- parâmetros de saída;
- divisão inteira;
- operador de resto `%`;
- tratamento de divisão por zero;
- validação de ponteiros `NULL`;
- uso do valor de retorno da função para indicar sucesso ou erro.

### Exercício 4 — Estatísticas de um array com aritmética de ponteiros

Cálculo do menor valor, maior valor e soma dos elementos de um array de inteiros.

O array é percorrido utilizando aritmética de ponteiros:

```c
*(valores + i)
```

em vez de:

```c
valores[i]
```

Principais pontos:
- relação entre arrays e ponteiros;
- aritmética de ponteiros;
- uso de `size_t`;
- passagem de arrays para funções;
- parâmetros de saída;
- validação de limites e ponteiros `NULL`.

## Compilação

Os exercícios podem ser compilados com GCC utilizando:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic exercicio01.c -o exercicio01.exe
```

Para executar:

```bash
./exercicio01.exe
```

Basta substituir `exercicio01.c` pelo arquivo do exercício que deseja compilar.

## Arquivos

```text
exercicio01.c
exercicio02.c
exercicio03.c
exercicio04.c
```

Novos exercícios serão adicionados ao repositório conforme o projeto evoluir.