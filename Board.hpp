

class Board
{
public
	//constructor-take an array and dimensions
	Board(int w, int h, Node nodes[]){
		width=w;
		height=h;
		boardArray= new Node[h][w]
		counter=0;
		for (int i=h; i>0; i--){
			for (int j=w; j>0; j--)
			boardArray[i][j]=nodes[counter];
			counter++;
			
			}
			
		}
		
	//Takes the 1-dimensional player position int and translates it to the coordinate format.
	// index looks like :
	// 0 1 2
	// 3 4 5
	// 6 7 8
	
	//instead of
	//   1 2 3
	// 1 x x x
	// 2 x x x 
	// 3 x x x
	int getPos(player){
		return int pos=[positions[player] / w , positions[player] % w];
	}
	
	//"visiting" a space is the computer players method of looking at the board. It returns the color that is displayed in that square
	String visit(int x, int y){
			return nodes[x][y].displayColor();
	} //visit should be called by a cpu method that first gets all neighbors and then looks at any that isn't a negative value
	
	
	//returns neighbor coordinates in an array-    up, down, left, right
	int[] getNeighbors(int x, int y)
		int up=-1, down=-1, left=-1, right=-1;//negatives are invalid spaces-the cpu's checkNeighbor's methods shouldnt look in spaces where any value is a negative. Any better way of implementing this?
		
		if (y >0){
		
			up=y-1;
			
		}
		
		if (y <h)
		
			down= y + 1;
		
		if (x > 0){
		 left = x - 1;
		}
		if (x < w){
			right = x + 1;
		}
		int directions= [[x,up],[x,down],[left,y],[right,y]];
		return directions;
		}
private
	Node boardArray[][];
	int width=0;
	int height=0;
	int positions[1];//position by index. PLayer is [0], computer is [1])
	}