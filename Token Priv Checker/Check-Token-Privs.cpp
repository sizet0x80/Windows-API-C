#include <iostream>
#include <Windows.h>
#include "size.h"

int main() {
	API api;
	std::cout << "Enter Window Name : ";
	std::getline(std::cin, api.input);
	check();
	
	return 0;
}