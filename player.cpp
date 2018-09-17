#include "player.h"
#include "board.h"

#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <vector>
#include <fstream>

#define pb push_back
#define F first
#define S second
using namespace std;

ofstream outputfile("out.txt");


int best_depth =3;
string best_move;
int num=0;

pii arr[] = {{0,0}, {1,0}, {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {2,0}, {2,1}, {2,2}};
string player::generate_ring_move(board& b)
{
	string str = "P ";
	outputfile <<str<<endl;
	for(int i=0;i<10;i++)
	{
		pii cordinate  = b.convert(arr[i].F,arr[i].S); 
		if(b.isEmpty(cordinate.F,cordinate.S))
		{
			str+= to_string(arr[i].F) + " " + to_string(arr[i].S);
			break;
		}

	}
	outputfile << str<<endl;
	return str ;
}

void print_board(board& b)
{
	for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            if(b.points[i][j]==10){

                outputfile<<" "<<" ";
            }
            else if(b.points[i][j]==-1)
                outputfile<<b.points[i][j];
            else
            	outputfile<<" "<<b.points[i][j];
        }
        outputfile<<"\n";
    }
}

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
	if (str == "")
	return ;	
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

	outputfile<<"execute_move:"<<str<<endl;

	// print_board(b);

	vector<string> token = split(str,' ');
	// print_board(b);
				int counter = 0;
				
			while ((token.size() > counter) && (token[counter] =="RS") )
			{	
				//cout << counter << "token" << endl ;
				string next_step = token.at(0+counter);
				int hexagon_start = stoi(token.at(1+counter));
				int position_start = stoi(token.at(2+counter));
				
					int hexagon_end  = stoi(token.at(4+counter));
					int position_end = stoi(token.at(5+counter));
					pii row_start , row_end ,ring_remove;
					row_start = b.convert(hexagon_start,position_start);
					row_end = b.convert(hexagon_end,position_end);
					b.remove_row(row_start.F,row_start.S,row_end.F,row_end.S);
					int ring_hexagon = stoi(token.at(7+counter));
					int ring_position = stoi(token.at(8+counter));
					ring_remove = b.convert(ring_hexagon,ring_position);
					b.remove_ring(id ,ring_remove.F,ring_remove.S);
					counter += 9 ;
					//cout << counter << "counter" << endl ;
					

			}





