# Introduction

**A-mazing** tem o objetivo de encontrar a saída de um labirinto com método conhecido como *backtracking*.  
O mapa do labirinto deve ser informado através de um arquivo pelo argumento do programa.


**Modelo do arquivo de entrada:**  
O arquivo que descreve o labirinto deve conter na sua primeira linha, respesctivamente e sem espaços entre eles, caracteres que define:  

1. parede
2. ator
3. saída
4. marcador

Abaixo disso deve vir o mapa do labirinto formado com os caracteres de acordo com os definidos acima.


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
- [X] *find_path* : Tenta encontrar o caminho com backtracking recursivo
- [X] *solve* : Resolve o labirinto
- [X] *adjacent_position* : Retorna uma posição adjacente em determinada direção
- [X] Testes

	
# Compiling and runing

	`$ g++ -Wall -std=c++11 src/main.cpp -o bin/amazing`
	`$ ./bin/amazing mazes/<nome_arquivo_com_maze>`


# Git repository

[**projetos.imd.ufrn.br/edivaniap/amazing**](http://projetos.imd.ufrn.br/edivaniap/amazing)  
[**github.com/vaniati/a-mazing**](https://github.com/vaniati/a-mazing)


# Authorship

Program developed by _Edivânia Pontes de Oliveira_ (< *edivaniap@ufrn.edu.br* >), 2017.1  
Guided by _Selan R. dos Santos_

&copy; IMD/UFRN 2017.
