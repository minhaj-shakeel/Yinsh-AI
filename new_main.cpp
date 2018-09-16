#include "player.h"
#include "board.h"


int main()
{
	board b;
	player p(1);

	p.execute_move(1,"P 1 1" , b);
	p.execute_move(1,"P 1 2" , b);
	p.execute_move(1,"P 2 1" , b);
	p.execute_move(1,"P 3 1" , b);
	
	p.execute_move(1,"P 4 0" , b);
	p.execute_move(1,"S 4 0 M 3 0" , b);
	p.execute_move(1,"S 3 0 M 2 0" , b);
	p.execute_move(1,"S 2 0 M 1 0" , b);
	p.execute_move(1,"S 1 0 M 0 0" , b);
	print_board(b);

	vector<string>  v = p.generate_neighbour(1 , b);
	

	//v = b.ring_p1 ;
	for (int i = 0 ; i < v.size() ; i++)
	{
		cout << v.at(i) << endl ;
	}

	
	


	 
}