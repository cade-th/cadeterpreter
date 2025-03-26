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

		void run_file(const std::string& path);
		void run_prompt();
		
		void init();

		// So this is how you do method overloading
		// Which is compile-time(static) polymorphism
		void run();
		void run(std::string);


};
