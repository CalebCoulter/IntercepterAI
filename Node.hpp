
class Node{
public:
	Node(std::string c){
		a=c; //convert from char to Color enum?
	}
	
	Node(char c, int s);//special=s; start space, win space
	std::tring displayColor(){
	return a;
	}
private:
//Im actually liking String as a simple categorizer-not as proper but frankly easy to implement
//enum Color{R,G,B};
std::string a;
special=0;

}