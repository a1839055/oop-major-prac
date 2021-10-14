#include <string>

#include "fries.h"

using namespace std;

Fries::Fries() {
    name = "";
    prices = new float[3];
    prices_count = 3;
    size = 0;
}

Fries::Fries(float p[3]) {
    name = "Fries";
    prices = p;
    prices_count = 3;
    size = 0;
}

Fries::Fries(string n, float* p, int pc) {
    name = n;
    prices = p;
    prices_count = 2;
    size = 0;
}

Fries::~Fries() {

}

string Fries::get_display() {
    return "";
}