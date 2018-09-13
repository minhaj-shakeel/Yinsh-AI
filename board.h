#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <utility>
using namespace std;

class board
{
public:
	std::vector<std::vector<int> > points;
	std::vector<pair<int,int> > ring_p1;
	std::vector<pair<int,int> > ring_p2;

	board();

	board(board b);

	void place_ring(player,int x, int y);

	void move_ring(r_no, int x, int y);


}