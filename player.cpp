#include "player.h"
#include "board.h"

#include <iostream>
#include <string>
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
void player::execute_move(int id ,string str,board& b)
{
	
	// vector< std::vector<pair<pii,pii> > > rows = b.find_row();
	// std::vector<pair<pii,pii> > current_row_list ;
	// std::vector<pii> ring_list ;
	// if (id == 1)
	// {
	// 	current_row_list = rows.at(0);
	// 	ring_list = b.ring_p1 ;
	// }
	// else
	// {
	// 	current_row_list = rows.at(1);
	// 	ring_list = b.ring_p2 ;
	// }
	// while (current_row_list.size()> 0)
	// {
	// 	pair<pii,pii> selected_row = current_row_list.at(0) ;
	// 	//correct the selected row heuristic 
	// 	b.remove_row((selected_row.F).F,(selected_row.F).S,(selected_row.S).F,(selected_row.S).S);
		
	// 	//select the ring to remove

	// 	for (int j = 0 ; j < 5 ; j++)
	// 	{
	// 		pii currRing = ring_list.at(j);
	// 		if (currRing.F != 100 && currRing.S != 100)
	// 		{
	// 			b.remove_ring(id ,currRing.F,currRing.S);  //reduntant value to current ring is set inside it ;
	// 			break;
	// 		}
	// 	}

	// 	rows = b.find_row();
	// 	if (id == 1)
	// 		current_row_list = rows.at(0);
	// 	else
	// 		current_row_list = rows.at(1);

	// }


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
			if (token.size() > 6) 
			{
				next_step = token.at(6);
				int hexagon_start = stoi(token.at(7));
				int position_start = stoi(token.at(8));

				if (next_step == "RS")
				{
					int hexagon_end  = stoi(token.at(10));
					int position_end = stoi(token.at(11));
					pii row_start , row_end ,ring_remove;
					row_start = b.convert(hexagon_start,position_start);
					row_end = b.convert(hexagon_end,position_end);
					b.remove_row(row_start.F,row_start.S,row_end.F,row_end.S);
					int ring_hexagon = stoi(token.at(13));
					int ring_position = stoi(token.at(14));
					ring_remove = b.convert(ring_hexagon,ring_position);
					b.remove_ring(id ,ring_remove.F,ring_remove.S);

					cout << str << endl ;

				}

			}
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
	// rows = b.find_row();
	// if (id == 1)
	// 	current_row_list = rows.at(0);
	// else
	// 	current_row_list = rows.at(1);
	// while (current_row_list.size() > 0)
	// {
	// 	pair<pii,pii> selected_row = current_row_list.at(0) ;
	// 	//correct the selected row heuristic 
	// 	b.remove_row((selected_row.F).F,(selected_row.F).S,(selected_row.S).F,(selected_row.S).S);
	// 	//select the ring to remove
	// 	for (int j = 0 ; j < 5 ; j++)
	// 	{
	// 		pii currRing = ring_list.at(j);
	// 		if (currRing.F != 100 && currRing.S != 100)
	// 		{
	// 			b.remove_ring(id ,currRing.F,currRing.S); 
	// 			break;
	// 		}
	// 	}
	// 	//updating rows to remove
	// 	rows = b.find_row();
	// 	if (id == 1)
	// 		current_row_list = rows.at(0);
	// 	else
	// 		current_row_list = rows.at(1);

	// }
	
}

