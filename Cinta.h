#ifndef CINTA_H
#define CINTA_H

#include <iostream>
#include <string>
using namespace std;

class Cinta {
private:
	int nivel;

public:
	Cinta();
	Cinta(int);
	int getNivel() const;
	string getColorCinta() const;
	float getPorcentaje() const;
	Cinta& operator++();
	Cinta& operator--();
};

#endif
