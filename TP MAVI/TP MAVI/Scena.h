#ifndef SCENA_H
#define SCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include <SFML/Window/Event.hpp>
using namespace sf;
class Juego;


class Scena {
public:
	Scena();
	void virtual ProcesoEventos(Juego& j, Event& event) {}
	void virtual actualizar(Juego& j) = 0;
	void virtual dibujar(RenderWindow& w) = 0;
private:
};

#endif

