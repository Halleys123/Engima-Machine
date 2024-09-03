#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Reflector {
private:
    char* original = nullptr;
    char* mapping = nullptr;
    int totalChars = 0;
private:
    int find(char c) {
        int ret = -1;
        for (int i = 0; i < totalChars; i++) {
            if (original[i] == c) {
                ret = i;
                break;
            }
        }
        return ret;
    }
public:
    Reflector() {

    }
    Reflector(const char* characters, const char* mappings, int size) : original(new char[size]), mapping(new char[size]), totalChars(size)
    {
        cout << "Setting up Reflector" << endl;
        string s1;
        string s2;

        ifstream init(characters);
        ifstream maps(mappings);

        getline(init, s1);
        getline(maps, s2);

        int i = 0;
        for (int i = 0; i < totalChars; i++) {
            original[i] = s1[i];
            mapping[i] = s2[i];
        }
    }
    char reflect(char c) {
        int finding = find(c);
        if (finding == -1) {
            throw 404;
        }
        return mapping[finding];
    }
};