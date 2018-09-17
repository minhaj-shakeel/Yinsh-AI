#include "player.h"
#include "board.h"


int main()
{
	board b;
	player p(1);

	p.execute_move(1,"P 0 0" , b);
	p.execute_move(2,"P 4 14" , b);

	p.execute_move(1,"P 1 0" , b);
	p.execute_move(2,"P 3 4" , b);
	p.execute_move(1,"P 1 1" , b);
	p.execute_move(2,"P 1 3" , b);
	p.execute_move(1,"P 1 2" , b);
	p.execute_move(2,"P 5 7" , b);
	p.execute_move(1,"P 1 4" , b);
	p.execute_move(2,"P 3 3" , b);
	// p.execute_move(1,"P 2 1" , b);
	// p.execute_move(1,"P 3 1" , b);
	
	// p.execute_move(1,"P 4 0" , b);
	// p.execute_move(1,"S 4 0 M 3 0" , b);
	// p.execute_move(1,"S 3 0 M 2 0" , b);
	// p.execute_move(1,"S 2 0 M 1 0" , b);
	// p.execute_move(1,"S 1 0 M 0 0" , b);
	print_board(b);

	p.execute_move(1,"S 0 0 M 1 5" , b);
	p.execute_move(2,"S 3 4 M 3 6" , b);
	p.execute_move(1,"S 1 5 M 2 11" , b);
	p.execute_move(2,"S 1 3 M 2 5" , b);
	p.execute_move(1,"S 2 11 M 3 17" , b);
	p.execute_move(2,"S 4 14 M 5 21" , b);
	p.execute_move(1,"S 3 17 M 4 23" , b);
	p.execute_move(2,"S 5 21 M 5 23" , b);

	print_board(b);

	vector<string>  v = p.generate_neighbour(1 , b);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
	vector< std::vector<pair<pii,pii> > > fr = b.find_row();
	cout<<fr[0].size()<<"shbd"<<fr[1].size()<<endl;
	string str = p.generate_move(1,b);
		cout <<  str << "here"<<endl ;

	//v = b.ring_p1 ;
	// for (int i = 0 ; i < v.size() ; i++)
	// {
	// 	cout << v.at(i) << endl ;
	// }

	
	


	 
}