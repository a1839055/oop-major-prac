#include <sstream>
#include <string>
#include <vector>

using namespace std;

string to_string_precision(const float input, const int precision = 2)
{
    ostringstream out;
    out.precision(precision);
    out << fixed << input;
    return out.str();
}