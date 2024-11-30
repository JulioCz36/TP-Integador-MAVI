#ifndef INFO_H
#define INFO_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Scena.h"
#include "Juego.h"
#include <SFML/Window/Event.hpp>
using namespace std;

class Info : public Scena {
	Font fuente;
	Text info, salir;
	Texture pt;
	Sprite ps;
	int seleccionado = 0;
	RenderWindow& ventana;
public:
	Info(RenderWindow& w);
	void actualizar(Juego& j) override;
	void dibujar(RenderWindow& w) override;
	void ProcesoEventos(Juego& j, Event& event)override;
};
#endif 
