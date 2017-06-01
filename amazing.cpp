#include <iostream>

class Maze
{
private:
	char * m_maze;
	char   m_wall;
	char   m_actor;
	char   m_wayout;
	char   m_marker;
public:
	Maze()
	{
		/*todo*/
	}

	~Maze()
	{
		/*todo*/
	}

	Position get_start_position()
	{
		/*todo*/
	}

	bool is_outside(const Position& pos)
	{
		/*todo*/
	}

	bool is_blocked(const Position& pos, const Direction& dir)
	{
		/*todo*/
	}

	void mark_cell(const Position& pos )
	{
		/*todo*/
	}

	void unmark_cell(const Position& pos )
	{
		/*todo*/
	}

	bool is_marked(const Position& pos)
	{
		/*todo*/
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}