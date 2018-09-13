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

	void move_ring(player, int x1, int y1, int x2, int y2);

	void remove_row(int x1, int y1, int x2, int y2);

	void remove_ring(player, int x, int y);

	bool isEmpty(int x, int y);


}