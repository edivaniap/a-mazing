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

		/*! inicializador */
		Position( size_t x_=0, size_t y_=0 ) 
			: x(x_)
			, y(y_)
		{ /*empty*/ }

		/*! configurador */
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
		NORTH = 0, //<! (-1, 0)
		SOUTH = 1, //<! ( 1, 0)
		WEST = 2,  //<! ( 0,-1)
		EAST = 3   //<! ( 0, 1)
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
	std::vector< std::string > m_maze; /*<! matriz labirinto */ 
	size_t m_nrow; /*<! número de linhas do labirinto */
	size_t m_ncol; /*<! número de colunas do labirinto */
	Map m_map; /*<! legenda de caracteres */

public:
	Maze()
	{
		m_nrow = 0;
		m_ncol = 0;
	}

	/*! 
	 * @brief preenche vector e define os caracteres do mapa através do arquivo passado
	 * @param filename nome do arquivo do usuário
	 * @return "true" se conseguir ler o arquivo, "false" caso contrário
	 */
	bool fill( std::string filename )
	{
		std::ifstream ifs;
		system("clear");
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
    		m_maze.push_back( line ); //insere string lida no vector
       	}

       	m_maze.erase( m_maze.begin() ); //retirar 1ª linha que está sendo lida em branco

       	while( m_maze.back() == "" )
       	{
       		m_maze.pop_back(); //retirar ultima linha se estiver em branco
       	}

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
		Position m_initial;

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
		if( not(pos.x >= 0 and pos.x < m_nrow) and not(pos.y >= 0 and pos.y < m_ncol)  )
		{
			std::cout << "is_outside(): Erro. Posição inválida: coordenada(s) fora do intervalo.";
			return false;
		}
		
		return ( m_maze[pos.x][pos.y] == m_map.out );
	}

	/*! 
	 * @brief verifica se uma direção, a partir de determinada posição está, está bloqueada 
	 * @param pos posição em foco da análise
	 * @param dir direção a ser analisada
	 * @return "true" se estiver a direção bloqueada, "false" caso contrário
	 */
	bool is_blocked( const Position& pos, const int& dir )
	{
		switch( dir ) 
		{
			case Direction::NORTH:
				return ( m_maze[pos.x-1][pos.y] == m_map.wall
					or m_maze[pos.x-1][pos.y] == m_map.marker );

			case Direction::SOUTH:
				return ( m_maze[pos.x+1][pos.y] == m_map.wall
					or m_maze[pos.x+1][pos.y] == m_map.marker );

			case Direction::WEST: 
				return ( m_maze[pos.x][pos.y-1] == m_map.wall
					or m_maze[pos.x][pos.y-1] == m_map.marker );

		  	case Direction::EAST: 
		  		return ( m_maze[pos.x][pos.y+1] == m_map.wall
		  				or m_maze[pos.x][pos.y+1] == m_map.marker );

		  	default:
		  		return false;
		}
	}

	/*!
	 * @brief marca posição como visitada
	 * @param pos posição que deve ser marcada
	 */
	void mark_cell( const Position& pos )
	{
		if( not(pos.x >= 0 and pos.x < m_nrow) and not(pos.y >= 0 and pos.y < m_ncol)  )
		{
			std::cout << "mark_cell(): Erro. Posição inválida: coordenada(s) fora do intervalo.";
			return;
		}

		m_maze[pos.x][pos.y] = m_map.marker;
	}

	/*!
	 * @brief desmarca visita de uma posição
	 * @param pos posição que deve ser desmarcada
	 */
	void unmark_cell( const Position& pos )
	{
		if( is_marked(pos) )
			m_maze[pos.x][pos.y] = m_map.way;
	}

	/*! 
	 * @brief verifica se posição está marcada como visitada
	 * @param posição que está sendo analisada
	 * @return "true" se a posição está marcada, "false" caso contrário
	 */
	bool is_marked(const Position& pos)
	{
		return ( m_maze[pos.x][pos.y] == m_map.marker );
	}

	/*!
	 * @brief mostra na tela situação atual do labirinto
	 */
	void render( void )
	{
		//system("clear");
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

	Position adjacent_position( Position pos, int dir )
	{
		Position result;

		switch( dir ) 
		{
			case Direction::NORTH:
				result.set(pos.x-1, pos.y);
				break;
				
			case Direction::SOUTH:
				result.set(pos.x+1, pos.y);
				break;

			case Direction::WEST: 
				result.set(pos.x, pos.y-1);
				break;
				
		  	case Direction::EAST: 
				result.set(pos.x, pos.y+1);
				break;
		}

		return result;
	}

	void solve() 
	{
		if( find_path( get_start_position() ) )
			std::cout << "\t>>> Labirinto resolvido!\n";
		else 
			std::cout << "\t>>> Labirinto sem saída!\n"; 
	}

	/*! backintrack function */
	bool find_path( Position start )
	{
		if( is_outside(start) )
			return true;
		if( is_marked(start) )
			return false;

		mark_cell(start);
		

		std::cin.ignore(); //esperar enter
		system("clear"); //limpar tela
		render();
		std::cout << "\t\n>>> ENTER PARA PRÓXIMO PASSO\n";

		for (int dir = Direction::NORTH; dir <=  Direction::EAST; ++dir)
		{
			if( not is_blocked(start, dir) )
			{
				if( find_path( adjacent_position(start, dir) ))
					return true;
			}
		}

		unmark_cell(start);

		std::cin.ignore(); //esperar enter
		system("clear"); //limpar tela
		render();
		std::cout << "\t\n>>> ENTER PARA PRÓXIMO PASSO\n";

		return false;
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
	std::cout << "\t\n>>> ENTER PARA INCIAR\n";
	
	// --- SOLVING
	labirinto.solve();

	return 0;
}