#ifndef LEXER_H
#define LEXER_H

#include<string>
#include<vector>
#include<variant>

enum class TokenType{
	CONSOLE,
	LOG,
	DOT,
	L_PAREN,
	R_PAREN,
	SEMI_COLON,
	STRING,
	NUMBER,
	BOOLEAN
};

using TokenData = std::variant<std::string,char,double>;

class Token{
	public:
		TokenType type;
		TokenData data;
		Token(){}
		Token(TokenType type): type(type){}
};

void Lexer();
std::vector<Token> line_lexer(const std::string& line);

#endif
