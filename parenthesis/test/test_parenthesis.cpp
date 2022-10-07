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
	int tamano=input.size();
	std::string body = "body";
	const char * b = "body";
	std::string b1 = "/body";
	const char * bb1 = "/body";
	while (!error && i < input.length()){
		if (input[i] == '<') {
			int o = i + 1;
			int j = 0;
			std::string clave;
			while(input[o]!='>'){
				clave += input[o];
				o++;
			}
			if(clave == b){
				stack.push(new Node('a'));
			}
			else if(clave == bb1){
				if(stack.isEmpty()){
					error = true;
				}
				else if(stack.top()->getData() == 'a'){
					stack.pop();
				}
				else{
					error = true;
				}
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

std::string read(const std::string &filename){
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

int main(int nargs, char* argv[1]){
	std::string filename(argv[1]);
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