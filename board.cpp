#include "board.h"
#include <bits/stdc++.h>

#define pb push_back
using namespace std;

board::board()
{
	for(int i=0;i<=10;i++){
		std::vector<int> v;
		for(int j=0;j<=10;j++){
			if(i==0){
				if(j==0 || j>4)
					v.pb(10);
				else
					v.pb(-1);
			}
			else if(i>=1 && i<=4){
				if(j>(i+5))
					v.pb(10);
				else
					v.pb(-1);
			}
			else if(i==5){
				if(j==0 || j==10){
					v.pb(10);
				else
					v.pb(-1);
				}
			}
			else if(i>=6 && i<=9){
				if(j<i-5)
					v.pb(10);
				else
					v.pb(-1);
			}
			else{
				if(j==10 || j<=5)
					v.pb(10);
				else
					v.pb(-1);
			}
		}
		points.pb(v);
	}
}

board::board(board b)
{
	for(int i=0;i<=10;i++){
		std::vector<int> v;
		for(int j=0;j<=10;j++){
			v.pb(b.points[i][j]);
		}
		this->points[i].pb(v);
	}
}

void board::place_ring(player, int x, int y)
{
	if(player == 1)
		ring_p1.pb({x,y});
	else
		ring_p2.pb({x,y});
}

void board::move_ring

// insert in format y,x as points[2][1] -> 1,2