vector<string> player::generate_neighbour(int id ,board& b)
{
	int direction_x[] = {0,0,1,-1,1,-1};
	int direction_y[] = {1,-1,0,0,1,-1};
	int rings_on_board ;

	board copyboard(b) ;

	if (id == 1)
	{
		rings_on_board = b.r1;
	}
	else
		rings_on_board = b.r2 ;


	vector<string> neighbours ;
	if (id == 1)
	{	
		if (flag1 == 0 )
		{
			return generate_ring_place(b);
		}
	}
	else
	{
		if (flag2 == 0 )
		{
			return generate_ring_place(b);
		}
	}
	string new_move = "";

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
  		
		//check it is a valid ring ?
		if (starting.F!=100) 
		{
			
			pii initial_hexagon = b.to_hexagon(starting.F,starting.S);
			new_move += "M";
			new_move += ( " " + to_string(initial_hexagon.F) + " " + to_string(initial_hexagon.S));
			//traverse in 6 directions
			for(int j = 0 ; j < 6 ; j++)
			{
				int marker_crossed = 0; // signifying marker has crossed or not 
				int new_x = starting.F + direction_x[j];
				int new_y = starting.S + direction_y[j];
				while(b.isValid(new_x,new_y)==true)
				{
					pii end ;
					end.F = new_x ;
					end.S = new_y ;
					if (b.isEmpty(new_x , new_y) == true )
					{
						pii end_hexagon = b.to_hexagon(end.F,end.S);
						new_move +=  " " + to_string(end_hexagon.F) +" " +  to_string(end_hexagon.S); 

						//checking the board after this move ;
						execute_move(id,new_move,copyboard);
						vector<pair<pii,pii> > sequence = (copyboard.find_row()).at(id-1) ;
						for (int k = 0 ; k < sequence.size() ; k++)
						{
							pair<pii,pii> toRemove = sequence.at(k);
							pii hexaStart = b.to_hexagon((toRemove.F).F,(toRemove.F).S);
							pii hexaEnd = b.to_hexagon((toRemove.S).F,(toRemove.S).S);
							new_move += " RS "  + to_string(hexaStart.F) + " " + to_string(hexaStart.S) + " RE " + to_string(hexaEnd.F) + " " + to_string(hexaEnd.S) + " X";

							//possibles ring which could be removed
							vector<pii> rings_removed ;
							if (id == 1)
								rings_removed = copyboard.ring_p1;
							else
								rings_removed = copyboard.ring_p2;

							for(int l = 0 ; l < rings_removed.size() ; l++)
							{
								pii current_ring = rings_removed.at(i);
								if (current_ring.F != 100)
								{
									pii hexaRing = b.to_hexagon(current_ring.F,current_ring.S);
									new_move += " " + to_string(hexaRing.F) + " " + to_string(hexaRing.S);
								}
							}

						}

						neighbours.push_back(new_move);
						if (marker_crossed == 1)
						{
							break ;
						}

					}
					if (b.value(new_x,new_y) == 3 || b.value(new_x,new_y) == 4 ) 
					{
						break; //ring encountered 
					}
					else if (b.value(new_x,new_y) == 0 || b.value(new_x,new_y) == 1 ) 
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


vector<string> player::generate_ring_place(board& b)
{
	
	vector<string> places ;
	string point ;

 	
	
	if (b.isEmpty(0,0))
	{
		
		point = "P 0 0" ;
	}
	
	places.push_back(point);
	 //0 is invalid move so check that
	//added statement for invalid check for hexagon 5
	for(int i = 1 ; i <= 5 ; i++ )
	{
		int hexagon = i;
		for (int j = 0 ; j < 6*i ; j++)
		{
			int position = j ;
			pii current =  b.convert(hexagon,position);
			if (b.isEmpty(current.F,current.S)== true)
			{   
				
				point =  "P " + to_string(i) + " " + to_string(j);
				places.push_back(point);
			}
		}
	}
	return places;
	

}

// string best_ring(vector<pii>  positions , board b)
// {
// 	pii best = b.best_ring_place(positions);
// 	pii hexa = b.to_hexagon(best.F,best.S); 
	

// 	//generating string format of move ;
// 	string  finale = "P " ;
// 	finale.append(to_string(hexa.F));
// 	finale.append(" ");
// 	finale.append(to_string(hexa.S));
// 	return finale;
// }







