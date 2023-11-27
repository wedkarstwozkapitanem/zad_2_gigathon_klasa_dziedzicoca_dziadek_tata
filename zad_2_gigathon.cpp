#include <iostream>
#include <locale.h>

using std::cout;
using std::string;

class Dziadek {
public:
    struct {
        int wiek{ 0 };
        string imie{ "" }, nazwisko{ "Kapitan" };
    } dane_osobowe;

    Dziadek() {};

    Dziadek(std::string imie, int wiek) {
        this->dane_osobowe.imie = imie;
        this->dane_osobowe.wiek = wiek;
    }
    void powitanie() {
        cout << "Witaj! Nazywam się " << this->dane_osobowe.imie << " " << this->dane_osobowe.nazwisko << ". Mam " << dane_osobowe.wiek << " lat.";
    }

    void zainteresowania() {
        cout << "Interesuję się: ";
        for (auto i : zainteresowania_jakie) cout << i << " ";
        cout << ".";
    }
private:
    string zainteresowania_jakie[2] = { "wędkarstwem","ogrodnictwem" };
   
};

class Tata : public Dziadek {
public:
    Tata(string imie, int wiek) : Dziadek(imie, wiek) {};
    void zainteresowania() {
        cout << "Interesuję się: ";
        for (auto i : zainteresowania_jakie) cout << i << " ";
    }
private:
    string zainteresowania_jakie[2] = { "karate","blogowaniem" };
};

int main() {
    setlocale(LC_CTYPE, "Polish");
    Dziadek rodzina_kapitana_dziadek("Eugeniusz", 74);
    rodzina_kapitana_dziadek.powitanie();
    rodzina_kapitana_dziadek.zainteresowania();
    cout << std::endl;
    Tata rodzina_kapitana_tata("Mirosław", 55);
    rodzina_kapitana_tata.powitanie();
    rodzina_kapitana_tata.zainteresowania();

    return 0;
}
