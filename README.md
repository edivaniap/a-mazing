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

- [X] *fill* : preenche vector e define os caracteres do mapa através do arquivo passado
- [X] *Position get_start_position* : pega a posição inicial do ator
- [X] *is_outside* : verifica se uma posição é a saída 
- [ ] *is_blocked* : 
- [ ] *mark_cell* : marca posição como visitada
- [ ] *unmark_cell* : desmarca visita de uma posição
- [X] *is_marked* : verifica se posição está marcada
- [X] *render* : mostra na tela situação atual do labirinto

**Main**

- [ ] *solve_maze* : função que utilizará backtraking para resolver o labirinto
		
# How to build

	`$`


# Git repository

[**projetos.imd.ufrn.br/edivaniap/amazing**](http://projetos.imd.ufrn.br/edivaniap/amazing)


# Authorship

Program developed by _Edivânia Pontes de Oliveira_ (< *edivaniap@ufrn.edu.br* >), 2017.1

&copy; IMD/UFRN 2017.
