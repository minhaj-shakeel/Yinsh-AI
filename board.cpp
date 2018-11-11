#include "board.h"
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define endl '\n'
using namespace std;

int hor[] = {1,-1,0,0,1,-1};
int ver[] = {0,0,1,-1,1,-1};

int n = 5;
int m = 5;
int kk = 5;

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


//tbd
board::board()
{
	if(n==5)
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
	else if(n==6)
	{
		for(int i=0;i<=12;i++){
			std::vector<int> v;
			for(int j=0;j<=12;j++){
				if(i==0){
					if(j==0 || j>5)
						v.pb(10);
					else
						v.pb(-1);
				}
				else if(i>=1 && i<=5){
					if(j>(i+6))
						v.pb(10);
					else
						v.pb(-1);
				}
				else if(i==6){
					if(j==0 || j==12)
						v.pb(10);
					else
						v.pb(-1);
				}
				else if(i>=7 && i<=11){
					if(j<i-6)
						v.pb(10);
					else
						v.pb(-1);
				}
				else{
					if(j==12 || j<=6)
						v.pb(10);
					else
						v.pb(-1);
				}
			}
			points.pb(v);
		}
	}


	r1=0;
	r2=0;
	flag1=0;
	flag2 = 0;
}

board::board(const board &b)
{
	if(n==5){
		for(int i=0;i<=10;i++){
			std::vector<int> v;
			for(int j=0;j<=10;j++){
				v.pb(b.points[i][j]);
			}
			this->points.pb(v);
		}
	}

	else if(n==6){
		for(int i=0;i<=12;i++){
			std::vector<int> v;
			for(int j=0;j<=12;j++){
				v.pb(b.points[i][j]);
			}
			this->points.pb(v);
		}
	}

	// for(int i=0;i<5;i++){
	// 	ring_p1.pb(b.ring_p1[i]);
	// 	ring_p2.pb(b.ring_p2[i]);
	// }
	for(int i=0;i<b.ring_p1.size();i++){
		ring_p1.pb(b.ring_p1[i]);
	}
	for(int i=0;i<b.ring_p2.size();i++){
		ring_p2.pb(b.ring_p2[i]);
	}
	r1=b.r1;
	r2=b.r2;
	flag1 = b.flag1;
	flag2 = b.flag2;
}

