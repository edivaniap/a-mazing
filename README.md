# Introduction

**A-mazing** tem o objetivo de encontrar a saída de um labirinto com método conhecido como *backtracking*.  
O mapa do labirinto deve ser informado através de um arquivo pelo argumento do programa.


**Modelo do arquivo de entrada:**  
1. caracter que define a parede, ator, saída e marcador, respectivamente sem espa;  
2. labirinto.


**Backtracking**  
*Backtracking* é uma estratégia de resolução de problemas que funciona com o método "tentativa e erro".  
Uma solução parcialmente detectada é completada passo a passo até encontrar a solução final.


# TODO

**Class Maze**  

- [X] *fill* : Preenche vector e define os caracteres do mapa através do arquivo passado
- [X] *Position get_start_position* : Pega a posição inicial do ator
- [X] *is_outside* : Verifica se uma posição é a saída 
- [X] *is_blocked* : Verifica se uma direção, a partir de determinada posição está, bloqueada
- [X] *mark_cell* : Marca posição como visitada
- [X] *unmark_cell* : Desmarca visita de uma posição
- [X] *is_marked* : Verifica se posição está marcada
- [X] *render* : Mostra na tela situação atual do labirinto

**Main**

- [ ] *solve_maze* : Função que utilizará backtraking para resolver o labirinto
- [X] Testes com assert

	
# How to build

	`$ ...`


# Git repository

[**projetos.imd.ufrn.br/edivaniap/amazing**](http://projetos.imd.ufrn.br/edivaniap/amazing)
[**github.com/vaniati/a-mazing**](https://github.com/vaniati/a-mazing)


# Authorship

Program developed by _Edivânia Pontes de Oliveira_ (< *edivaniap@ufrn.edu.br* >), 2017.1

&copy; IMD/UFRN 2017.
