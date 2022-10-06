#include "adts/node.hpp"
#include "adts/queue.hpp"
#include "adts/stack.hpp"
#include <iostream>
#include <cstring>
#include <string.h>

using namespace eda;

bool validateParenthesis(const std::string &input, int* pos){
	bool error = false;
	int i = 0;
	Stack stack;
	Stack acumulando;
	int tamano=input.size();
	while (!error && i < input.length()){
		if (input[i] == '<') {
			stack.push(new Node(input[i]));
			if (input[i+1]!= '/'){
				for (int j=1;j!='>';j++){//hacer que acumule lo que sigue en input
					acumulando.push(new Node(input[j]));
				}
				}
			
			else{
				for(int a=tamano-1;a!='/';a--){
					char n = *acumulando.top();
					if (n == input[a]){//comenzar del carcater final para asi ir sacando del ultimo elemento
						acumulando.pop();
					}
					else{
						error=true;
					}
				}
			}
		}
		if (input[i] == '>') {
			if (stack.isEmpty()){
				error = true;
			}
			else{
				stack.pop();
			}
		}
		i = i + 1;
	}
	if (!stack.isEmpty()){
		error = true;
	}
	*pos = i - 1 ;
	return !error;
}


int main(int nargs, char** vargs){
	std::string input;
	int pos=0;
	std::cout<<"Ingresa expresión: ";
	std::getline(std::cin, input);
	bool status = validateParenthesis(input, &pos);
	if (status){
		std::cout<< " Expresión Correcta " << std::endl;
	}
	else{
		std::cout<< " Expresión Inválida" << std::endl;
		std::cout<< "Pos error:  " << pos	<< std::endl;
	}

	return 0;
}
// hola