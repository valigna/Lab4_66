#ifndef DUMMY
#define DUMMY

#include <string>
using namespace std;

class Dummy
{
private:
    string nombre;
public:
    Dummy();
    ~Dummy();
    string getNombre();
};

#endif