void board::place_ring(int player, int x, int y)
{
	if(player == 1){
		ring_p1.pb({x,y});
		r1++;
		points[x+n][y+n] = 3;
		if(r1 == m) flag1 = 1;
	}
	else{
		ring_p2.pb({x,y});
		r2++;
		if(r2 == m) flag2 = 1;
		points[x+n][y+n] = 4;
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

void board::printb()
{
	if(n==5){
		for(int i=0;i<=10;i++){
	        for(int j=0;j<=10;j++){
	            if(points[i][j]==10){

	                cout<<" "<<" ";
	            }
	            else if(points[i][j]==-1)
	                cout<<points[i][j];
	            else
	            	cout<<" "<<points[i][j];
	        }
	        cout<<"\n";
	    }
	}

	else if(n==6){
		for(int i=0;i<=12;i++){
	        for(int j=0;j<=12;j++){
	            if(points[i][j]==10){

	                cout<<" "<<" ";
	            }
	            else if(points[i][j]==-1)
	                cout<<points[i][j];
	            else
	            	cout<<" "<<points[i][j];
	        }
	        cout<<"\n";
    	}
	}
}

void board::move_ring(int player, int x1, int y1, int x2, int y2)
{

	// printb();
    // cout<<"testingstart"<<endl;
	if(player==1){
		for(int i=0;i<m;i++){
			if(ring_p1[i].F==x1 && ring_p1[i].S==y1){
				ring_p1[i].F = x2;
				ring_p1[i].S = y2;
				break;
			}
		}
		points[x1+n][y1+n] = 0;
		points[x2+n][y2+n] = 3;
	}
	else{
		// printb();
		// cout<<"bfore"<<endl;
		for(int i=0;i<m;i++){
			if(ring_p2[i].F==x1 && ring_p2[i].S==y1){
				ring_p2[i].F = x2;
				ring_p2[i].S = y2;
				// cout << "index" << i << endl ;
				break;
			}
		}
		// printb();
		points[x1+n][y1+n] = 1;
		points[x2+n][y2+n] = 4;

		// printb();
		// cout<<"player2"<<endl;
	}

	// printb();
    // cout<<"baaaaahaaaaaar"<<endl;

	int a = move_index(x1,y1,x2,y2);

	int s1 = x1; int e1 = y1;
	s1+= hor[a]; e1+= ver[a];
	// cout<<"s1"<<s1<<"e1"<<e1<<endl;
	// cout<<"x2"<<x2<<"y2"<<y2<<endl;
	while(s1!=x2 || e1!=y2){
		// cout<<"andaaaaaaaaaaar"<<endl;
		if(points[s1+n][e1+n]==-1){
			s1+= hor[a]; e1+= ver[a];
			continue;
		}
		else{
			points[s1+n][e1+n] = 1-points[s1+n][e1+n];
			s1+= hor[a]; e1+= ver[a];
		}
	}


	// printb();
    // cout<<"testing"<<endl;



}

void board::remove_row(int x1, int y1, int x2, int y2)
{
	int a = move_index(x1,y1,x2,y2);

	points[x1+n][y1+n] = -1;
	points[x2+n][y2+n] = -1;

	int s1 = x1; int e1 = y1;
	s1+= hor[a]; e1+= ver[a];
	while(s1!=x2 || e1!=y2){
		points[s1+n][e1+n] = -1;
		s1+= hor[a]; e1+= ver[a];
	}
}

void board::remove_ring(int player, int x, int y)
{
	points[x+n][y+n] = -1;
	if(player==1){
		for(int i=0;i<m;i++){
			if(ring_p1[i].F==x && ring_p1[i].S==y){
				ring_p1[i].F = 100;
				ring_p1[i].S = 100;
				break;
			}
		}
		r1--;
	}
	else{
		for(int i=0;i<m;i++){
			if(ring_p2[i].F==x && ring_p2[i].S==y){
				ring_p2[i].F = 100;
				ring_p2[i].S = 100;
				break;
			}
		}
		r2--;
	}
}


bool board::isEmpty(int x, int y)
{
	if(points[x+n][y+n]==-1) return true;
	else return false;
}


int board::value(int x, int y)
{
	return points[x+n][y+n];
}


bool board::isValid(int x, int y)
{
	int i = x+n; int j = y+n;
	if(i<0 || j<0 || i>(2*n) || j>(2*n)) return false;
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
	for(int i=0;i<=(2*n);i++){
		for(int j=0;j<=(2*n);j++){
			if(points[i][j]==10) continue;
			
			if(points[i][j]==0){
				for(int a=0;a<=4;a+=2){
					int rc=1;
					// i is x and j is y
					newx = i;newy=j;
					for(int count=1;count<=kk-1;count++){
						newx+= hor[a];newy+= ver[a];
						if(isValid(newx-n,newy-n)){
							if(points[newx][newy]==0) rc++;
						}
					}
					// if(!(isValid(i-hor[a]-5,j-ver[a]-5)) || !(isValid(newx+hor[a]-5,newy+ver[a]-5)) || (points[i-hor[a]][j-ver[a]] !=0) || (points[newx+hor[a]][newy+ver[a]] !=0) ){
						if(rc==kk){
							ans[0].pb({{i-n,j-n},{newx-n,newy-n}});
						}
					// }
					
				}
			}
			else if(points[i][j]==1){
				for(int a=0;a<=4;a+=2){
					int rc=1;
					// i is x and j is y
					newx = i;newy=j;
					for(int count=1;count<=kk-1;count++){
						newx+= hor[a];newy+= ver[a];
						if(isValid(newx-n,newy-n)){
							if(points[newx][newy]==1) rc++;
						}
					}
					// if(!(isValid(i-hor[a]-5,j-ver[a]-5)) || !(isValid(newx+hor[a]-5,newy+ver[a]-5)) || (points[i-hor[a]][j-ver[a]] !=1) || (points[newx+hor[a]][newy+ver[a]] !=1) ){
						if(rc==kk){
							ans[1].pb({{i-n,j-n},{newx-n,newy-n}});
						}
					// }
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
	//double sc = 0;
	double finr1,finr2;
	int r1=0,r2=0,rnum1=0 , rnum2=0;int np;
	for(int i=0;i<=(2*n);i++){
		for(int j=0;j<=(2*n);j++){
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

	r1 = m-r1;
	r2 = m-r2;

	int score1 = 0 ;
	int score2 = 0 ;
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

	// cout<<"evaluation"<<endl;

	pair<double,double> db = evaluation();

	// cout<<"after aftyer after"<<endl;

	// cout<<score1<<"   dhfjs  "<<score2<<endl;
	// cout<<rnum1<<"   dhfjs  "<<rnum2<<endl;

	// finr1 = (double)score1 + rnum1/1000.0;
	// finr2 = (double)score2 + rnum2/1000.0;


	finr1 = (double)score1*100.0 + rnum1/1000.0 + db.F/100.0;
	finr2 = (double)score2*100.0 + rnum2/1000.0 + db.S/100.0;
	pair<double,double> scp;

	// cout<<finr1<<"   dhfjs  "<<finr2<<endl;


	scp.F = finr1; scp.S = finr2;
	return scp;
}



pair<double,double> board::evaluation()
{
	int r1=0,r2=0,rnum1=0 , rnum2=0;int np,newx,newy;
	pair<double,double> db;
	// cout<< " fucking asshole"<<endl;
	for(int i=0;i<=(2*n);i++){
		// cout<<"i"<<"     "<<i<<endl;
		for(int j=0;j<=(2*n);j++){
			// cout<<"j"<<"     "<<j<<endl;
			np = points[i][j];
			if(np==3){
				for(int a=0;a<=4;a++){
					int rc=0;
					// i is x and j is y
					newx = i;newy=j;
					if(!(isValid(newx+hor[a]-n,newy+ver[a]-n))) continue;

					if(points[newx+hor[a]][newy+ver[a]]==0){
						for(int count=1;count<=kk-1;count++){
							newx+= hor[a];newy+= ver[a];
							if(isValid(newx-n,newy-n)){
								if(points[newx][newy]==0) rc++;
								else break;
							}
						}
						if(rc==kk-1) r1+=39;
						else if(rc==kk-2) r1+=36;
						else if(rc==kk-3) r1+=21;
						else if(rc==kk-4) r1+=11;
						// if(rc==3) r1+=4;
						// else if(rc==4) r1+=5;

					}
					else if(points[newx+hor[a]][newy+ver[a]]==1){
						for(int count=1;count<=kk-1;count++){
							newx+= hor[a];newy+= ver[a];
							if(isValid(newx-n,newy-n)){
								if(points[newx][newy]==1) rc++;
								else break;
							}
							if(isValid(newx+hor[a]-n,newy+ver[a]-n)){
								if(rc==kk-1 && points[newx+hor[a]][newy+ver[a]]==-1) r1+=29;
								else if(rc==kk-1) r1+=26;
								else if(rc==kk-2 && points[newx+hor[a]][newy+ver[a]]==-1) r1+=21;
								else if(rc==kk-2) r1+=19;
								else if(rc==kk-3 && points[newx+hor[a]][newy+ver[a]]==-1) r1+=16;
								else if(rc==kk-3) r1+=13;
								else if(rc==kk-4 && points[newx+hor[a]][newy+ver[a]]==-1) r1+=5;
								else if(rc==kk-4) r1+=3;
							}
						}

					}

				}
			}

			else if(np==4){
				for(int a=0;a<=4;a++){
					int rc=0;
					// i is x and j is y
					newx = i;newy=j;

					if(!(isValid(newx+hor[a]-n,newy+ver[a]-n))) continue;

					if(points[newx+hor[a]][newy+ver[a]]==1){
						for(int count=1;count<=kk-1;count++){
							newx+= hor[a];newy+= ver[a];
							if(isValid(newx-n,newy-n)){
								if(points[newx][newy]==1) rc++;
								else break;
							}
						}
						if(rc==kk-1) r1+=39;
						else if(rc==kk-2) r1+=36;
						else if(rc==kk-3) r1+=21;
						else if(rc==kk-4) r1+=11;
						// if(rc==3) r2+=4;
						// else if(rc==4) r2+=5;

					}
					else if(points[newx+hor[a]][newy+ver[a]]==0){
						for(int count=1;count<=kk-1;count++){
							newx+= hor[a];newy+= ver[a];
							if(isValid(newx-n,newy-n)){
								if(points[newx][newy]==0) rc++;
								else break;
							}
							if(isValid(newx+hor[a]-n,newy+ver[a]-n)){
								if(rc==kk-1 && points[newx+hor[a]][newy+ver[a]]==-1) r1+=29;
								else if(rc==kk-1) r1+=26;
								else if(rc==kk-2 && points[newx+hor[a]][newy+ver[a]]==-1) r1+=21;
								else if(rc==kk-2) r1+=19;
								else if(rc==kk-3 && points[newx+hor[a]][newy+ver[a]]==-1) r1+=16;
								else if(rc==kk-3) r1+=13;
								else if(rc==kk-4 && points[newx+hor[a]][newy+ver[a]]==-1) r1+=5;
								else if(rc==kk-4) r1+=3;
							}
						}

					}

				}
				
			}

			else if(np==0){
				for(int a=0;a<=4;a+=2){
					int rc=1;
					// i is x and j is y
					newx = i;newy=j;

					if(!(isValid(newx+hor[a]-n,newy+ver[a]-n))) continue;

					if(points[newx+hor[a]][newy+ver[a]]==0){
						for(int count=1;count<=kk-1;count++){
							newx+= hor[a];newy+= ver[a];
							if(isValid(newx-n,newy-n)){
								if(points[newx][newy]==0) rc++;
								else break;
							}
						}
						if(rc==kk-1) r1+=36;
						else if(rc==kk-2) r1+=30;
						else if(rc==kk-3) r1+=11;
						else if(rc==kk-4) r1+=4;
						// if(rc==3) rnum1+=4;
						// else if(rc==4) rnum1+=5;

					}

				}
				
			}

			else if(np==1){
				for(int a=0;a<=4;a+=2){
					int rc=1;
					// i is x and j is y
					newx = i;newy=j;

					if(!(isValid(newx+hor[a]-n,newy+ver[a]-n))) continue;

					if(points[newx+hor[a]][newy+ver[a]]==1){
						for(int count=1;count<=kk-1;count++){
							newx+= hor[a];newy+= ver[a];
							if(isValid(newx-n,newy-n)){
								if(points[newx][newy]==0) rc++;
								else break;
							}
						}
						if(rc==kk-1) r1+=36;
						else if(rc==kk-2) r1+=30;
						else if(rc==kk-3) r1+=11;
						else if(rc==kk-4) r1+=4;
						// if(rc==3) rnum2+=4;
						// else if(rc==4) rnum2+=5;

					}

				}
				
			}
		}
	}

	// cout<<"asshole fuckeddffffffffffffff"<<endl;

	db.F = (double)r1*10.0 + rnum1;
	db.S = (double)r2*10.0 + rnum2;
	// cout<<db.F<<"  "<<db.S<<endl;
	// cout<<r1<<"  "<<r2<<" "<<rnum1<<" "<<rnum2<<endl;
	return db;
}
// insert in format x,y as points[1][2] -> 1,2