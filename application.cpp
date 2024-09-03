#include <stdio.h>
#include <Machine.cpp>

#include "Enums/Enums.cpp"

using namespace std;

int main()
{
    const char *original = "./Ciphers/original.txt";
    const char *mapping[] = {"./Ciphers/one.txt", "./Ciphers/two.txt", "./Ciphers/three.txt"};
    const char *m_reflector = "./Ciphers/reflector_mapping.txt";

    Machine machine(3, 26, original, mapping, m_reflector);
    // machine.set_plugboard("AB CD EF");
    string h = "A";
    cout << machine.process(h) << endl
         << endl;
}
