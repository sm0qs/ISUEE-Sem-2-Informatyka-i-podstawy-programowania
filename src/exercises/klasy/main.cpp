#include <iostream>

class Samochod {
  private:
	std::string marka;
	std::string model;
	unsigned int rocznik;
	double przebieg;

  public:
	Samochod() : marka("nieznana"), model("nieznany"), rocznik(0), przebieg(0.0) {}

	Samochod(const std::string &marka, const std::string &model, unsigned int rocznik,
			 double przebieg)
		: marka(marka), model(model), rocznik(rocznik), przebieg(przebieg) {}

	void setMarka(const std::string &marka) { this->marka = marka; }
	std::string getMarka() const { return marka; }

	void setModel(const std::string &model) { this->model = model; }
	std::string getModel() const { return model; }

	void setRocznik(unsigned int rocznik) { this->rocznik = rocznik; }
	unsigned int getRocznik() const { return rocznik; }

	void setPrzebieg(double przebieg) { this->przebieg = przebieg; }
	double getPrzebieg() const { return przebieg; }

	void wypisz() {
		std::cout << "/-- Informacje o samochodzie: ---" << std::endl;
		std::cout << "| Marka: " << marka << std::endl;
		std::cout << "| Model: " << model << std::endl;
		std::cout << "| Rocznik: " << rocznik << std::endl;
		std::cout << "| Przebieg: " << przebieg << std::endl;
		std::cout << "\\--------------------------------" << std::endl;
	}
};

int main() {
	Samochod s;

	s.setMarka("Skoda");
	s.setModel("Fabia");
	s.setRocznik(2015);
	s.setPrzebieg(150000);

	s.wypisz();

	Samochod s2("Toyota", "Corolla", 2018, 50000);
	s2.wypisz();

	return 0;
}
