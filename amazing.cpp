#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <fstream>
#include <cassert>

class Maze
{
public:
	/*! estrutura de uma posição */
	struct Position
	{
		size_t x; /*<! linha da posição */
		size_t y; /*<! coluna da posição */

		void set( size_t x_, size_t y_ )
		{
			x = x_;
			y = y_;
		}
	};

	/*! enumeração de direções 

			 north
	    west __|__ east
		       |     
		     south
	*/
	enum Direction
	{
		/*NORTH = 0, //<! ( 0,  1)
		SOUTH = 1, //<! ( 0, -1)
		WEST = 2,  //<! (-1,  0)
		EAST = 3;  //<! ( 1,  0)*/
	};

	/*! estrutura que vai definir o significado de cada caracter no mapa/labirinto */
	struct Map
	{
		char actor;     /*<! Caracter que define um ator */ 
		char wall;      /*<! Caracter que define uma parede */
		char way = ' '; /*<! Caracter que define um caminho aberto */
		char out;       /*<! Caracter que define a saída */
		char marker;    /*<! Caracter que define um marcador */
	};

private:
	//std::vector< std::vector< char > > m_maze;
	std::vector< std::string > m_maze;
	size_t m_nrow; //numero linha
	size_t m_ncol; //numero coluna
	Position m_initial; //posição inicial
	Map m_map;

public:
	Maze()
	{
		m_nrow = 0;
		m_ncol = 0;
		m_initial.set(0, 0);
	}

	/*! 
	 * @brief preenche vector e define os caracteres do mapa através do arquivo passado
	 * @param filename nome do arquivo do usuário
	 * @return "true" se conseguir ler o arquivo, "false" caso contrário
	 */
	bool fill( std::string filename )
	{
		std::ifstream ifs;

	    std::cout << "\t>>> Preparando para ler [" << filename << "]...\n";
	    std::cout << "\t--------------------------------------------------\n";

	    ifs.open( filename.c_str() ); //tentar abrir aquivo

	    if( ifs.fail() ) { //verificando erro
	        std::cout << "\t>>> fill(): Erro. Não foi possível abrir o arquivo [" << filename << "], tente novamente.\n";
	        return false;
	    }

	    std::cout << "\t>>> Arquivo lido com sucesso!\n\n";

    	m_map.wall = ifs.get();	    
    	m_map.actor = ifs.get();	    
    	m_map.out = ifs.get();
    	m_map.marker = ifs.get();

    	while( ! ifs.eof() )
    	{
    		std::string line;
    		getline ( ifs, line );  //ler linha

    		std::cout << "linha lida: "<< line<< "\n";    		
    		m_maze.push_back( line ); //insere string lida no vector
       	}

       	m_maze.erase( m_maze.begin() ); //retirar 1ª linha que está sendo lida em branco

       	m_nrow = m_maze.size();
       	m_ncol = m_maze.back().size(); //coluna é igual ao numero de caracteres na ultima string do maze

	    ifs.close(); //fechar arquivo
	    return true;
	}

	/*! 
	 * @brief pega a posição inicial do ator
	 * @return posição inicial
	 */
	Position get_start_position( void )
	{
		for( auto i = 0u; i < m_nrow; i++)
			for( auto j = 0u; j < m_ncol; j++)
				if( m_maze[i][j] == m_map.actor )
					m_initial.set(i, j);

		return m_initial;
	}

	/*! 
	 * @brief verifica se a posição é a saída 
	 * @param pos posição que está sendo analisada
	 * @return "true" se for a saída, "false" caso contrário
	 */
	bool is_outside( const Position& pos )
	{
		return ( m_maze[pos.x][pos.y] == m_map.out );
	}

	bool is_blocked( const Position& pos, const Direction& dir )
	{
		/*todo*/
		return false;
	}

	/*! marca posição como visitada */
	void mark_cell( const Position& pos )
	{
		m_maze[pos.x][pos.y] = m_map.marker;
	}

	/*! desmarca visita de uma posição */
	void unmark_cell( const Position& pos )
	{
		if( is_marked(pos) )
			m_maze[pos.x][pos.y] = m_map.way;
	}

	/*! verifica se posição está marcada como visitada */
	bool is_marked(const Position& pos)
	{
		return ( m_maze[pos.x][pos.y] == m_map.marker );
	}

	/*! mostra na tela situação atual do labirinto */
	void render( void )
	{
		std::cout << "\t\t A-Mazing!\n";
		std::cout << "\t -------------------------\n\n";

		std::cout << "\t Legenda: \n"; 
		std::cout << "\t > Ator:            "<< m_map.actor << "\n";
		std::cout << "\t > Parede:          "<< m_map.wall << "\n";
		std::cout << "\t > Caminho livre:   "<< m_map.way << "\n";
		std::cout << "\t > Caminho marcado: "<< m_map.marker << "\n";
		std::cout << "\t > Saída:           "<< m_map.out << "\n\n";
		std::cout << "\t > Num linhas:  "<< m_nrow << "\n";
		std::cout << "\t > Num colunas: "<< m_ncol << "\n\n";

		for( auto i = 0u; i < m_nrow; i++)
	            std::cout << "\t\t" << m_maze[i] << std::endl;
	}
};

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

	Maze::Position pos_i = labirinto.get_start_position();

	std::cout << "Posição inicial do ator: (" << pos_i.x << ", " << pos_i.y << ")\n";

	/* asserts */
	assert( pos_i.x == 6 );
	assert( pos_i.y == 7 );

	return 0;
}