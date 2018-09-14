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
	point start ;
	point end ;
};	
class player
{
	int id ; //by default player1
	
	//int rings_x[] = {0,0,1,1,0,-1 };
	//int rings_y[] = {0,1,1,0,-1,-1};
	player(int a);

	vector<move<point,point> > generate_neighbour(int id );
	move<point,point> generate_move(int id , board b);
	void player::execute_move(move<point,point> m)


};
