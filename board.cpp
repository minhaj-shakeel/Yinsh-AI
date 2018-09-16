#include "board.h"
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
using namespace std;

int hor[] = {1,-1,0,0,1,-1};
int ver[] = {0,0,1,-1,1,-1};

// map< pii,pii > hex_to_2d;
// map< pii,pii > 2d_to_hex;

// pii arr[91] = {
// {0,0},
// {0,1},{1,1},{1,0},{0,-1},{-1,-1},{-1,0},
// {0,2},{1,2},{2,2},{2,1},{2,0},{1,-1},{0,-2},{-1,-2},{-2,-2},{-2,-1},{-2,0},{-1,1},
// {0,3},{1,3},{2,3},{3,3},{3,2},{3,1},{3,0},{2,-1},{1,-2},{0,-3},{-1,-3},{-2,-3},{-3,-3},{-3,-2},{-3,-1},{-3,0},{-2,1},{-1,2},
// {0,4},{1,4},{2,4},{3,4},{4,4},{4,3},{4,2},{4,1},{4,0},{3,-1},{2,-2},{1,-3},{0,-4},{-1,-4},{-2,-4},{-3,-4},{-4,-4},{-4,-3},{-4,-2},{-4,-1},{-4,0},{-3,1},{-2,2},{-1,3},
//     {}, {1,5},{2,5},{3,5},{4,5}, {},  {5,4},{5,3},{5,2},{5,1}, {},  {4,-1},{3,-2},{2,-3},{1,-4}, {},  {-1,-5},{-2,-5},{-3,-5},{-4,-5}, {},  {-5,-4},{-5,-3},{-5,-2},{-5,-1}, {},  {-4,1},{-3,2},{-2,3},{-1,4}
// };


// void board::initialise()
// {
// 	int count=0;
// 	hex_to_2d[{0,0}] =arr[count];
// 	count++;
// 	for(int i=0;i<=5;i++){
// 		for(int j=0;j<=(6*i-1);j++){
// 			hex_to_2d[{i,j}] = arr[count];
// 			count++;
// 		}
// 	}
// }

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
				if(j==0 || j==10)
					v.pb(10);
				else
					v.pb(-1);
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

board::board(const board &b)
{
	for(int i=0;i<=10;i++){
		std::vector<int> v;
		for(int j=0;j<=10;j++){
			v.pb(b.points[i][j]);
		}
		this->points.pb(v);
	}

	for(int i=0;i<5;i++){
		b.ring_p1.pb(ring_p1[i]);
		b.ring_p2.pb(ring_p2[i]);
	}
}

void board::place_ring(int player, int x, int y)
{
	if(player == 1){
		ring_p1.pb({x,y});
		points[x+5][y+5] = 3;
	}
	else{
		ring_p2.pb({x,y});
		points[x+5][y+5] = 4;
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

void board::move_ring(int player, int x1, int y1, int x2, int y2)
{
	if(player==1){
		for(int i=0;i<5;i++){
			if(ring_p1[i].F==x1 && ring_p1[i].S==y1){
				ring_p1[i].F = x2;
				ring_p1[i].S = y2;
			}
		}
		points[x1+5][y1+5] = 0;
		points[x2+5][y2+5] = 3;
	}
	else{
		for(int i=0;i<5;i++){
			if(ring_p2[i].F==x1 && ring_p2[i].S==y1){
				ring_p2[i].F = x2;
				ring_p2[i].S = y2;
			}
		}
		points[x1+5][y1+5] = 1;
		points[x2+5][y2+5] = 4;
	}

	int a = move_index(x1,y1,x2,y2);

	int s1 = x1; int e1 = y1;
	s1+= hor[a]; e1+= ver[a];
	while(s1!=x2 || e1!=y2){
		if(points[s1+5][e1+5]==-1){
			s1+= hor[a]; e1+= ver[a];
			continue;
		}
		else{
			points[s1+5][e1+5] = 1-points[s1+5][e1+5];
			s1+= hor[a]; e1+= ver[a];
		}
	}



}

void board::remove_row(int x1, int y1, int x2, int y2)
{
	int a = move_index(x1,y1,x2,y2);

	points[x1+5][y1+5] = -1;
	points[x2+5][y2+5] = -1;

	int s1 = x1; int e1 = y1;
	s1+= hor[a]; e1+= ver[a];
	while(s1!=x2 || e1!=y2){
		points[s1+5][e1+5] = -1;
		s1+= hor[a]; e1+= ver[a];
	}
}

void board::remove_ring(int player, int x, int y)
{
	points[x+5][y+5] = -1;
	if(player==1){
		for(int i=0;i<5;i++){
			if(ring_p1[i].F==x && ring_p1[i].S==y){
				ring_p1[i].F = 100;
				ring_p1[i].S = 100;
			}
		}
	}
	else{
		for(int i=0;i<5;i++){
			if(ring_p2[i].F==x && ring_p2[i].S==y){
				ring_p2[i].F = 100;
				ring_p2[i].S = 100;
			}
		}
	}
}


bool board::isEmpty(int x, int y)
{
	if(points[x+5][y+5]==-1) return true;
	else return false;
}


int board::value(int x, int y)
{
	return points[x+5][y+5];
}

bool board::isValid(int x, int y)
{
	int i = x+5; int j = y+5;
	if(i<0 || j<0 || i>10 || j>10) return false;
	if(points[i][j]==10) return false;
	else return true;
}

vector< std::vector<pair<pii,pii> > > board::find_row()
{
	std::vector<pair<pii,pii> > v1;
	std::vector<pair<pii,pii> > v2;
	std::vector< std::vector<pair<pii,pii> > > ans;
	ans.pb(v1);ans.pb(v2);

	int newx,newy;
	// v1 has player1 rows and v2 has player2 rows
	for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++){
			if(points[i][j]==10) continue;
			
			if(points[i][j]==0){
				for(int a=0;a<=4;a+=2){
					int rc=1;
					// i is x and j is y
					newx = i;newy=j;
					for(int count=1;count<=4;count++){
						newx+= hor[a];newy+= ver[a];
						if(isValid(newx-5,newy-5)){
							if(points[newx][newy]==0) rc++;
						}
					}
					if(!(isValid(i-hor[a]-5,j-ver[a]-5)) || !(isValid(newx+hor[a]-5,newy+ver[a]-5)) || (points[i-hor[a]][j-ver[a]] !=0) || (points[newx+hor[a]][newy+ver[a]] !=0) ){
						if(rc==5){
							ans[0].pb({{i-5,j-5},{newx-5,newy-5}});
						}
					}
					
				}
			}
			else if(points[i][j]==1){
				for(int a=0;a<=4;a+=2){
					int rc=1;
					// i is x and j is y
					newx = i;newy=j;
					for(int count=1;count<=4;count++){
						newx+= hor[a];newy+= ver[a];
						if(isValid(newx-5,newy-5)){
							if(points[newx][newy]==1) rc++;
						}
					}
					if(!(isValid(i-hor[a]-5,j-ver[a]-5)) || !(isValid(newx+hor[a]-5,newy+ver[a]-5)) || (points[i-hor[a]][j-ver[a]] !=1) || (points[newx+hor[a]][newy+ver[a]] !=1) ){
						if(rc==5){
							ans[1].pb({{i-5,j-5},{newx-5,newy-5}});
						}
					}
				}

			}
		}
	}

	return ans;
}




