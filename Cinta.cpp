#include "Cinta.h"

Cinta::Cinta() : nivel(1) {
}

Cinta::Cinta(int nivel) : nivel(nivel) {
}

int Cinta::getNivel() const {
	return nivel;
}

string Cinta::getColorCinta() const {
	string color;

	switch (nivel) {
	case 1: {
		color = "Blanco";
	}
		  break;

	case 2: {
		color = "Amarillo";
	}
		  break;

	case 3: {
		color = "Naranja";
	}
		  break;

	case 4: {
		color = "Verde";
	}
		  break;

	case 5: {
		color = "Azul";
	}
		  break;

	case 6: {
		color = "Marrón";
	}
		  break;

	case 7: {
		color = "Negro";
	}
		  break;

	default: {
		color = "NO VALIDO";
	}
		   break;
	}
	return color;
}

float Cinta::getPorcentaje() const {
	float porcentaje = 0.0;
	switch (nivel) {
	case 1: {
		porcentaje = 0.4;
	}
		  break;

	case 2: {
		porcentaje = 0.5;
	}
		  break;

	case 3: {
		porcentaje = 0.6;
	}
		  break;

	case 4: {
		porcentaje = 0.7;
	}
		  break;

	case 5: {
		porcentaje = 0.8;
	}
		  break;

	case 6: {
		porcentaje = 0.9;
	}
		  break;

	case 7: {
		porcentaje = 1.0;
	}
		  break;

	default: {
		porcentaje = 0.0;
	}
		   break;
	}
	return porcentaje;
}
