#include "board.h"
#include "player.h"


double maxim(int id, board& b, int depth)
{
	int next_player;
	if(id==1) next_player=2;
	else next_player=1;

	double max_score=0.0,present_score;

	if(depth==0){
		pair<double,double> pr = b.score();
		if(id==1) present_score = pr.F;
		else present_score = pr.S;
		return present_score;
	}

	vector<string> nb = generate_neighbour(id,b);
	
	string best_move;
	for(int i=0;i<nb.size();i++){
		board copy_board(b);
		execute_move(id,nb[i],copy_board);
		// present_score = copy_board.score();
		present_score = minim(next_player,copy_board,depth-1);
		if(present_score>max_score){
			best_move = nb[i];
			max_score = present_score;
		}
	}
	return max_score;
}

double minim(int next_player, board& b, int depth)
{
	int id;
	if(next_player==1) id=2;
	else id=1;

	double min_score=0.0,present_score;

	if(depth==0){
		pair<double,double> pr = b.score();
		if(id==1) present_score = pr.F;
		else present_score = pr.S;
		return present_score;
	}

	vector<string> nb = generate_neighbour(next_player,b);
	// double min_score=100.0,present_score;
	// string best_move;
	for(int i=0;i<nb.size();i++){
		board copy_board(b);
		execute_move(next_player,nb[i],copy_board);
		// present_score = copy_board.score();
		present_score = maxim(id,copy_board,depth-1);
		if(present_score<min_score){
			// best_move = nb[i];
			min_score = present_score;
		}
	}
	return min_score;
}