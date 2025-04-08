#pragma once

#include <string>
#include <vector>
#include "token.h"

class Cade_Lang {
	public:
		Cade_Lang(int argc, char *argv[]);
		void printArgs();	
		std::vector<Token> tokenize(std::string input);
		std::vector<Token> tokenize_cpp(std::string input);

	private:
		int argc;
		std::vector<std::string> args;
		void run_file(const std::string& path);
		void run_shell();
		void run(std::string);
		


};


