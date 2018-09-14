#include "board.h"
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
using namespace std;

int hor[] = {1,-1,0,0,1,-1};
int ver[] = {0,0,1,-1,1,-1};

map< pii,pii > hex_to_2d;
map< pii,pii > 2d_to_hex;

pii arr[91] = {
{0,0},
{0,1},{1,1},{1,0},{0,-1},{-1,-1},{-1,0},
{0,2},{1,2},{2,2},{2,1},{2,0},{1,-1},{0,-2},{-1,-2},{-2,-2},{-2,-1},{-2,0},{-1,1},
{0,3},{1,3},{2,3},{3,3},{3,2},{3,1},{3,0},{2,-1},{1,-2},{0,-3},{-1,-3},{-2,-3},{-3,-3},{-3,-2},{-3,-1},{-3,0},{-2,1},{-1,2},
{0,4},{1,4},{2,4},{3,4},{4,4},{4,3},{4,2},{4,1},{4,0},{3,-1},{2,-2},{1,-3},{0,-4},{-1,-4},{-2,-4},{-3,-4},{-4,-4},{-4,-3},{-4,-2},{-4,-1},{-4,0},{-3,1},{-2,2},{-1,3},
    {}, {1,5},{2,5},{3,5},{4,5}, {},  {5,4},{5,3},{5,2},{5,1}, {},  {4,-1},{3,-2},{2,-3},{1,-4}, {},  {-1,-5},{-2,-5},{-3,-5},{-4,-5}, {},  {-5,-4},{-5,-3},{-5,-2},{-5,-1}, {},  {-4,1},{-3,2},{-2,3},{-1,4}
};

int count=0;
hex_to_2d[{0,0}] =arr[count];
count++;
for(int i=0;i<=5;i++){
	for(int j=0;j<=(6*i-1);j++){
		hex_to_2d[{i,j}] = arr[count];
		count++;
	}
}

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
	if(player == 1){
		ring_p1.pb({x,y});
		points[y+5][x+5] = 3;
	}
	else{
		ring_p2.pb({x,y});
		points[y+5][x+5] = 4;
	}
}

int board::move_index(int x1, int y1, int x2, int y2)
{
	if(x1==x2){
		if(y1<y2) return 2;
		else return 3;
	}
	else if(y1==y2){
		if(x1<x2) return 0;
		else return 1;
	}
	else{
		if((x2-x1)<0) return 5;
		else return 4;
	}
}

void board::move_ring(player, int x1, int y1, int x2, int y2)
{
	if(player==1){
		for(int i=0;i<5;i++){
			if(ring_p1[i].F==x1 && ring_p1[i].S==y1){
				ring_p1[i].F = x2;
				ring_p1[i].S = y2;
			}
		}
		points[y1+5][x1+5] = 0;
		points[y2+5][x2+5] = 3;
	}
	else{
		for(int i=0;i<5;i++){
			if(ring_p2[i].F==x1 && ring_p2[i].S==y1){
				ring_p2[i].F = x2;
				ring_p2[i].S = y2;
			}
		}
		points[y1+5][x1+5] = 1;
		points[y2+5][x2+5] = 4;
	}

	int a = move_index(x1,y1,x2,y2);

	int s1 = x1; int e1 = y1;
	s1+= hor[a]; e1+= ver[a];
	while(s1!=x2 || e1!=y2){
		if(points[e1+5][s1+5]==-1){
			s1+= hor[a]; e1+= ver[a];
			continue;
		}
		else{
			points[e1+5][s1+5] = 1-points[e1+5][s1+5];
			s1+= hor[a]; e1+= ver[a];
		}
	}



}

void board::remove_row(int x1, int y1, int x2, int y2)
{
	int a = move_index(x1,y1,x2,y2);

	points[y1+5][x1+5] = -1;
	points[y2+5][x2+5] = -1;

	int s1 = x1; int e1 = y1;
	s1+= hor[a]; e1+= ver[a];
	while(s1!=x2 || e1!=y2){
		points[e1+5][s1+5] = -1;
		s1+= hor[a]; e1+= ver[a];
	}
}

void board::remove_ring(player, int x, int y)
{
	points[y+5][x+5] = -1;
	if(player==1){
		for(int i=0;i<5;i++){
			if(ring_p1[i].F==x1 && ring_p1[i].S==y1){
				ring_p1[i].F = 100;
				ring_p1[i].S = 100;
			}
		}
	}
	else{
		for(int i=0;i<5;i++){
			if(ring_p2[i].F==x1 && ring_p2[i].S==y1){
				ring_p2[i].F = 100;
				ring_p2[i].S = 100;
			}
		}
	}
}


bool board::isEmpty(int x, int y)
{
	if(points[y][x]==-1) return true;
	else return false;
}

pii board::convert(int hexagon , int position)
{
	return hex_to_2d[{hexagon,position}];
}
// insert in format y,x as points[2][1] -> 1,2

