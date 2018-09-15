#ifndef PLAYER_H
#define PLAYER_H

#include <board.h>
#include <vector>
#include <utility>
#include <algorithm>
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

	vector<move<pii,pii> > generate_neighbour(int id );
	
	move<pii,pii> generate_move(int id , board b);

	string generate_ring_place(int id , board b); //generate 
	string generate_ring_move(int id , board b) ;


	void player::execute_move(move<pii,pii> m)


};
#endif 