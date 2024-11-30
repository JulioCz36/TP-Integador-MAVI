#ifndef JUEGO_H
#define JUEGO_H
#include "Scena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
using namespace sf;
class Scena;

class Juego{
public:
	Juego(Scena* e);
	void jugar();
	void Actualizar();
	void Dibujar();
	void CambiarScena(Scena* scena_nueva);
	void ProcesoEventos();
	void  Salir();
	~Juego();
private:
	RenderWindow w;
	Scena* actual, * prox = nullptr;
	Image icon;
};

#endif

