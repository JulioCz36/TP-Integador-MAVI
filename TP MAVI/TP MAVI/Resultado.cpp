#include "Resultado.h"
#include "Menu.h"
#include <iostream>
using namespace std;
using namespace sf;

Resultado::Resultado(RenderWindow& w,bool gano, int enemigos, int inocentes)
	: canEnemigos(enemigos), canInocentes(inocentes), ventana(w) {

	pt.loadFromFile("assets/fondoPartida.png");
	ps.setTexture(pt);
	fuente.loadFromFile("assets/Starborn.ttf");

	texto.setFont(fuente);
	salir.setFont(fuente);

	int puntajeFinal = enemigos - (inocentes * 2);
	if (gano) {
		mensaje = "       Win!\n Puntaje Final: " + to_string(puntajeFinal);
	}
	else {
		mensaje = "       Game Over\n Puntaje Final: " + to_string(puntajeFinal);
	}
	texto.setString(mensaje);
}

void Resultado::actualizar(Juego& j) {

	texto.setCharacterSize(50);
	texto.setFillColor(Color::White);
	texto.setPosition(150, 200);

	salir.setString("Salir (ESC)");
	salir.setCharacterSize(30);
	salir.setFillColor(Color::White);
	salir.setPosition(0, 0);
};
void Resultado::dibujar(RenderWindow& w) {
	w.draw(ps);
	w.draw(texto);
	w.draw(salir);
}
void Resultado::ProcesoEventos(Juego& j, Event& event) {
	if (event.type == Event::KeyPressed and event.key.code == Keyboard::Escape) {
		j.CambiarScena(new Menu(ventana));

	}
};