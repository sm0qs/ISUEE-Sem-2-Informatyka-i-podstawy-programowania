#include <fstream>
#include <iostream>

class Date {
  private:
	unsigned int year, month, day;

  public:
	Date() : year(0), month(0), day(0) {}
	Date(unsigned int year, unsigned int month, unsigned int day)
		: year(year), month(month), day(day) {}

	friend std::ostream &operator<<(std::ostream &os, const Date &d) {
		os << d.year << "-" << d.month << "-" << d.day;
		return os;
	}

	friend std::istream &operator>>(std::istream &is, Date &d) {
		is >> d.year >> d.month >> d.day;
		return is;
	}
};

class Car {
  private:
	std::string brand;
	std::string model;
	unsigned int year;
	double mileage;
	static int items;
	Date *inspections;

  public:
	Car() : brand("unknown"), model("unknown"), year(0), mileage(0.0) {
		items++;
		inspections = new Date[20];

		for (int i = 0; i < 20; i++) {
			inspections[i] = Date();
		}
	}

	Car(const std::string &brand, const std::string &model, unsigned int year, double mileage)
		: brand(brand), model(model), year(year), mileage(mileage) {
		items++;
		inspections = new Date[20];
	}

	Car(const std::string path) {
		items++;
		inspections = new Date[20];

		readFromFile(path);
	}

	Car(const Car &other)
		: brand(other.brand), model(other.model), year(other.year), mileage(other.mileage) {
		items++;
		inspections = new Date[20];
		for (int i = 0; i < 20; i++) {
			inspections[i] = other.inspections[i];
		}
	}

	Car &operator=(const Car &other) {
		if (this != &other) {
			brand = other.brand;
			model = other.model;
			year = other.year;
			mileage = other.mileage;

			for (int i = 0; i < 20; i++) {
				inspections[i] = other.inspections[i];
			}
		}
		return *this;
	}

	~Car() {
		delete[] inspections;
		items--;
	}

	void setBrand(const std::string &brand) { this->brand = brand; }
	std::string getBrand() const { return brand; }

	void setModel(const std::string &model) { this->model = model; }
	std::string getModel() const { return model; }

	void setYear(unsigned int year) { this->year = year; }
	unsigned int getYear() const { return year; }

	void setMileage(double mileage) { this->mileage = mileage; }
	double getMileage() const { return mileage; }

	static int getItems() { return items; }

	void printInfo() {
		std::cout << "/--------- Car Info: ---------" << std::endl;
		std::cout << "| Brand: " << brand << std::endl;
		std::cout << "| Model: " << model << std::endl;
		std::cout << "| Year: " << year << std::endl;
		std::cout << "| Mileage: " << mileage << std::endl;
		std::cout << "\\----------------------------" << std::endl;
	}

	void saveToFile(const std::string &path) const {
		std::ofstream file(path);
		if (!file.is_open()) {
			throw std::string("Failed to open file for writing at: " + path);
		}

		file << brand << std::endl;
		file << model << std::endl;
		file << year << std::endl;
		file << mileage << std::endl;

		for (int i = 0; i < 20; i++) {
			file << inspections[i] << std::endl;
		}

		file.close();
	}

	void readFromFile(const std::string &path) {
		std::ifstream file(path);
		if (!file.is_open()) {
			throw std::string("Failed to open file at: " + path);
		}

		file >> brand >> model >> year >> mileage;

		for (int i = 0; i < 20; i++) {
			file >> inspections[i];
		}

		file.close();
	}
};

int Car::items = 0;

std::string getPath() {
	std::string path;
	std::cout << "Insert path: ";
	std::cin >> path;
	return path;
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
		car1.saveToFile("car1.txt");

		Car car2("Toyota", "Corolla", 2018, 50000);
		car2.printInfo();

		std::string path = getPath();
		createFileIfNotExists(path);
		Car car3(path);
		car3.printInfo();

		Car car4 = car1;
		car4.printInfo();

		std::cout << "Current number of Car objects in memory: " << Car::getItems() << std::endl;

	} catch (const std::string &e) {
		std::cerr << "Error: " << e << std::endl;
	} catch (...) {
		std::cerr << "An unexpected error occurred." << std::endl;
	}

	return 0;
}
