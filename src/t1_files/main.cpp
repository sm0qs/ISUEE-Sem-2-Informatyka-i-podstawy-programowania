#include <fstream>
#include <iostream>

std::string getPath() {
	std::string path;
	std::cout << "Insert path: ";
	std::cin >> path;
	return path;
}

void createFileIfNotExists(const std::string &path) {
	std::ifstream file(path);
	if (!file.good()) {
		std::cout << "File does not exist. Creating new file at: " << path << std::endl;
		std::ofstream newFile(path);
		if (!newFile.is_open()) {
			throw std::string("Failed to create file at: " + path);
		}
		newFile << "123" << std::endl;
		newFile << "456" << std::endl;
		newFile << "789" << std::endl;
		newFile.close();
	}

	file.close();
}

int main() {
	try {
		std::string path = getPath();
		createFileIfNotExists(path);

	} catch (const std::string &e) {
		std::cerr << "Error: " << e << std::endl;
	} catch (...) {
		std::cerr << "Critical error occurred!" << std::endl;
	}

	return 0;
}
