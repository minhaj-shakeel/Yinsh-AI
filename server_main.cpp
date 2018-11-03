#include "player.h"
#include "board.h"
#include <fstream>
#include <ctime>

using namespace std;

// ofstream Out("mainout.txt");


// Sample C++ Code 
int main() {

	// ofstream outputfile("out.txt");
    
    int player_id, board_size, time_limit;
    string move;
    // Get input from server about game specifications
    cin >> player_id >> board_size >> time_limit;

    // if(player_id == 2) {
    //     // Get other player's move
    //     cin>>move; 
        
    //     while(true) {
    //         cout<<"P 1 0"<<endl;
    //         cin>>move;
    //     }
    // }   
    // else if(player_id == 1) {
    //     while(true) {
    //         cout<<"P 0 0"<<endl;
    //         cin>>move; 
    //     }
    // }
    board b;
	player p(player_id);

	start = clock();

	// Out<<"letsgo"<<endl;

    

    if(player_id == 2) {
        // Get other player's move
        // cin>>move;
        move.clear();
        while(move.size() == 0)
        getline(cin,move);
        p.id = 1;
        p.execute_move(1,move,b);
        
        while(true) {
            // cout<<"P 1 0"<<endl;
            p.id = 2;
            string str = p.generate_move(2,b);
            // str = "P 0 0";
            char a = str[str.length()-1];
            if(isblank(a))
            str = str.substr(0,str.length()-1);
            // Out<<str<<"mmmm"<<endl;
            cout<<str<<endl;


            p.execute_move(2,str,b);

            // cin>>move;
            move.clear();
            while(move.size() == 0)
            getline(cin,move);
            // Out<<move<<"move"<<endl;
            p.id = 1;
            p.execute_move(1,move,b);
        }
    }   
    else if(player_id == 1) {
        while(true) {
            // cout<<"P 0 0"<<endl;
            // cin>>move; 
        	p.id = 1;
            string str = p.generate_move(1,b);

            // str = "P 1 1";

           	// Out<<str<<endl;

            cout<<str<<endl;
            p.execute_move(1,str,b);



            // cin>>move;
            move.clear();
            while(move.size() == 0)
            getline(cin,move);
            // Out<<"move:"<<move<<endl;
            p.id = 2;
            p.execute_move(2,move,b);
        }
    }

    return 0;
}