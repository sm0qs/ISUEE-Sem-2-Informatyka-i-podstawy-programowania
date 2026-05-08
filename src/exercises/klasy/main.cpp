#include <fstream>
#include <iostream>

class Car {
  private:
	std::string brand;
	std::string model;
	unsigned int year;
	double mileage;
	static int items;

  public:
	Car() : brand("unknown"), model("unknown"), year(0), mileage(0.0) { items++; }

	Car(const std::string &brand, const std::string &model, unsigned int year, double mileage)
		: brand(brand), model(model), year(year), mileage(mileage) {
		items++;
	}

	Car(const std::string path) {
		std::ifstream file(path);
		if (!file.is_open()) {
			throw std::string("Cannot open file");
		}
		file >> brand >> model >> year >> mileage;
		file.close();
		items++;
	}

	~Car() { items--; }

	void setBrand(const std::string &brand) { this->brand = brand; }
	std::string getBrand() const { return brand; }

	void setModel(const std::string &model) { this->model = model; }
	std::string getModel() const { return model; }

	void setYear(unsigned int year) { this->year = year; }
	unsigned int getYear() const { return year; }

	void setMileage(double mileage) { this->mileage = mileage; }
	double getMileage() const { return mileage; }

	int getItems() const { return items; }

	void printInfo() {
		std::cout << "/--------- Car Info: ---------" << std::endl;
		std::cout << "| Brand: " << brand << std::endl;
		std::cout << "| Model: " << model << std::endl;
		std::cout << "| Year: " << year << std::endl;
		std::cout << "| Mileage: " << mileage << std::endl;
		std::cout << "\\----------------------------" << std::endl;
	}
};

int Car::items = 0;

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
	std::ifstream openFile(path);
	if (!openFile.is_open()) {
		std::cout << "File does not exist. Creating new file\n";
		std::ofstream newFile(path);
		if (!newFile.is_open()) {
			throw std::string("Failed to create file at: " + path);
		}
		newFile << "Citroen" << std::endl;
		newFile << "C3" << std::endl;
		newFile << "2012" << std::endl;
		newFile << "120000" << std::endl;
		newFile.close();
	}
}

int main() {
	try {
		Car car1;
		car1.setBrand("Skoda");
		car1.setModel("Fabia");
		car1.setYear(2015);
		car1.setMileage(150000);
		car1.printInfo();

		Car car2("Toyota", "Corolla", 2018, 50000);
		car2.printInfo();

		std::string path = getPath();
		createFileIfNotExists(path);
		Car car3(path);
		car3.printInfo();

	} catch (const std::string &e) {
		std::cerr << "Error: " << e << std::endl;
	} catch (...) {
		std::cerr << "An unexpected error occurred." << std::endl;
	}

	return 0;
}
