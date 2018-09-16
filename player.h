#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <cmath>
#define pii pair<int,int> 
using namespace std;

struct move
{
	pii start ;
	pii end ;
};	



class player
{
public:
	int id ; 
	player(int a)
	{
		id = a ;
	}

	vector<string> generate_neighbour(int id ,board& b);

	pair<pii,pii> generate_move(int id , board& b);

	vector<string> generate_ring_place(board& b); //generate 
	string generate_ring_move(int id , board& b) ;


	void execute_move(int id ,string str,board& b);


};
#endif 