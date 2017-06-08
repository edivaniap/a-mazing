/**
* @file main.cpp
* @version 1.0  
* @title Main A-mazing
* @brief Faz chamada da solução do labirinto
* @author Edivânia Pontes
* @date 08/06/2017
*/

#include <iostream>
#include "amazing.hpp"

int main(int argc, char const *argv[])
{
	Maze labirinto;	

	// tenta preencher labirinto do arquivo passado por argumento
	if ( argc > 1) {
		if( not labirinto.fill( argv[1] ) )
			return -1;
	} else {
		std::cout << ">>> main(): Por favor, entre com nome do arquivo da próxima vez.\n";
		return -1;
	}

	labirinto.render();
	std::cout << "\t\n>>> ENTER PARA INCIAR\n";

	// --- SOLVING
	labirinto.solve();

	return 0;
}