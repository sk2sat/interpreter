#include <iostream>

int main(int argc, char **argv){
	for(;;){
		std::string code;
		std::cout<<"> ";
		std::cin>>code;
		if(code == "exit") break;
	}
	return 0;
}