//cout << token.size() << endl ;
if (token.size() > counter)
{
	string move_type = token.at(0+counter); 
	string hexagon = token.at(1+counter);
	string position  = token.at(2+counter);

 	pii start = b.convert(stoi(hexagon),stoi(position));

	if (move_type == "P" )
	{
		if (b.isEmpty(start.F,start.S) )
		{

			b.place_ring(id , start.F , start.S);
			//print_board(b);
			// cout << str << endl ;
		}
		else
		{
			// cout << "non empty position" << endl ;
			return ;
		}
	}
	else if  (move_type == "S" )
	{
		string next_step = token.at(3+counter);
		hexagon = token.at(4+counter);
		position = token.at(5+counter);
		pii end = b.convert(stoi(hexagon),stoi(position));


		if (next_step == "M")
		{
			b.move_ring(id , start.F , start.S , end.F , end.S);
			if (token.size() > 6) 
			{
				next_step = token.at(6+counter);
				int hexagon_start = stoi(token.at(7+counter));
				int position_start = stoi(token.at(8+counter));

				if (next_step == "RS")
				{
					int hexagon_end  = stoi(token.at(10+counter));
					int position_end = stoi(token.at(11+counter));
					pii row_start , row_end ,ring_remove;
					row_start = b.convert(hexagon_start,position_start);
					row_end = b.convert(hexagon_end,position_end);
					b.remove_row(row_start.F,row_start.S,row_end.F,row_end.S);
					int ring_hexagon = stoi(token.at(13+counter));
					int ring_position = stoi(token.at(14+counter));
					ring_remove = b.convert(ring_hexagon,ring_position);
					b.remove_ring(id ,ring_remove.F,ring_remove.S);

					// cout << str << endl ;

				}

			}
 			// cout << str << endl ;
		}
		else
		{
			// cout << "invalid move" << endl ;
		}

	}
	else
	{
		// cout << "invalid move " << endl ;
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
	// print_board(b);
	
	}
}
vector<string> player::generate_initial_removal(int id, board& b)
{
	vector<pii> initial_rings ;
	if (id == 1)
	{
		initial_rings = b.ring_p1;
	}
	else
	{
		initial_rings = b.ring_p2 ;
	}
	 vector<pair<pii,pii > > initial_rows =  (b.find_row()).at(id-1);
	 vector<string> initial_removal; 
	 vector<string> first ;
	 //cout << initial_rows.size() << endl ;
	 for (int i = 0 ; i < initial_rows.size() ; i++)
	 	{ 
	 		
	 			

	 			pair<pii,pii > first_pickup = initial_rows[i] ;
	 			//cout<<"checkpoint1"<<endl;
	 			for (int j = 0 ;  j < initial_rings.size() ; j++)

		 				{	
		 					string prefix = "";
		 					pii current_ring = initial_rings[j];
		 					if(current_ring.F!=100)
							{
	

							 	pii hexaStart = b.to_hexagon((first_pickup.F).F,(first_pickup.F).S);
								pii hexaEnd = b.to_hexagon((first_pickup.S).F,(first_pickup.S).S);
								prefix += "RS "  + to_string(hexaStart.F) + " " + to_string(hexaStart.S) + " RE " + to_string(hexaEnd.F) + " " + to_string(hexaEnd.S) + " X";			

							    pii hexaRing = b.to_hexagon(current_ring.F,current_ring.S);
								prefix += " " + to_string(hexaRing.F) + " " + to_string(hexaRing.S);
							
				    			
								//prefix += " ";
								first.push_back(prefix)  ;
								
							}
							
					    }


		}
		//cout<<"checkpoint2"<<endl;
		board copy(b);
		//cout<<"checkpoint3"<<endl;
		vector<string> second ;
		for (int i = 0 ; i < first.size(); i++)
		{
			//cout<<"checkpoint4"<<first[i]<<endl;
			execute_move(id,first[i],copy);
			//cout<<"checkpoint5"<<first[i]<<endl;
			vector<pair<pii,pii > > remaining_rows =  (copy.find_row()).at(id-1);
			//cout << remaining_rows.size() << endl ;
			//cout << first[i] << "first" << endl ;
			
			if (id == 1)
			{
				initial_rings = copy.ring_p1;
			}
			else
			{
				initial_rings = copy.ring_p2 ;
			}
			if (remaining_rows.size()!=0)	
			{

		 	     for (int j = 0 ;  j < initial_rings.size() ; j++)
				 {
				 		pii current_ring = initial_rings[j];
		 					if(current_ring.F!=100)
							{
			 	
								string prefix = "";		 					
		 	     				

					 			pair<pii,pii> initial_marker = remaining_rows[0];
					

							 	pii hexaStart = b.to_hexagon((initial_marker.F).F,(initial_marker.F).S);
								pii hexaEnd = b.to_hexagon((initial_marker.S).F,(initial_marker.S).S);
								prefix += "RS "  + to_string(hexaStart.F) + " " + to_string(hexaStart.S) + " RE " + to_string(hexaEnd.F) + " " + to_string(hexaEnd.S) + " X";
											

							    pii hexaRing = b.to_hexagon(current_ring.F,current_ring.S);
								prefix += " " + to_string(hexaRing.F) + " " + to_string(hexaRing.S);
							
				    			
								
								//cout << prefix << endl ;
								second.push_back(first[i]+" "+prefix);
								
							}
							
				    		
				  }
			}
			else
			{
				second.push_back(first[i]);
			}
		}

		 

		














							
			 	



			 	
			
		

		initial_removal = second;
		if (initial_removal.size() == 0)
		{
			string space = "";
			initial_removal.push_back(space);

		}
		return initial_removal;	
}



