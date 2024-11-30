#ifndef PARTIDA_H
#define PARTIDA_H

#include <vector>
#include "Scena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include "Jugador.h"
#include "Personaje.h"

using namespace std;
using namespace sf;


class Partida : public Scena {
	Jugador jugador;
	Personaje* personaje;
	Texture pt;
	Sprite ps;
	Font fuente;
	Text textoPuntos, textoVidas, textoEnemigos;

	int puntos, enemigosMatados, inocentesMatados;

	Clock relojGeneracion;

	RenderWindow& ventana;
public:
	Partida(RenderWindow& w);

	void actualizar(Juego& j) override;
	void dibujar(RenderWindow& w) override;
	void virtual ProcesoEventos(Juego& j, Event& event) override;

	void comprobarColisiones();
	void generarPersonaje();
	~Partida();

};

#endif 