
class Node{
public:
	Node(char c){
		a=c; //convert from char to Color enum?
	
	}
	
	Node(char c, int s);//special=s; start space, win space
	String displayColor(){
	return a;
	}
private:
enum Color{R,G,B};
Color a;
special=0;

}