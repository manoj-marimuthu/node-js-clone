#include "lexer.h"
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<ctype.h>
#include<stdexcept>

void Lexer(){

}

std::vector<Token> line_lexer(const std::string& line ){
	int i =0;
	int n = line.length();
	std::vector<Token> output;
	while(i < n){
		Token t;
		if(isspace(line[i])){
			i++;
			continue;
		}
		else if(isalpha(line[i]) || line[i] == '_'){
			std::string s;
			while(isalpha(line[i]) || line[i] == '_'){
				s += line[i++];
			}
			if(s == "console"){
				t.type = TokenType::CONSOLE;
				t.data = s;
			}else if(s == "log"){
				t.type = TokenType::LOG;
				t.data = s;
			}else{
				throw std::runtime_error("Unknown runtime identifier found :" + s);
			}
		}else if(line[i] == '"' || line[i] == '\''){
			char quote = line[i];
			i++;
			std::string s;
			while(i < n && line[i] != quote){
				s += line[i++];
			}
			if(line[i] == quote) i++;
			else throw std::runtime_error(std::string("Missing termination of") + quote + " during string creation");
			t.type = TokenType::STRING;
			t.data = s;
		}
		else if(line[i] == '.'){
			t.type = TokenType::DOT;
			i++;
		}
		else if(line[i] == ';'){
			t.type = TokenType::SEMI_COLON;
			i++;
		}
		else if(line[i] == '('){
			t.type = TokenType::L_PAREN;
			i++;
		}
		else if(line[i] == ')'){
			t.type = TokenType::R_PAREN;
			i++;
		}
		else{
			throw std::runtime_error(std::string("Unknown character found by lexer : ") + line[i]);
		}
		output.push_back(t);
	}
	return output;
}
