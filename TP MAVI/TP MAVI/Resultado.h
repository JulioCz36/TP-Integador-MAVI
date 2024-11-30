#ifndef RESULTADO_H
#define RESULTADO_H

#include "Scena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include "Jugador.h"
using namespace std;
using namespace sf;

class Resultado : public Scena {

	Texture pt;
	Sprite ps;
	Font fuente;
	Text texto, salir;
	string mensaje;
	int canEnemigos, canInocentes;

	RenderWindow& ventana;

public:
	Resultado(RenderWindow& w,bool gano, int enemigos, int inocentes);

	void actualizar(Juego& j) override;
	void dibujar(RenderWindow& w) override;
	void virtual ProcesoEventos(Juego& j, Event& event) override;
};

#endif 