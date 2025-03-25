#include "cade_lang.h"
#include <iostream>


Cade_Lang::Cade_Lang(int argc, char *argv[]) {
	this->argc = argc;

	for (int i=0; i < argc; i++) {
		args.push_back(argv[i]);
	}

}

void Cade_Lang::printArgs() {
	for (int i=0; i < argc; i++) {
		std::cout << "Args: " << args[i] << "\n";
	}
}
