#pragma once 
#include <string>

class Token {
	public:
		Token(std::string data);
		std::string data;
	private:
		
};

class Operator : Token {
	public:
		Operator();
	private:
};

class Label : Token {
	public: 
		Label();
	private:
};

