#include "player.h"
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
using namespace std;


std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}
vector<move<point,point> > generate_neighbour(int id )
{
	//starting point should be ring
	//traverse in 6 directions
	//stop if ring comes
	//stop if marker sequence ends
	//stop if out of the board
}
move<point,point> player::generate_move(int id , board b)
{

} 


string generate_ring_place(int id , board b)
{
	//iterate to all the positions 
	vector<pair<int,int> > positions ;
	pair middle ;
	middle.x = 0;
	middle.y = 0;
	
	int position
	if (board::isEmpty(0,0))
	{
		positions.push_back(middle);
	}
	for(int i = 1 ; i < 5 ; i++ )
	{
		int hexagon = i;
		for (int j = 0 ; j < 6*i < j ++)
		{
			int position = j ;
			pair<int, int> current =  board::convert(hexagon,position);
			if (isEmpty(current.x,current.y)== true)
			{
				positions.push_back(current);
			}
		}
	}
	pair


}




void player::execute_move(int id ,string str)
{
	//check the board 
	board::check_board();

	vector<string> token = split(str,' ');
	string move_type = token.at(0); 
	string hexagon = token.at(1);
	string position  = token.at(2);

 	pair start = board::convert(hexagon,position);

	if (move_type == "P" )
	{
		if (board::isEmpty(start.x,start.y) )
		{
			board::place_ring(id , start.x , start.y);
		}
		else
		{
			cout << "non empty position" << endl ;
			return ;
		}
	}
	else if  (move_type == "S" )
	{
		string next_step = token.at(3);
		hexagon = token.at(4);
		position = token.at(5);
		pair end = board::convert(hexagon,position);


		if (next_step == "M")
		{
			board::move_ring(id , start.x , start.y , end.x , end.y);
		}
		else
		{
			cout << "invalid move" << endl ;
		}

	}
	else
	{
		cout << "invalid move " << endl ;
	}
	
	//check the board
	board::check_board();
	
}

