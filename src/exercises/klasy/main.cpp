#include <iostream>

class Samochod {
  private:
	std::string marka;
	std::string model;
	unsigned int rocznik;
	double przebieg;

  public:
	void setMarka(const std::string &marka) { this->marka = marka; }
	std::string getMarka() const { return marka; }

	void setModel(const std::string &model) { this->model = model; }
	std::string getModel() const { return model; }

	void setRocznik(unsigned int rocznik) { this->rocznik = rocznik; }
	unsigned int getRocznik() const { return rocznik; }

	void setPrzebieg(double przebieg) { this->przebieg = przebieg; }
	double getPrzebieg() const { return przebieg; }

	void wypisz() {
		std::cout << "Marka: " << marka << std::endl;
		std::cout << "Model: " << model << std::endl;
		std::cout << "Rocznik: " << rocznik << std::endl;
		std::cout << "Przebieg: " << przebieg << std::endl;
	}
};

int main() {
	Samochod s;

	s.setMarka("Skoda");
	s.setModel("Fabia");
	s.setRocznik(2015);
	s.setPrzebieg(150000);

	s.wypisz();
}
