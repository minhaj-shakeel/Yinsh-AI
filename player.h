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

	vector<string> generate_initial_removal(int id ,board& b);

	vector<string> generate_simple_moves(int id ,board& b);
	vector<string> generate_neighbour(int id ,board& b);

	string generate_move(int id , board& b);

	vector<string> generate_ring_place(board& b); //generate 
	string generate_ring_move( board& b) ;

	double maxim(int id, board& b, int depth);

	double minim(int next_player, board& b, int depth);


	void execute_move(int id ,string str,board& b);


};
void print_board(board& b);
#endif 