#include "cade_lang.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


Cade_Lang::Cade_Lang(int argc, char *argv[]) {
	this->argc = argc;
	for (int i=0; i < argc; i++) {
		// put the arguments in order by putting them at the back of the array
		args.push_back(argv[i]);
	}
	init();
}

void Cade_Lang::init() {
	if (argc == 1) {
		std::cout << "Usage: Cade_Lang [script]" << "\n";
		exit(1);
	}
	else if (argc == 2) {
		run_file(args[1]);	
		// printArgs();
	}
	else {
		run_prompt();
		// printArgs();
	}


}

void Cade_Lang::printArgs() {
	std::cout << "Args: " << "\n";
	for (int i=0; i < argc; i++) {
		std::cout << args[i] << "\n";
	}
}


void Cade_Lang::run_prompt() {
	
	bool is_running = true;

	std::string input;

	while(is_running) {
		std::cout << "cade_lang> ";	
		
		std::getline(std::cin,input);

		if(input.empty()) continue;
		if(input == ".quit") is_running = false;

		run();
	}
}
	
void Cade_Lang::run_file(const std::string& path) {
	// get the file into a cpp string
	std::ifstream file(path, std::ios::binary);

	if(!file) {
		std::cerr << "Error: Unable to open file " << path << std::endl;
		return;
	}

	std::ostringstream buffer;
	buffer <<file.rdbuf(); // Read the entire file  into the buffer
	std::string content = buffer.str();

	run(content);

}

void Cade_Lang::run() {

}

void Cade_Lang::run(std::string) {

}
