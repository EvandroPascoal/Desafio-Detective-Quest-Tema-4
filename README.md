# 🕵️‍♂️ Detective Quest – Exploração da Mansão com Árvore de Pistas

Este projeto implementa uma pequena aventura de investigação em C, onde o jogador explora salas de uma mansão, coleta pistas e as armazena em uma **árvore binária de busca (BST)** para exibição em ordem alfabética.

O código utiliza estruturas de dados, lógica de navegação e organização de pistas.

---

## 🧩 Funcionalidades

* Explorar salas conectadas em formato de árvore binária simples
* Cada sala pode conter uma pista ou estar vazia
* Pistas encontradas são armazenadas automaticamente em uma **árvore binária de busca**
* Navegação interativa entre salas através do terminal
* Exibição das pistas coletadas em **ordem alfabética**

---

## 🏠 Estruturas do Jogo

### **Sala (`struct Sala`)**

Representa um cômodo da mansão.

Contém:

* `nome` — nome da sala
* `pista` — pista encontrada no local (ou vazio)
* `esquerda` — ponteiro para sala à esquerda
* `direita` — ponteiro para sala à direita

### **PistaNode (árvore BST)**

Onde ficam armazenadas as pistas coletadas:

* Inseridas seguindo regras de árvore binária de busca
* Impressas em ordem alfabética via percurso in-order

---

## 🌳 Mapa da Mansão

A estrutura de salas é montada assim:

```
             Hall de Entrada
              /           \
     Sala de Estar       Cozinha
       /       \              \
Biblioteca   Quarto       Porão
```

Cada sala pode conter uma pista.

---

## 🎮 Jogabilidade

Durante a exploração o jogador pode:

* Ir para a sala à **esquerda** (`e`)
* Ir para a sala à **direita** (`d`)
* **Sair** da exploração (`s`)

Exemplo de interação:

```
Você está no(a): Sala de Estar
>> Pista encontrada: Caderno rasgado no sofá
[e] Ir para a esquerda: Biblioteca
[d] Ir para a direita: Quarto Principal
[s] Sair da exploração
```

---

## 📝 Saída Final

Ao terminar a exploração, o programa exibe as pistas coletadas:

```
=== Pistas coletadas (em ordem alfabética) ===
- Caderno rasgado no sofá
- Chave enferrujada
- Copo quebrado no chão
- Página arrancada de um diário
- Pegada misteriosa no tapete
```

---

## 🚀 Como Compilar e Executar

### **Compilar**

```bash
gcc main.c -o detective
```

### **Executar**

```bash
./detective
```

---

## 🎯 Objetivo do Projeto

* Praticar uso de **árvores binárias (BST)**
* Criar uma lógica de navegação usando ponteiros
* Implementar coleta e organização de dados
* Simular um mini jogo interativo no terminal
