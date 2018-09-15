#include "player.h"
#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>
#include <vector>

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
vector<pair<pii,pii> > generate_neighbour(int id ,board b)
{
	int direction_x[] = {0,0,1,-1,1,-1};
	int direction_y[] = {1,-1,0,0,1,-1};

	vector<pair<pii,pii> > neighbours ;

	 pair<pii,pii> new_move ;
	//starting pii should be ring
	for (int i = 0 ; i < 5 ; i++)
	{
		//take a ring pii and 
		pii starting ;
		if (id == 1)
		{
			starting = (b.ring_p1).at(i);
		}
		else
		{
			starting = (b.ring_p2).at(i);
		}
  
		new_move.F = starting ;
		//check it is a valid ring ?
		if (starting.F!=100) //validring function tellls validity of rings
		{
			//then generate termination piis

			//traverse in 6 directions
			for(int j = 0 ; j < 6 ; j++)
			{
				int marker_crossed = 0; // signifying marker has crossed or not 
				int new_x = starting.F + direction_x[j];
				int new_y = starting.S + direction_y[j];
				while(b.isValid(new_x,new_y)==true)
				{
					pii current ;
					current.F = new_x ;
					current.S = new_y ;
					if (b.isEmpty(new_x , new_y) == true )
					{
						new_move.S = current ;
						neighbours.push_back(new_move);
						if (marker_crossed == 1)
						{
							break ;
						}

					}
					if (b.value(new_x,new_y) == 3 | b.value(new_x,new_y) == 4 ) 
					{
						break; //ring encountered 
					}
					else if (b.value(new_x,new_y) == 0 | b.value(new_x,new_y) == 1 ) 
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
	middle.F = 0;
	middle.S = 0;
	
	int position ;
	if (b.isEmpty(0,0))
	{
		places.push_back(middle);
	}
	for(int i = 1 ; i <= 5 ; i++ )
	{
		int hexagon = i;
		for (int j = 0 ; j < 6*i ; j++)
		{
			int position = j ;
			pii current =  b.convert(hexagon,position);
			if (b.isEmpty(current.F,current.S)== true)
			{
				places.push_back(current);
			}
		}
	}
	return places;
	

}

string best_ring(vector<pii>  positions , board b)
{
	pii best = b.best_ring_place(positions);
	pii hexa = b.to_hexagon(best.F,best.S); 
	

	//generating string format of move ;
	string  final = "P " ;
	final.append(to_string(hexa.F));
	final.append(" ");
	final.append(to_string(hexa.S));
	return final;
}



void player::execute_move(int id ,string str,board b)
{
	
	vector< std::vector<pair<pii,pii> > > rows = b.find_row();
	std::vector<pair<pii,pii> > current_row_list ;
	std::vector<pii> ring_list ;
	if (id == 1)
	{
		current_row_list = rows.at(0);
		ring_list = b.ring_p1 ;
	}
	else
	{
		current_row_list = rows.at(1);
		ring_list = b.ring_p2 ;
	}
	for (int i = 0 ; i < current_row_list.size();i++)
	{
		pair<pii,pii> selected_row = current_row_list.at(0) ;
		//correct the selected row heuristic 
		b.remove_row((selected_row.F).F,(selected_row.F).S,(selected_row.S).F,(selected_row.S).S);
		
		//select the ring to remove

		for (int j = 0 ; j < 5 ; j++)
		{
			pii currRing = ring_list.at(j);
			if (currRing.F != 100 && currRing.S != 100)
			{
				b.remove_ring(id ,currRing.F,currRing.S);  //reduntant value to current ring is set inside it ;
				break;
			}
		}
	}


	vector<string> token = split(str,' ');
	string move_type = token.at(0); 
	string hexagon = token.at(1);
	string position  = token.at(2);

 	pii start = b.convert(stoi(hexagon),stoi(position));

	if (move_type == "P" )
	{
		if (b.isEmpty(start.F,start.S) )
		{
			b.place_ring(id , start.F , start.S);
			cout << str << endl ;
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
		pii end = b.convert(stoi(hexagon),stoi(position));


		if (next_step == "M")
		{
			b.move_ring(id , start.F , start.S , end.F , end.S);
			cout << str << endl ;
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
	rows = b.find_row();
	if (id == 1)
		current_row_list = rows.at(0);
	else
		current_row_list = rows.at(1);
	for (int i = 0 ; i < current_row_list.size();i++)
	{
		pair<pii,pii> selected_row = current_row_list.at(0) ;
		//correct the selected row heuristic 
		b.remove_row((selected_row.F).F,(selected_row.F).S,(selected_row.S).F,(selected_row.S).S);
		//select the ring to remove
		for (int j = 0 ; j < 5 ; j++)
		{
			pii currRing = ring_list.at(j);
			if (currRing.F != 100 && currRing.S != 100)
			{
				b.remove_ring(id ,currRing.F,currRing.S); 
				break;
			}
		}
	}





	
}

