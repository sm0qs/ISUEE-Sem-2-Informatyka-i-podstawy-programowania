#include <iostream>

class Samochod {
  private:
	std::string marka, model;
	unsigned int rocznik;
	unsigned long przebieg;

  public:
	std::string getMarka() { return marka; }
	std::string getModel() { return model; }
	unsigned int getRocznik() { return rocznik; }
	unsigned long getPrzebieg() { return przebieg; }

	void setMarka(std::string marka) { this->marka = marka; }
	void setModel(std::string model) { this->model = model; }
	void setRocznik(unsigned int rocznik) { this->rocznik = rocznik; }
	void setPrzebieg(unsigned long przebieg) { this->przebieg = przebieg; }

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
