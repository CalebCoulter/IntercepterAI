/* 
 * File:   main.cpp
 *
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <stdio.h>
#include <cmath>
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
    char color;
    Node * board;
   //Input intended to create a square board of user selected size and fill
   //the board with random colors. The number of colors is specified by user.
    Board(int size, int num_of_colors){ 
        width= size;
        Node game_board[size*size];
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                game_board[i*size+j].color = rand_color_gen(num_of_colors);
                
            }
        }
        
       
    }
      char getColor(int y, int x){
        //return (board + y*width + x)->color;
        
   }
      char getColor(){
          return color;
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
    int width;
    int height;
    int num_of_colors;
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
void default_print_board(char b[5][5]);
void default_playermove(int x, int y, char b[5][5]);
void AI_move(char b[5][5], int predict[][2]);

void AI_predict_playermove(int x, int y, char b[5][5]);

bool target_activated = 0;
bool game_over = 0;
//int AI_prediction[2];
std::queue<char> playerBuffer;
std::queue<char> buffer;
char list[4];
int AILoc[2];

//result of AI move algorithm
 int result[2];
std::queue< int * > AIList;

char default_playboard[5][5] ={{'I','0','0','0','0'},
                                   {'0','0','0','0','0'},
                                   {'0','0','0','0','0'},
                                   {'0','0','0','0','0'},
                                   {'0','0','X','0','0'}};
    
    char default_specialboard[5][5] ={{'t','0','t','0','t'},
                                      {'0','0','0','0','0'},
                                      {'0','0','0','0','0'},
                                      {'0','0','0','0','0'},
                                      {'0','g','0','g','0'}};
  
void set_console_color(char clr){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    
    int c;
    //12 = r, 10 = g, 9 = b, y = 14, p = 13, White = 15
    switch(clr){
        case('r'): c = 12;
        break;
        case('g'): c = 10;
        break;
        case('b'): c = 9;
        break;
        case('y'): c = 14;
        break;
        case('p'): c = 13;
        break;
        default: c = 15;
        break;
    }
    SetConsoleTextAttribute(hConsole, c);
}

void reset_console_color(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
}

void print_move_history();

int main(int argc, char** argv) {
    srand(time(NULL));
    int board_size = 5;
    int num_of_colors = 3;
    
    
    //SetConsoleTextAttribute(hConsole, 12);
    //set_console_color('r');
    
    
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    for(int clr = 1; clr < 255; clr++){
//    SetConsoleTextAttribute(hConsole, clr);
//    cout << clr << "This is color output\n";
//    }
    
    
    //Board defaultgameboard = Board();
    
    cout << "Welcome to Interceptor Console Debugger!\n";
//    cout << "Please enter the size of the board: ";
//    cin >> board_size;
//    cout << "How many colors would you like? (1-5): \n";
//    cin >> num_of_colors;
//    cout << "Generating Board...\n";
//    Board gameboard = Board(board_size,num_of_colors);
//    gameboard.height=board_size;
//    gameboard.width=board_size;
//    gameboard.num_of_colors=num_of_colors;
//    print_board(gameboard);
    char default_gameboard[5][5] = {{'r','g','b','r','b'},
                                   {'b','g','r','r','g'},
                                   {'b','g','g','g','r'},
                                   {'g','b','r','r','r'},
                                   {'r','b','b','b','g'}};
    
   
    while(game_over == 0){
        default_print_board(default_gameboard);
        default_playermove(2,4,default_gameboard);
        buffer=playerBuffer;
        if(game_over != 1){
                //AI_predict_playermove(2,4,default_gameboard);
                print_move_history();
        }
        
    }
    
    cout << "\n\n===================\n=====GAME OVER=====\n===================\n";
    
    
    
    
    
    return 0;
}

void default_AI_predict_move(int x, int y, char b[5][5]){
    
}

void print_move_history(){
    std::queue<char> history;
    history=playerBuffer;
    cout << "History of player moves:";
    for(int i=0; i<buffer.size();i++){
        cout << history.front();
        history.pop();
        //if(i>20)
           // break;
    }
    cout << endl;
}

void AI_visitNeighbors(int y, int x, char b[5][5]){
    //char list[4];
    if (y>0){//left
        list[0]=b[x][y-1];   
    }
    else{
        list[0]='n';   
    }
    if (y<4){//right
        list[1]=b[x][y+1];   
    }
    else{
        list[1]='n';   
    }
    if (x>0){//up
        list[2]=b[x-1][y];   
    }
    else{//down
        list[2]='n';   
    }
    if (x<4){
        list[3]=b[x+1][y];   
    }
    else{
        list[3]='n';   
    }
    //cout<<"neighbors: "<<list[0]<<" "<<list[1]<<" "<<list[2]<<" "<<list[3]<<"\n";
    //return list;
}
//from the location board, move closer to the given location. Prioritizes longer distances
//ie 0,0-> 2,4 will move to 0,1
void getMove(int x, int y, int x2, int y2){
    int xsum= x+x2;
    int ysum= y+y2;
   
    if (abs(xsum)>abs(ysum)){
        result[1]=y;
        if (xsum>0)//go left
            result[0]=x-1;
        else 
            result[0]=x+1;
    }
    else
        result[0]=x;
        if(ysum>0)
            result[1]=y-1;
    else if(y<4)//default, move down
        
            result[1]=y+1;
    else //total default-in case something goes wrong with calculations and it can't move down, it can move up
        
            result[1]=y-1;
        
}
void getMoveKnown(int x, int y, int x2, int y2){
   
    if (target_activated){//bias towards top, closer to target
         int xsum= x+x2;
         int ysum= y+y2-1;
    if (abs(xsum)>abs(ysum)){
        result[1]=y;
        if (xsum>0)//go left
            result[0]=x-1;
        else 
            result[0]=x+1;
    }
    else
        result[0]=x;
        if(ysum>0)
        
        result[1]=y-1;
    else if(y<4)//default, move down
        result[1]=y+1;
    else //total default-in case something goes wrong with calculations and it can't move down, it can move up
        result[1]=y-1;;
    }//else, target not activated, bias towards bottom, closer to target
     int xsum= x+x2;
         int ysum= y+y2+1;
    if (abs(xsum)>abs(ysum)){
        result[1]=y;
        if (xsum>0)//go left
            result[0]=x-1;
        else 
            result[0]=x+1;;
    }
    else
        result[0]=x;
        if(ysum>0)
        
        result[1]=y-1;
    else if(y<4)//default, move down
        result[1]=y+1;
    else //total default-in case something goes wrong with calculations and it can't move down, it can move up
        result[1]=y-1;
    
}

//AI prediction will return if they have a single predicted location. Otherwise, default behavior
void AI_move(char b[5][5], int predX, int predY ){

    int x=AILoc[1];
    int y=AILoc[0];
    //int coords[2];
    if (predX>=0){//we have a single prediction, move towards player. 
      
      
       getMoveKnown(x,y,predX,predY);
        
    } else{//target unknown, move towards goal
        if (!target_activated){
            getMove(x,y,1,2);//move to the center, diagonal from both nodes
        }
        else
           getMove(x,y,3,2);//move towards the goal, diagonal from both nodes
    }
     if(default_playboard[result[0]][result[1]] == 'X'){
                        game_over = 1;
                    }
                    if(game_over != 1){
                        default_playboard[y][x] = '0';
                        default_playboard[result[1]][result[0]] = 'I';
                        cout <<"Computer moved moved : "<< b[result[1]][result[0]]<< "\n";
                        AILoc[1]=result[1];
                        AILoc[0]=result[0];
                    }

};





void AI_predict_playermove(int x, int y, char b[5][5]){
    int x_coord=x;
    int y_coord=y;
    int moves = buffer.size();
    int AI_prediction[2];
    if(moves>0){
    for(int j=0; j<moves; j++){
        AI_visitNeighbors(x_coord,y_coord, b);
        char c = buffer.front();
        buffer.pop();
        for (int i=0; i<4; i++){
           
            if   (list[i]==c){
                
                if (j==moves-1){
                    // if (i==0){
                    // AI_prediction[0]=x-1;
                    // AI_prediction[1]=y;
                    //AIList.push(AI_prediction);
                    //cout<< i;
                     //}
                      if (i==1){
                    AI_prediction[0]=x+1;
                     AI_prediction[1]=y;
                    AIList.push(AI_prediction);
                    cout<< i;
                     } if (i==2){
                     AI_prediction[0]=x;
                     AI_prediction[1]=y-1;
                    AIList.push(AI_prediction);
                    cout<< i;
                     }if (i==3) //i==3 
                    {
                     AI_prediction[0]=x-1;
                     AI_prediction[1]=y;
                    AIList.push(AI_prediction);
                    cout<< i;
                    }
                     
                     cout << "AI predicted player location: ";
                     int a=AIList.size();
                     for (int i = 0; i<a;i++){
                      cout << AIList.front()[0]+1<<","<< AIList.front()[1]+1<<" ";
                      AIList.pop();
                     }
                     cout << "\n";
                    
                     break;
                }
                else{ if (i==0){
                     AI_predict_playermove(x_coord-1,y_coord,b);
                     
                }
                 if (i==1){
                     AI_predict_playermove(x_coord+1,y_coord,b);
                     
                } if (i==2){
                     AI_predict_playermove(x_coord,y_coord-1,b);
                     
                }if(i==3) //i==3 
                {
                     AI_predict_playermove(x_coord,y_coord+1,b);
                     
                }}break;
            }}
        }
}
}

void check_target(int y, int x){
    if(default_playboard[y][x] == 'X' && default_specialboard[y][x] == 't'){
        target_activated = 1;

        cout << "Player reached target at: " << x+1 << "," << y+1 << "\n";
    }
}

void check_goal(int y, int x){
    if(default_playboard[y][x] == 'X' && default_specialboard[y][x] == 'g' && target_activated == 1){
        cout << "Player reached goal at: " << x+1 << "," << y+1 << "\n";
        cout << "\nPlayer wins!!!!\n";
        game_over = 1;
    }
}

void default_playermove(int x, int y, char b[5][5]){
    char move;
    int x_coord=x;
    int y_coord=y;
  //  bool retry_move = 0;
    cout << "Player, make your move (u,d,l,r):";
    //do{
        //retry_move = 0;
        cin >> move;
        if (move != 'u' && move != 'd' && move != 'l' && move != 'r'){
           // retry_move = 1;
            cout << "That is not a valid move, try again:";
        }
        else{
            
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    if(default_playboard[i][j] == 'X'){
                        x_coord = j;
                        y_coord = i;
                    }
                }
            }
            if(move == 'u'){
                if (y_coord>0){
                    if(default_playboard[y_coord-1][x_coord] == 'I'){
                        game_over = 1;
                    }
                    if(game_over != 1){
                        default_playboard[y_coord][x_coord] = '0';
                        default_playboard[y_coord-1][x_coord] = 'X';
                        cout <<"player moved : "<< b[y_coord-1][x_coord]<< "\n";
                        check_target(y_coord-1, x_coord);
                        check_goal(y_coord-1, x_coord);
                        playerBuffer.push(b[y_coord-1][x_coord]);
                    }
                }
                else{
                    cout << "that is not a valid move, try again:\n";
                    //default_playermove(b);
            }
            }
            if(move == 'd'){
                if (y_coord<4){
                    if(default_playboard[y_coord+1][x_coord] == 'I'){
                        game_over = 1;
                    }
                    if(game_over != 1){
                        default_playboard[y_coord][x_coord] = '0';
                        default_playboard[y_coord+1][x_coord] = 'X';
                        cout <<"player moved : "<< b[y_coord+1][x_coord]<< "\n";
                        check_target(y_coord+1, x_coord);
                        check_goal(y_coord+1, x_coord);
                        playerBuffer.push(b[y_coord+1][x_coord]);
                    }
                }
                else{
                    cout << "that is not a valid move, try again:\n";
                    //default_playermove(b);
            }
            }
            if(move == 'l'){
                if (x_coord>0){
                    if(default_playboard[y_coord][x_coord-1] == 'I'){
                        game_over = 1;
                    }
                    if(game_over != 1){
                        default_playboard[y_coord][x_coord] = '0';
                        default_playboard[y_coord][x_coord-1] = 'X';
                        cout <<"player moved : "<< b[y_coord][x_coord-1]<< "\n";
                        check_target(y_coord, x_coord-1);
                        check_goal(y_coord, x_coord-1);
                        playerBuffer.push(b[y_coord][x_coord-1]);
                    }
            }
                else{
                    cout << "that is not a valid move, try again:\n";
                    //default_playermove(b);
               
            }
            }
            if(move == 'r'){
                if (x_coord<4){
                    if(default_playboard[y_coord][x_coord+1] == 'I'){
                        game_over = 1;
                    }
                    if(game_over != 1){
                        default_playboard[y_coord][x_coord] = '0';
                        default_playboard[y_coord][x_coord+1] = 'X';
                        cout <<"player moved : "<< b[y_coord][x_coord+1]<< "\n";
                        check_target(y_coord, x_coord+1);
                        check_goal(y_coord, x_coord+1);
                        playerBuffer.push(b[y_coord][x_coord+1]);
                        //cout << "["<<playerBuffer.back()<<"]";
                    }
                }
                else{
                    cout << "that is not a valid move, try again:\n";
                    //default_playermove(b);

            
            }
            }
        }
    //}while(retry_move == 1);
    
}

void default_print_board(char b[5][5]){
    for(int j=0; j<5; j++){
        cout << "\t" << j+1;
    }
    cout << "\n";
    for(int j=0; j<5; j++){
        cout << "\t" << "_";
    }

    cout << "\n\n";
    
    for(int i=0; i<5; i++){
        cout << i+1 << "|";
        for(int j=0; j<5; j++){
            if(default_playboard[i][j] == '0'){ //Prints Color on board as that color
//                switch(b[i][j]){
//                    case('r'): set_console_color('r');
//                    break;
//                    case('g'): set_console_color('g');
//                    break;
//                    case('b'): set_console_color('b');
//                    break;
//                    case('y'): set_console_color('y');
//                    break;
//                    case('p'): set_console_color('p');
//                    break;
//                    default: reset_console_color();
//                    cout << "WASN'T A COLOR! ERROR!";
//                    break;
//                }
                cout << "\t" << b[i][j];
                
            }
            else{
                cout << "\t" << default_playboard[i][j];
            }
            
            
        }
        cout << "\n" << "\n";
        
    }
//    reset_console_color(); //Resets console text back to white after printing
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
            cout << "\t" << b.getColor();
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