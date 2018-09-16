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
	int id ; 
	player(int a)
	{
		id = a ;
	}

	vector<pair<pii,pii> > generate_neighbour(int id );

	pair<pii,pii> generate_move(int id , board b);

	string generate_ring_place(int id , board b); //generate 
	string generate_ring_move(int id , board b) ;


	void execute_move(int id ,string str,board b);


};
#endif 