#include <iostream>
#include <string>

#include "Reflector.cpp";
#include "Rotors.cpp";

#include "Enums/Enums.cpp"

using namespace std;

class Machine
{
private:
	Rotors *rotors;
	Reflector *r;
	char **plugboard = nullptr;
	MODE mode = MODE::ENCRYPT;

public:
	Machine(int totalRotors, int totalChars, const char *original_chars, const char **mappings, const char *m_reflector)
	{
		rotors = new Rotors(totalRotors, totalChars, original_chars, mappings);
		r = new Reflector(original_chars, m_reflector, totalChars);
		cout << "Starting a new Machine" << endl
			 << "Mode: Encryption" << endl;
	}
	~Machine()
	{
		cout << "Deleteing Machine" << endl;
		delete rotors;
		delete r;
	}
	void set_plugboard(string plug)
	{
		// plug = "AB CD EF"
		int totalPairs = 0;
		for (int i = 0; i < plug.length(); i++)
		{
			if (plug[i] == ' ')
				totalPairs++;
		}
		totalPairs++;
		plugboard = new char *[totalPairs];
		for (int i = 0; i < totalPairs; i++)
		{
			plugboard[i] = new char[2];
		}
		int j = 0;
		for (int i = 0; i < plug.length(); i++)
		{
			if (plug[i] != ' ')
			{
				plugboard[j / 2][j % 2] = plug[i];
				j++;
			}
		}
		}
	Machine(int totalRotors, int totalChars, const char *original_chars, const char **mappings, const char *m_reflector, MODE mode) : mode(mode)
	{
		rotors = new Rotors(totalRotors, totalChars, original_chars, mappings);
		r = new Reflector(original_chars, m_reflector, totalChars);

		if (mode == MODE::ENCRYPT)
		{
			cout << "Starting a new Machine" << endl
				 << "Mode: Encryption" << endl;
		}
		else
		{
			cout << "Starting a new Machine" << endl
				 << "Mode: Decryption" << endl;
		}
	}
	void toggleMode()
	{
		if (mode == MODE::DECRYPT)
			mode = MODE::ENCRYPT;
		else
			mode = MODE::DECRYPT;
		cout << "Now working in " << (mode == 1 ? "Encrypyion" : "Decryption") << " Mode" << endl;
	}
	string process(string s)
	{
		char temp;
		for (int i = 0; i < s.length(); i++)
		{
			temp = s[i];
			temp = rotors->cipher(temp, DIRECTION::FORWARD);
			cout << temp << endl;
			temp = r->reflect(temp);
			cout << temp << endl;
			temp = rotors->cipher(temp, DIRECTION::BACKWARD);
			s[i] = temp;
		}
		return s;
	}
};