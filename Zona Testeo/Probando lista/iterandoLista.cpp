#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> dummy;
    dummy.push_back(3);
    dummy.push_back(2);
    dummy.push_back(1);
    dummy.push_back(0);

    for(list<int>::iterator it = dummy.begin(); it != dummy.end(); ++it) {
        cout << *it << "\n";
    }

    return 1;

}