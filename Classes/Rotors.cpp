#include <iostream>
#include "Rotor.cpp";

#include "Enums/Enums.cpp"

using namespace std;

class Rotors
{
private:
	Rotor **rotors = nullptr;
	int totalRotors = 0;

private:
	void rotate()
	{
		if (totalRotors > 0)
		{
			rotors[0]->step();
		}
	}

public:
	~Rotors()
	{
		cout << "Deleteing Rotors" << endl;
		delete[] rotors;
	}
	Rotors()
	{
	}
	Rotors(int totalRotors, int totalChars, const char *characters, const char **mappings) : totalRotors(totalRotors)
	{
		cout << "Starting Rotors!!!" << endl;
		rotors = new Rotor *[totalRotors];
		for (int i = 0; i < totalRotors; i++)
		{
			cout << "Starting Rotor " << i << endl;
			rotors[i] = new Rotor(characters, mappings[i], totalChars);
			cout << "Rotor " << i << "Started Successfully" << endl;
		}
		for (int i = 0; i < totalRotors - 1; i++)
		{
			rotors[i]->set_next(rotors[i + 1]);
		}
		// rotors[0]->set_init(1);
	}
	char cipher(char c, DIRECTION d)
	{
		if (d == FORWARD)
		{
			for (int i = 0; i < totalRotors; i++)
			{
				this->rotate();
				c = rotors[i]->cipher(c);
			}
		}
		else if (d == BACKWARD)
		{
			for (int i = totalRotors - 1; i >= 0; i--)
			{
				c = rotors[i]->cipher(c);
			}
		}
		return c;
	}
};