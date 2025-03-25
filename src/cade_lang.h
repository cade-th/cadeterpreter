#pragma once

#include <string>
#include <vector>

class Cade_Lang {
	public:
		Cade_Lang(int argc, char *argv[]);
	
		void printArgs();	

	private:
		int argc;
		std::vector<std::string> args;
};
