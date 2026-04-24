#include <fstream>
#include <iostream>

std::string getPath() {
	std::string path;
	std::cout << "Insert path: ";
	std::cin >> path;
	return path;
}

std::ifstream openFile(const std::string &path) {
	std::ifstream file(path);

	if (!file.is_open()) {
		throw std::string("Failed to open file at: " + path);
	}
	return file;
}

void createFileIfNotExists(const std::string &path) {
	try {
		std::ifstream file = openFile(path);
		file.close();
	} catch (...) {
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
}

void resetFileState(std::ifstream &file) {
	file.clear();
	file.seekg(0, std::ios::beg);
}

void printFile(std::ifstream &file) {
	std::string line;
	std::cout << "--- File Contents ---" << std::endl;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}
	std::cout << "--- End of File ---" << std::endl;
	resetFileState(file);
}

void validateFile(std::ifstream &file) {
	long double number;

	while (file >> number) {
	}

	if (file.fail() && !file.eof()) {
		resetFileState(file);
		throw std::string("File contains non-numeric data.");
	}

	resetFileState(file);
}

long double averageFile(std::ifstream &file) {
	long double sum = 0;
	int count = 0;
	long double number;

	while (file >> number) {
		sum = sum + number;
		count++;
	}

	if (count == 0) {
		throw std::string("File is empty.");
	}

	resetFileState(file);
	return sum / count;
}

void printAverage(std::ifstream &file) {
	std::cout << "Average: " << averageFile(file) << std::endl;
}

int main() {
	try {
		std::string path = getPath();
		createFileIfNotExists(path);

		std::ifstream file = openFile(path);

		printFile(file);
		validateFile(file);
		printAverage(file);

		file.close();

	} catch (const std::string &e) {
		std::cerr << "Error: " << e << std::endl;
	} catch (...) {
		std::cerr << "Critical error occurred!" << std::endl;
	}

	return 0;
}
