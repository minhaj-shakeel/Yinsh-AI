#include "player.h"
#include "board.h"


int main()
{
	board b;
	 player p(1);
	//cout << "1" ;
	 p.execute_move(1,"P 1 3" , b);
	 p.execute_move(1,"P 3 7" , b);
	 p.execute_move(1,"P 2 4" , b);
	 p.execute_move(1,"P 2 2" , b);
	 p.execute_move(1,"P 4 12 " , b);
	 

	 //p.execute_move(2,"P 4 14" , b);
	 p.execute_move(1,"S 1 3 M 0 0" , b);
	 p.execute_move(1,"S 0 0 M 1 0" , b);
	 p.execute_move(1,"S 1 0 M 2 0" , b);
	 p.execute_move(1,"S 2 0 M 3 0" , b);
	 p.execute_move(1,"S 3 0 M 4 0" , b);
	 p.execute_move(1,"S 4 0 M 4 1" , b);
	 p.execute_move(1,"S 4 1 M 4 2" , b);
	 p.execute_move(1,"S 4 2 M 4 3" , b);
	 p.execute_move(1,"S 4 3 M 4 4" , b);
	 p.execute_move(1,"S 4 4 M 4 5" , b);
    
	//p.execute_move(1,"RS 1 3 RE 3 0 X 4 4" , b);

	// p.execute_move(2,"P 3 4" , b);
	// p.execute_move(1,"P 1 1" , b);
	// p.execute_move(2,"P 1 3" , b);
	// p.execute_move(1,"P 1 2" , b);
	// p.execute_move(2,"P 5 7" , b);
	// p.execute_move(1,"P 1 4" , b);
	// p.execute_move(2,"P 3 3" , b);
	// // p.execute_move(1,"P 2 1" , b);
	// // p.execute_move(1,"P 3 1" , b);
	
	// // p.execute_move(1,"P 4 0" , b);
	// // p.execute_move(1,"S 4 0 M 3 0" , b);
	// // p.execute_move(1,"S 3 0 M 2 0" , b);
	// // p.execute_move(1,"S 2 0 M 1 0" , b);
	// // p.execute_move(1,"S 1 0 M 0 0" , b);
	// print_board(b);

	// p.execute_move(1,"S 0 0 M 1 5" , b);
	// p.execute_move(2,"S 3 4 M 3 6" , b);
	// p.execute_move(1,"S 1 5 M 2 11" , b);
	// p.execute_move(2,"S 1 3 M 2 5" , b);
	// p.execute_move(1,"S 2 11 M 3 17" , b);
	// p.execute_move(2,"S 4 14 M 5 21" , b);
	// p.execute_move(1,"S 3 17 M 4 23" , b);
	// p.execute_move(2,"S 5 21 M 5 23" , b);

	print_board(b);
	
	//p.execute_move(1,"RS 1 3 RE 3 0 X 4 5 RS 4 0 RE 4 4 X 4 5" , b);
	print_board(b);
	// vector<string> v = p.generate_initial_removal(1,b);
	//  cout << v.size() << endl ;
	 // vector<string>  v = p.generate_initial_removal(1 , b);
	 // for(int i=0;i<v.size();i++)
	 // {
	 // 		cout<<v[i] <<endl;
	 // }
	 //p.execute_move(1,"RS 0 0 RE 4 0 X 2 2" , b);
	// vector<string> s = p.generate_initial_removal(1,b);
	// for (int i = 0 ; i < s.size(); i++)
	// {
		
	// 	//p.execute_move(1,s[i],copy);
		
	// 	 cout << s[i]  << endl ;

	 
	// }
	 
	 //p.execute_move(1,s[1],b);
	 print_board(b);
	 vector<string> v = p.generate_neighbour(1 , b);
	 cout << v.size() << endl ;
	 for(int j=0;j<v.size();j++)
	 {
	 		cout<<v[j] <<endl;
	 }
	// vector< std::vector<pair<pii,pii> > > fr = b.find_row();
	// cout<<fr[0].size()<<"shbd"<<fr[1].size()<<endl;
	// string str = p.generate_move(1,b);
	// 	cout <<  str << "here"<<endl ;

	//v = b.ring_p1 ;
	// for (int i = 0 ; i < v.size() ; i++)
	// {
	// 	cout << v.at(i) << endl ;
	// }

	
	


	 
}