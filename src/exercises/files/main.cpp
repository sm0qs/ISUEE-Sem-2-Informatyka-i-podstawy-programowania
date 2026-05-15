#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::string fileName;

	try {
		std::cout << "--- TASK 1: READ LINE ---\n";
		std::cout << "Enter file name: ";
		std::cin >> fileName;

		int lineNumber;
		std::cout << "Enter line number: ";
		std::cin >> lineNumber;

		std::ifstream file1(fileName);
		if (!file1.is_open()) {
			throw std::string("Cannot open file 1");
		}

		std::string line;
		int currentLine = 1;
		bool found = false;

		while (std::getline(file1, line)) {
			if (currentLine == lineNumber) {
				std::cout << "Line " << lineNumber << ": " << line << "\n";
				found = true;
				break;
			}
			currentLine++;
		}

		if (!found) {
			throw std::string("Line not found");
		}

		file1.close();
	} catch (const std::string &e) {
		std::cout << "Error: " << e << "\n";
	} catch (...) {
		std::cout << "Unknown error in Task 1\n";
	}

	try {
		std::cout << "\n--- TASK 2: COPY AND REPLACE 'a' WITH 'A' ---\n";
		std::string copyName;
		std::cout << "Enter source file name: ";
		std::cin >> fileName;
		std::cout << "Enter destination file name: ";
		std::cin >> copyName;

		std::ifstream fileIn(fileName);
		std::ofstream fileOut(copyName);

		if (!fileIn.is_open() || !fileOut.is_open()) {
			throw std::string("Cannot open files for copying");
		}

		char c;
		while (fileIn.get(c)) {
			if (c == 'a') {
				c = 'A';
			}
			fileOut << c;
		}
		std::cout << "File copied successfully.\n";

		fileIn.close();
		fileOut.close();
	} catch (const std::string &e) {
		std::cout << "Error: " << e << "\n";
	} catch (...) {
		std::cout << "Unknown error in Task 2\n";
	}

	try {
		std::cout << "\n--- TASK 3: GET FILE SIZE ---\n";
		std::cout << "Enter file name: ";
		std::cin >> fileName;

		std::ifstream file3(fileName, std::ios::binary | std::ios::ate);
		if (!file3.is_open()) {
			throw std::string("Cannot open file 3");
		}

		std::cout << "Size: " << file3.tellg() << " bytes\n";
		file3.close();
	} catch (const std::string &e) {
		std::cout << "Error: " << e << "\n";
	} catch (...) {
		std::cout << "Unknown error in Task 3\n";
	}

	return 0;
}
