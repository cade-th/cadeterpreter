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
	
	switch(argc) { 
		case 1:
			// No arguments so run shell
			run_shell();
			break;
		case 2:
			// Only other argument for now can be a file
			run_file(args[1]);	
			break;
		default:
			std::cout << "Usage: Cade_Lang [script]" << "\n";
			exit(1);
			break;
	}
}

void Cade_Lang::run_shell() {
	
	bool is_running = true;

	std::string input;

	while(is_running) {
		std::cout << "cade_lang> ";	
		
		std::getline(std::cin,input);

		if(input.empty()) continue;
		if(input == ".quit") is_running = false;

		run(input);
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

std::vector<Token> Cade_Lang::tokenize_cpp(std::string input) {
    std::vector<Token> tokens;
    std::stringstream ss(input);
    std::string buffer;

    while (ss >> buffer) {
	Token temp(buffer);
        tokens.push_back(temp);
    }

    return tokens;
}

std::vector<Token> Cade_Lang::tokenize(std::string input) {
	std::vector<Token> tokens;
	std::string buffer;

	// Loop through the entire string character by character
	for (int i=0; i < input.size();i++) {
		// look for a space
		if (input[i] != ' ') {
			buffer.push_back(input[i]);
		// omit multiple spaces
		} else if (!buffer.empty()) {
			Token temp(buffer);
			tokens.push_back(temp);
			buffer.clear();
		}
	}
	// Catch the last token if the input doesn't end in a space since we don't have a string delimter for cpp strings
	if (!buffer.empty()) {
		Token temp(buffer);
		tokens.push_back(temp);
	}
	return tokens;
}

void Cade_Lang::run(std::string input) {
	std::vector<Token> tokens = tokenize(input);
}

void Cade_Lang::printArgs() {
	std::cout << "Args: " << "\n";
	for (int i=0; i < argc; i++) {
		std::cout << args[i] << "\n";
	}
}


