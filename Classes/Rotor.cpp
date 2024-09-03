#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Rotor
{
private:
    char *original = nullptr;
    char *mapping = nullptr;
    int totalChars = 0;
    int rotation = 0;
    Rotor *next = nullptr;
    Rotor *prev = nullptr;

private:
    int find(char c)
    {
        int ret = -1;
        for (int i = 0; i < totalChars; i++)
        {
            if (original[i] == c)
            {
                ret = i;
                break;
            }
        }
        return ret;
    }

public:
    ~Rotor()
    {
        cout << "Destroying Rotor Gear" << endl;
        delete[] original;
        delete[] mapping;
        delete next;
    }
    Rotor()
    {
        cout << "Started Empty Rotor" << endl;
    }
    void set_init(int i)
    {
        rotation = i;
    }
    Rotor(const char *characters, const char *mappings, int size) : original(new char[size]), mapping(new char[size]), totalChars(size)
    {
        string s1;
        string s2;
        try
        {
            ifstream init(characters);
            ifstream maps(mappings);

            getline(init, s1);
            getline(maps, s2);

            int i = 0;
            for (int i = 0; i < totalChars; i++)
            {
                original[i] = s1[i];
                mapping[i] = s2[i];
            }
        }
        catch (...)
        {
            throw 404;
        }
    }
    void set_next(Rotor *next)
    {
        this->next = next;
    }
    void rotate()
    {
        rotation = (rotation + 1) % totalChars;
        char temp = mapping[totalChars - 1];
        // move every character forward
        for (int i = totalChars - 1; i > 0; i--)
        {
            mapping[i] = mapping[i - 1];
        }
        mapping[0] = temp;
    }
    void step()
    {
        rotate();
        if (rotation == 0 && next != nullptr)
        {
            next->step();
            cout << "Rotated Next" << endl;
        }
    }
    char cipher(char c)
    {
        for (int i = 0; i < totalChars; i++)
        {
            //cout << mapping[i] << endl;
        }
        int finding = find(c);
        if (finding == -1)
        {
            throw 404;
        }
        return mapping[finding];
    }
};