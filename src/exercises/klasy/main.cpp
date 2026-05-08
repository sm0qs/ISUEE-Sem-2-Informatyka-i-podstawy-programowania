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

int main() {
	Samochod samochod1;
	samochod1.setMarka("Skoda");
	samochod1.setModel("Fabia");
	samochod1.setRocznik(2015);
	samochod1.setPrzebieg(150000);
	samochod1.wypisz();

	Samochod samochod2("Toyota", "Corolla", 2018, 50000);
	samochod2.wypisz();

	return 0;
}