pii board::to_hexagon(int x , int y )	
{
  int hexagon ;
  int position ;
  if (x*y >= 0)
  {
      hexagon = max(abs(x),abs(y));
  }
  else
  {
      hexagon = abs(x) + abs(y);
  }
  
  
  
  if (x >=0 && y >= 0)
  {
      if (y == hexagon)
      position = x ;
      else
      {
          position = 2*hexagon - y ;
      }
  }
  if (x >=0 && y < 0)
  {
      position = 2*hexagon + abs(y) ;
  }
  if (x < 0 && y < 0)
  {
      if (abs(y) == hexagon)
      {
        position = 3*hexagon + abs(x);
      }
      else
      {
          position = 5*hexagon+y ;
      }
  }
  if (x < 0 && y >= 0)
  {
       position = 5*hexagon+y ;
  }
  pii ans ;
  ans.F =  hexagon ;
  ans.S =  position ;
  return ans ;
}




pii board::convert(int hexagon , int position )  //changed convert
{ 
	int x , y ;
  if (position <= hexagon)
  {
      y = hexagon ;
      x = position ;
  }
  else if (position <= 2*hexagon)
  {
      x = hexagon ;
      y = 2*hexagon - position ;
  }
  else if (position <= 3*hexagon)
  {
      x = 3*hexagon - position ;
      y = -1*(position - 2*hexagon) ;
  }
   else if (position <= 4*hexagon)
  {
      y = -1*hexagon  ;
      x = -1*(position - 3*hexagon) ;
  }
   else if (position <= 5*hexagon)
  {
      x = -1*hexagon  ;
      y = -1*(5*hexagon-position) ;
  }
  else
  {
      y = position - 5*hexagon ;
      x = -1*(hexagon-y);
  }
  pii ans ;

  ans.F = x  ;
  ans.S = y ;  
  return ans ; 
}


pair<double,double> board::score()
{
	double sc = 0;
	int r1=0,r2=0,rnum1=0;,rnum2=0;int np;
	for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++){
			np = points[i][j];
			if(np==3) 
				r1++;
			else if(np==4) 
				r2++;
			else if(np==0)
				rnum1++;
			else if(np==1)
				rnum2++;
		}
	}

	int score1,score2;
	if(r1==3){
		score1 = 10-r2;
		score2 = r2;
	}
	else if(r2==3){
		score1 = r1;
		score2 = 10-r1;
	}
	else if(r2==r1){
		score1 = 5;
		score2 = 5;
	}
	else if(r1-r2==2){
		score1 = 7;
		score2 = 3;
	}
	else if(r2-r1==2){
		score1 = 3;
		score2 = 7;
	}
	else if(r1>r2){
		score1 = 6;
		score2 = 4;
	}
	else if(r2>r1){
		score1 = 4;
		score2 = 6;
	}

	r1 = score1 + (double)rnum1/1000.0;
	r2 = score2 + (double)rnum2/1000.0;

	pair<double,double> scp;
	scp.F = r1; scp.S = r2;
	return scp;
}

// insert in format x,y as points[1][2] -> 1,2

