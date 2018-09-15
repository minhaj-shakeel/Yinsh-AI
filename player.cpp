#include "player.h"
#include <iostream>

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
vector<move<pii,pii> > generate_neighbour(int id )
{
	int direction_x[] = {0,0,1,-1,1,-1};
	int direction_y[] = {1,-1,0,0,1,-1};

	vector<move<pii,pii> > neighbours ;

	//starting pii should be ring
	for (int i = 0 ; i < 5 ; i++)
	{
		//take a ring pii and 
		pii starting ;
		if (id == 1)
		{
			starting = ring_p1.at(i);
		}
		else
		{
			starting = ring_p2.at(i);
		}
		move<pii,pii> new_move ;  
		new_move.start = starting ;
		//check it is a valid ring ?
		if (board::validRing(current)==true) //validring function tellls validity of rings
		{
			//then generate termination piis

			//traverse in 6 directions
			for(int j = 0 ; j < 6 ; j++)
			{
				int marker_crossed = 0; // signifying marker has crossed or not 
				int new_x = starting.x + direction_x[j];
				int new_y = starting.y + direction_y[j];
				while(board::isValid(new_x,new_y)==true)
				{
					pii current ;
					current.x = new_x ;
					current.y = new_y ;
					if (isEmpty(new_x , new_y) == true )
					{
						new_move.end = current ;
						neighbours.push_back(new_move);
						if (marker_crossed == 1)
						{
							break ;
						}

					}
					if (board::value(new_x,new_y) == 3 | board::value(new_x,new_y) == 4 ) 
					{
						break; //ring encountered 
					}
					else if (board::value(new_x,new_y) == 0 | board::value(new_x,new_y) == 1 ) 
					{
						marker_crossed = 1;
					}
					new_x += direction_x[j];
					new_y += direction_y[j];
				}

			}

		}

	}
	return neighbours ;
}


vector<pii> generate_ring_place(int id , board b)
{
	//iterate to all the positions 
	vector<pii > places ;
	pii middle ;
	middle.x = 0;
	middle.y = 0;
	
	int position
	if (board::isEmpty(0,0))
	{
		positions.push_back(middle);
	}
	for(int i = 1 ; i <= 5 ; i++ )
	{
		int hexagon = i;
		for (int j = 0 ; j < 6*i < j++)
		{
			int position = j ;
			pii current =  board::convert(hexagon,position);
			if (isEmpty(current.x,current.y)== true)
			{
				places.push_back(current);
			}
		}
	}
	return places;
	

}

string best_ring(vector<pii>  )
{
	pii best = board::best_ring_place(positions);
	pii hexa = board::to_hexagon(best.x,best.y); 
	//to_hexagon converts coordinates in hexagoal format ;

	//generating string format of move ;
	string  final = "P " ;
	final.append(to_string(hexa.x));
	final.append(" ");
	final.append(to_string(hexa.y));
	return final;
}



void player::execute_move(int id ,string str)
{
	//check the board 
	board::check_board();

	vector<string> token = split(str,' ');
	string move_type = token.at(0); 
	string hexagon = token.at(1);
	string position  = token.at(2);

 	pii start = board::convert(hexagon,position);

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
		pii end = board::convert(hexagon,position);


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

