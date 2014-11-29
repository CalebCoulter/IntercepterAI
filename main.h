/* 
 * File:   main.cpp
 * Author: Jordan
 *
 */

#include <cstdlib>
#include <iostream>

using namespace std;




class Node{
public:
    Node(){};
    
    Node(std::string color){
        cout << "making a node of a color "<< color << endl; 
            a=color; //convert from char to Color enum?
    }

    Node(char color, int s);//special=s; start space, win space
    std::string displayColor(){
    return a;
    }

    
        
std::string a;
//int special=0;
char color;
private:
//Im actually liking String as a simple categorizer-not as proper but frankly easy to implement
//enum Color{R,G,B};


};


char rand_color_gen(int num_of_colors);

class Board{
public:
    int width;
    int height;
    int num_of_colors;
    Node * board;
   //Input intended to create a square board of user selected size and fill
   //the board with random colors. The number of colors is specified by user.
    Board(int size, int num_of_colors){ 
        width= size;
        Node game_board[size*size];
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                game_board[i*size+j].color = rand_color_gen(num_of_colors);
                //cout << game_board[i*size+j].color;
            }
            
        }
        cout << game_board[size*size-1].color<< "\n";
        board=game_board;
        cout << board[size*size-1].color << "\n" << "hmm";
        cout << board[width*width-1].color;
    }
      char getColor(int x, int y){
       // cout <<y<<" "<< x << " " << y*width+x;
       cout << board[width*width-1].color;
        return board[y*width + x-1].color;   
   }
    //constructor-take an array and dimensions
//    Board(const int w, int h, Node nodes[5][5]){
//            width=w;
//            height=h;
//            boardArray = new Node[h][5];//I might have screwed up board building, double check this 
//            int counter=0;
//            for (int i=h; i>0; i--){
//                    for (int j=w; j>0; j--)
//                    boardArray[i][j]=nodes[counter];
//                    counter++;
//                    }
//        }
//    
//    //Checks if a move is valid, given a player position and intended position
//    bool checkMove(int player, int x, int y){
//        int spot= y*width+x;
//        bool check= spot>=0&&spot<=height*width&&(spot==positions[player]+1||spot==positions[player]-1||spot==positions[player]+width||spot==positions[player]-width);//Makes sur spot isnt too big, too small, and that its either one up down left or right from the players current position
//        return check;
//    }
//
//    
//    //Takes the 1-dimensional player position int and translates it to the coordinate format.
//    // index looks like :
//    // 0 1 2
//    // 3 4 5
//    // 6 7 8
//    
//    //instead of
//    //   1 2 3
//    // 1 x x x
//    // 2 x x x 
//    // 3 x x x
//    
//    int getPos(player){
//        return int pos=[positions[player] / width , positions[player] % width];
//    }
//    
//    //"visiting" a space is the computer players method of looking at the board. It returns the color that is displayed in that square
//    std::string visit(int x, int y){
//            return nodes[x][y].displayColor();
//    } //visit should be called by a cpu method that first gets all neighbors and then looks at any that isn't a negative value
//    
//    
//    //returns neighbor coordinates in an array-    up, down, left, right
//    int[] getNeighbors(int x, int y)
//        int up=-1, down=-1, left=-1, right=-1;//negatives are invalid spaces-the cpu's checkNeighbor's methods shouldnt look in spaces where any value is a negative. Any better way of implementing this?
//        
//        if (y >0){
//        
//            up=y-1;
//            
//        }
//        
//        if (y <height)
//        
//            down= y + 1;
//        
//        if (x > 0){
//         left = x - 1;
//        }
//        if (x < width){
//            right = x + 1;
//        }
//        int directions= [[x,up],[x,down],[left,y],[right,y]];
//        return directions;
//        }
//        
//    // returns a string ready to display the board
//    std::string displayBoard(){
//        std::string board=new std::string();
//        for (int i=h; i>0; i--){
//            for (int j=w; j>0; j--){//add a line. Should there be delimiters between each cell?
//            //ie:
//            // 1 2 3  or  1|2|3
//    }            board= board+nodes[i][j].displayColor()+ " ";
//            }//break the line. Delimiting would make this look icky
//        board= board + "/n";//newline!
//        };
    
private:
    //Node boardArray[][];
//    int width=0;
//    int height=0;
//    int positions[1];//position by index. PLayer is [0], computer is [1]
};


/*
 * PROTOTYPES
 */


void print_board(Board b);

int main(int argc, char** argv) {
    srand(time(NULL));
    int board_size = 5;
    int num_of_colors = 3;
    
    cout << "Welcome to Interceptor Console Debugger!\n";
    cout << "Please enter the size of the board: ";
    cin >> board_size;
    cout << "How many colors would you like? (1-5): \n";
    cin >> num_of_colors;
    cout << "Generating Board...\n";
    Board gameboard = Board(board_size,num_of_colors);
    gameboard.height=board_size;
    gameboard.width=board_size;
    gameboard.num_of_colors=num_of_colors;
    print_board(gameboard);
    
    
    return 0;
}

void print_board(Board b){
    for(int j=0; j<b.width; j++){
        cout << "\t" << j+1;
    }
    cout << endl;
    for(int j=0; j<b.width; j++){
        cout << "\t" << "_";
    }
    cout << endl << endl;
    
    for(int i=0; i<b.height; i++){
        cout << i+1 << "|";
        for(int j=0; j<b.width; j++){
            cout << "\t" << b.getColor(j, i);
        }
        cout << endl << endl;
    }
    
}


char rand_color_gen(int num_of_colors){
        int x = rand()%num_of_colors; //Randomly selects a color based on number of colors in game
        //r=red; g=green; b=blue; y=yellow; p=pink/purple
        switch(num_of_colors){
            case(1): return 'r';
                break;
            case(2):
                if(x == 0) return 'r';
                else if(x == 1) return 'g';
                else cout<< "\nrand_color_gen ERROR - case 2\n";
                break;
            case(3):
                if(x == 0) return 'r';
                else if(x == 1) return 'g';
                else if(x == 2) return 'b';
                else cout<< "\nrand_color_gen ERROR - case 3\n";
                break;
            case(4):
                if(x == 0) return 'r';
                else if(x == 1) return 'g';
                else if(x == 2) return 'b';
                else if(x == 3) return 'y';
                else cout<< "\nrand_color_gen ERROR - case 4\n";
                break;
            case(5):
                if(x == 0) return 'r';
                else if(x == 1) return 'g';
                else if(x == 2) return 'b';
                else if(x == 3) return 'y';
                else if(x == 4) return 'p';
                else cout << "\nrand_color_gen ERROR - case 5\n";
                break;
            default: 
                cout << "Currently not supported. Defaulting settings.";
                int x = rand()%3;
                if(x == 0) return 'r';
                else if(x == 1) return 'g';
                else if(x == 2) return 'b';
                else cout << "\nrand_color_gen ERROR - DEFAULT CASE\n";
        }

    }