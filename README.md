# 🔄 `push_swap` — 42 School Project  
> 🧠 Sorting integers using two stacks and the least number of operations.  
> Ordenando números inteiros com duas pilhas e o menor número possível de operações.

---

## 🧠 🇧🇷 Descrição

O **`push_swap`** é um dos projetos mais desafiadores da **Escola 42**.  
O objetivo é criar um programa que **ordene uma lista de números inteiros** usando apenas **duas pilhas (A e B)** e um conjunto limitado de **operações predefinidas** — tudo com o **menor número de movimentos possível**.

O programa recebe como argumento uma sequência de números e deve exibir, na saída padrão, a sequência de operações que resultam na ordenação da pilha A em ordem crescente.

Esse projeto combina **lógica algorítmica**, **otimização**, **manipulação de estruturas de dados** e **boas práticas de código em C**.

---

## 🧠 🇺🇸 Description

**`push_swap`** is one of the most challenging projects at **42 School**.  
The goal is to build a program that **sorts a list of integers** using only **two stacks (A and B)** and a limited set of **predefined operations**, achieving the **lowest possible number of moves**.

The program receives a sequence of numbers as arguments and outputs the sequence of operations that will sort stack A in ascending order.

This project blends **algorithmic logic**, **optimization**, **data structure management**, and **clean, efficient C coding**.

---

## ⚙️ 🇧🇷 Funcionamento

O programa começa lendo e validando os números passados como argumento.  
Todos são armazenados na **pilha A**. A **pilha B** começa vazia.  
A partir daí, o programa executa as operações necessárias para ordenar A com o mínimo de movimentos.

As operações permitidas são:

| Operação | Ação |
|-----------|------|
| `sa` / `sb` | Troca os dois primeiros elementos da pilha A ou B |
| `ss` | Troca os dois primeiros de ambas pilhas |
| `pa` / `pb` | Move o topo de uma pilha para a outra |
| `ra` / `rb` | Roda a pilha (o topo vai para o fim) |
| `rr` | Roda ambas as pilhas |
| `rra` / `rrb` | Rotação inversa (o último vai para o topo) |
| `rrr` | Rotação inversa de ambas as pilhas |

### 💡 Estratégia de Ordenação

A abordagem utilizada é uma variação do algoritmo **Turk Sort**, que combina lógica de custo mínimo com movimentação eficiente entre as pilhas.

Etapas:
1. Encontra o **nó mais barato (cheapest)** de mover.  
2. Calcula o **custo total de movimentação** entre as pilhas.  
3. Executa rotações e *pushes* otimizados.  
4. Garante que a pilha A termine totalmente ordenada.

---

## ⚙️ 🇺🇸 How it Works

The program starts by reading and validating the input numbers.  
All numbers are stored in **stack A**, while **stack B** is initially empty.  
From there, it performs a sequence of allowed operations to sort A in ascending order with as few moves as possible.

Allowed operations:

| Operation | Action |
|------------|---------|
| `sa` / `sb` | Swap the first two elements of stack A or B |
| `ss` | Swap both stacks simultaneously |
| `pa` / `pb` | Push the top element from one stack to the other |
| `ra` / `rb` | Rotate a stack (top element moves to bottom) |
| `rr` | Rotate both stacks |
| `rra` / `rrb` | Reverse rotate a stack (bottom moves to top) |
| `rrr` | Reverse rotate both stacks |

### 💡 Sorting Strategy

The algorithm follows a **Turk Sort**–style approach, focusing on minimizing the number of operations.

Steps:
1. Identify the **cheapest node** to move.  
2. Calculate **movement cost** between stacks.  
3. Execute optimized rotations and pushes.  
4. Ensure stack A ends up fully sorted.

---

## 🧪 🇧🇷 Compilação e uso

```bash
# Compilar o programa
make

# Executar exemplo
./push_swap 4 67 3 87 23

Saída esperada (sequência de operações):
pb
pb
sa
ra
pa
pa
```

Para verificar o número de movimentos:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

---

### 🧰 Estrutura de Arquivos / File Structure

```bash
📂 push_swap/
├── push_swap.c
├── push_swap.h
├── operations/
│   ├── push.c
│   ├── swap.c
│   ├── rotate.c
│   ├── reverse_rotate.c
├── utils/
│   ├── stack_utils.c
│   ├── error_handling.c
│   ├── parsing_utils.c
├── sorting/
│   ├── sort_three.c
│   ├── sort_turk.c
│   ├── cost_analysis.c
├── Makefile
└── README.md
```

---

### 🏁 Resultado / Result

✅ Ordenação correta e estável |
✅ Implementação dentro da Norma da 42 |
✅ Eficiência em número de operações |
✅ Estrutura modular e de fácil leitura |
✅ Sem memory leaks (checado com Valgrind)

---

### 👩‍💻 Créditos / Credits

Autor: Tai Fanfa |
Projeto: push_swap (42 School) |
Linguagem: C |
Licença: MIT |



