#include <iostream>
#include "include/InterfacesYControladores/dummy.hh"

int main()
{
    Dummy* aux = new Dummy();
    cout << aux->getNombre() << endl;
    return 0;
}