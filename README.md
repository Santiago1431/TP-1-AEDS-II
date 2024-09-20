# Resolução de Labirintos em C

Este projeto implementa um algoritmo para resolver labirintos utilizando a linguagem C. O objetivo é encontrar um caminho da entrada ('E') até a saída ('S') em uma matriz que representa o labirinto.

## Estrutura do Projeto

- `main.c`: Contém a função principal e a lógica para exibir o menu e interagir com o usuário.
- `funcs.c` e `funcs.h`: Implementação das funções que manipulam o labirinto, incluindo a leitura do arquivo, identificação das coordenadas de entrada e saída, e a lógica de busca.
- `pilha.c` e `pilha.h`: Implementação de uma estrutura de dados pilha utilizada para armazenar as coordenadas do caminho percorrido.
- `Makefile`: Script para automatizar a compilação do projeto.

## Funcionalidades

- Carregamento de labirintos a partir de arquivos de texto.
- Exibição do labirinto na tela.
- Busca pelo caminho da entrada à saída utilizando PILHA.
- Exibição do caminho percorrido.

## Compilação e Execução

Para compilar o projeto, utilize o Makefile incluído no diretório:

```bash
make