vector<string> player::generate_simple_moves(int id ,board& b)
{
	int direction_x[] = {0,0,1,-1,1,-1};
	int direction_y[] = {1,-1,0,0,1,-1};
	


	vector<string> neighbours ;
	if (id == 1)
	{	
		if (b.flag1 == 0 )
		{
			
			return generate_ring_place(b);
		}
	}
	else
	{
		if (b.flag2 == 0 )
		{
			return generate_ring_place(b);
		}
	}
	
		

	 

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
						string new_move = "";
						new_move += "S";
						new_move += ( " " + to_string(initial_hexagon.F) + " " + to_string(initial_hexagon.S));
			
						new_move +=  " M " + to_string(end_hexagon.F) +" " +  to_string(end_hexagon.S); 
						
						//checking the board after this move ;
						// board copyboard(b) ;
						// execute_move(id,new_move,copyboard);
		
						
						// vector<pair<pii,pii> > sequence = (copyboard.find_row()).at(id-1) ;
						// // cout << sequence.size() << endl ;
						
						// for (int k = 0 ; k < sequence.size() ; k++)
						// {
						// 	// new_move += " RS "  + to_string(hexaStart.F) + " " + to_string(hexaStart.S) + " RE " + to_string(hexaEnd.F) + " " + to_string(hexaEnd.S) + " X";

						// 	//possibles ring which could be removed
						// 	vector<pii> rings_removed ;
						// 	if (id == 1)
						// 		rings_removed = copyboard.ring_p1;
						// 	else
						// 		rings_removed = copyboard.ring_p2;
							
						// 	for(int l = 0 ; l < rings_removed.size() ; l++)
						// 	{

						// 		pii current_ring = rings_removed.at(l);
								
						// 		if (current_ring.F != 100)
						// 		{
						// 			string rest = "";
						// 			pair<pii,pii> toRemove = sequence.at(k);
						// 			pii hexaStart = b.to_hexagon((toRemove.F).F,(toRemove.F).S);
						// 			pii hexaEnd = b.to_hexagon((toRemove.S).F,(toRemove.S).S);
						// 			rest += " RS "  + to_string(hexaStart.F) + " " + to_string(hexaStart.S) + " RE " + to_string(hexaEnd.F) + " " + to_string(hexaEnd.S) + " X";
							

						// 			pii hexaRing = b.to_hexagon(current_ring.F,current_ring.S);
						// 			rest += " " + to_string(hexaRing.F) + " " + to_string(hexaRing.S);
						// 			// new_move += " " + to_string(hexaRing.F) + " " + to_string(hexaRing.S);
						// 			string st = new_move + rest;
						// 			neighbours.push_back(st);
						// 		}
						// 	}
							//string st = new_move + rest;
							//b.remove_row()
							//neighbours.push_back(st);
							// cout << new_move << endl ;

						// }

						// if(sequence.size()==0)
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
	if (neighbours.size() == 0 )
	{
		string space = "";
		neighbours.push_back(space);
	}
	return neighbours ;
}

vector<string> player::generate_neighbour(int id ,board& b)
{
	vector<string> ans ;
	cout << "he" << endl ;
	vector<string> v = generate_initial_removal(id , b) ;
	cout << "there" << endl ;
	
	for (int  i = 0 ; i < v.size() ; i++)
	{

		board copy(b);
		execute_move(id,v[i],copy);

		
		cout << "rhere" << endl ;
		vector<string> s = generate_simple_moves(id , copy);
		cout << "here" << endl ;
		cout << s.size() << endl ;
		for (int j = 0 ; j < s.size() ; j++)
		{
			
			  board copy2(copy);
			  execute_move(id,s[j],copy);
			  vector<string> r = generate_initial_removal(id,copy2);
			

			//ans.push_back(v[i]+ " " + s[j]);
			for (int k = 0 ; k < r.size() ; k++ )
			{
				
				if (v[i]!= "")
					ans.push_back(v[i]+ " " + s[j] + " " +r[k]);
				else
					ans.push_back(s[j] + " " +r[k]);
			}
		}
	}

	return ans ;
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


double player::maxim(int id, board& b, int depth)
{
	int next_player;
	if(id==1) next_player=2;
	else next_player=1;

	double max_score= -100.0,present_score;

	if(depth==0){
		pair<double,double> pr = b.score();
		if(id==1) present_score = pr.F;
		else present_score = pr.S;
		return present_score;
	}

	vector<string> nb = generate_neighbour(id,b);
	num = num + nb.size();
	
	for(int i=0;i<nb.size();i++){
		board copy_board(b);
		execute_move(id,nb[i],copy_board);
		// present_score = copy_board.score();
		present_score = minim(next_player,copy_board,depth-1);
		if(present_score>max_score){
			if(depth==best_depth)
				best_move = nb[i];
			outputfile<<best_move<<"bestbest"<<endl;
			max_score = present_score;
		}
	}
	return max_score;
}

double player::minim(int next_player, board& b, int depth)
{
	int id;
	if(next_player==1) id=2;
	else id=1;

	double min_score=1000,present_score;

	if(depth==0){
		pair<double,double> pr = b.score();
		if(id==1) present_score = pr.F;
		else present_score = pr.S;
		return present_score;
	}

	vector<string> nb = generate_neighbour(next_player,b);
	num = num + nb.size();
	// double min_score=100.0,present_score;
	// string best_move;
	for(int i=0;i<nb.size();i++){
		board copy_board(b);
		execute_move(next_player,nb[i],copy_board);
		// present_score = copy_board.score();
		present_score = maxim(id,copy_board,depth-1);
		if(present_score<min_score){
			// best_move = nb[i];
			min_score = present_score;
		}
	}
	return min_score;
}

string player::generate_move(int id, board& b)
{
	string str;
	outputfile<<"start"<<endl;
	if(b.flag1==0 && id==1)
		str = generate_ring_move(b);
	else if(b.flag2==0 && id==2)
		str = generate_ring_move(b);
	else{
		double dd = maxim(id,b,best_depth);
		str = best_move;
		// cout<<"fuck"<<best_move<<"  "<< num<< endl;

	}

	outputfile<<str<<endl;

	return str;
}



