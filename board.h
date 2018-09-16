#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <utility>
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
using namespace std;

class board
{
public:
	std::vector<std::vector<int> > points;
	std::vector<pii > ring_p1;
	std::vector<pii > ring_p2;

	board();

	board(const board &b);

	void place_ring(int player,int x, int y);

	int move_index(int x1, int y1, int x2, int y2);

	void move_ring(int player, int x1, int y1, int x2, int y2);

	void remove_row(int x1, int y1, int x2, int y2);

	void remove_ring(int player, int x, int y);

	bool isEmpty(int x, int y);

	pii convert(int hexagon , int position);

	pii best_ring_place(vector<pair<int,int> > positions);

	int value(int x, int y);

	bool isValid(int x, int y);

	pii to_hexagon(int x , int y );

	// returns vector of all possible row to be removed for both the players
	// player1 in v[0] and player2 in v[1]
	vector< std::vector<pair<pii,pii> > > find_row();
	//gives best ring position to place 

	pair<double,double> score();


};

#endif