#include <iostream>

std::string getPath() {
	std::string path;
	std::cout << "Insert path: ";
	std::cin >> path;
	return path;
}

int main() {
	try {
		std::string path = getPath();
	} catch (const std::string &e) {
		std::cerr << "Error: " << e << std::endl;
	} catch (...) {
		std::cerr << "Critical error occurred!" << std::endl;
	}

	return 0;
}
