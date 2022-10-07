#include "adts/node.hpp"
#include "adts/stack.hpp"
#include <iostream>
#include <cstring>
#include <string.h>
#include <fstream>

using namespace eda;

bool validate(const std::string &input, int* pos){
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
					if (acumulando.top()->getData() ==input[a]){//comenzar del carcater final para asi ir sacando del ultimo elemento
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

std::string  read(const std::string &filename){
		std::ifstream f_in(filename);
		char symbol = '\0';
		std::string leyendo;
		if (f_in.is_open()){
			while (f_in.get(symbol)){
				std::cout<<symbol;
				leyendo+=symbol;
			}
			std::cout<<std::endl;
		}
		else{
			std::cout<< "Error al leer " << filename << std::endl;
		}
		f_in.close();
	return leyendo;
}

int main(int nargs, char** argv[1]){
	std::string filename("doc1.nhtml");
	std::string texto=read(filename);//hacer que lea el html
	int pos=0;
	bool status = validate(texto, &pos);
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