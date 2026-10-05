#include<iostream>
#include<variant>
#include "lexer.h"

int main(){
	std::cout << "Hello World" << std::endl;
	std::vector<Token> tokens = line_lexer("console.log(\"Hello World\");");
	for(const auto& token: tokens){
		if(token.type == TokenType::CONSOLE || token.type == TokenType::LOG){
			std::cout << std::get<std::string>(token.data) << "->";
		}else if(token.type == TokenType::L_PAREN){
			std::cout << "( -> ";
		}else if(token.type == TokenType::R_PAREN){
			std::cout << ") -> ";
		}else if(token.type == TokenType::DOT){
			std::cout << ". -> ";
		}else if(token.type == TokenType::SEMI_COLON){
			std::cout << "; -> ";
		}else{
			std::cout << std::get<std::string>(token.data) << "-> ";
		}
	}
	return 0;
}
