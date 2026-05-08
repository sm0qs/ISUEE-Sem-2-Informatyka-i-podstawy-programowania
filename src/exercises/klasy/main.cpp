#include <fstream>
#include <iostream>

class Samochod {
  private:
	std::string marka;
	std::string model;
	unsigned int rocznik;
	double przebieg;
	static int ileObiektow;

  public:
	Samochod() : marka("nieznana"), model("nieznany"), rocznik(0), przebieg(0.0) { ileObiektow++; }

	Samochod(const std::string &marka, const std::string &model, unsigned int rocznik,
			 double przebieg)
		: marka(marka), model(model), rocznik(rocznik), przebieg(przebieg) {
		ileObiektow++;
	}

	Samochod(const std::string path) {
		std::ifstream file(path);
		if (!file.is_open()) {
			throw std::string("Nie można otworzyć pliku");
		}
		file >> marka >> model >> rocznik >> przebieg;
		file.close();
		ileObiektow++;
	}

	~Samochod() { ileObiektow--; }

	void setMarka(const std::string &marka) { this->marka = marka; }
	std::string getMarka() const { return marka; }

	void setModel(const std::string &model) { this->model = model; }
	std::string getModel() const { return model; }

	void setRocznik(unsigned int rocznik) { this->rocznik = rocznik; }
	unsigned int getRocznik() const { return rocznik; }

	void setPrzebieg(double przebieg) { this->przebieg = przebieg; }
	double getPrzebieg() const { return przebieg; }

	int getIleObiektow() const { return ileObiektow; }

	void wypisz() {
		std::cout << "/-- Informacje o samochodzie: ---" << std::endl;
		std::cout << "| Marka: " << marka << std::endl;
		std::cout << "| Model: " << model << std::endl;
		std::cout << "| Rocznik: " << rocznik << std::endl;
		std::cout << "| Przebieg: " << przebieg << std::endl;
		std::cout << "\\--------------------------------" << std::endl;
	}
};

int Samochod::ileObiektow = 0;

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
		Samochod samochod1;
		samochod1.setMarka("Skoda");
		samochod1.setModel("Fabia");
		samochod1.setRocznik(2015);
		samochod1.setPrzebieg(150000);
		samochod1.wypisz();

		Samochod samochod2("Toyota", "Corolla", 2018, 50000);
		samochod2.wypisz();

		std::string path = getPath();
		createFileIfNotExists(path);
		Samochod samochod3(path);
		samochod3.wypisz();

	} catch (const std::string &e) {
		std::cerr << "Error: " << e << std::endl;
	} catch (...) {
		std::cerr << "An unexpected error occurred." << std::endl;
	}

	return 0;
}
