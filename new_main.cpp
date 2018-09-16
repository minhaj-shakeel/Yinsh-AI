#include "player.h"
#include "board.h"

void print_board(board& b)
{
	for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            if(b.points[i][j]==10){

                cout<<" "<<" ";
            }
            else if(b.points[i][j]==-1)
                cout<<b.points[i][j];
            else
            	cout<<" "<<b.points[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
	board b;
	player p(1);

	p.execute_move(1,"P 0 0" , b);
	p.execute_move(1,"P 1 0" , b);
	p.execute_move(1,"P 1 0" , b);
	p.execute_move(1,"P 0 0" , b);
	p.execute_move(1,"P 0 0" , b);
	p.execute_move(1,"P 0 0" , b);


	
	


	 
}