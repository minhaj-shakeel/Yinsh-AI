#ifndef PLAYER_H
#define PLAYER_H

#include <board.h>
#include <vector>
#include <utility>
#define point pair<int,int> 
using namespace std;
struct pair
{
	int x , y ;

};
struct move
{

};	
class player
{
	int id ; //by default player1
	
	//int rings_x[] = {0,0,1,1,0,-1 };
	//int rings_y[] = {0,1,1,0,-1,-1};
	player(int a);

	vector<pair<int ,int> > generate_move(int id = 1, board b); //generate best move
	void execute_move(pair<int,int> p);

};
