#include "Juego.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Rect.hpp>
using namespace std;
using namespace sf;

Juego::Juego(Scena* e) :w(VideoMode(800, 600), "TP MAVI"), actual(e) {
	w.setFramerateLimit(60);
}
Juego::~Juego() {
	delete actual;
};
void Juego::jugar() {

	while (w.isOpen()) {
		ProcesoEventos();
		w.clear();

		Actualizar();

		Dibujar();


		w.display();

		if (prox) {
			delete actual;
			actual = prox;
			prox = nullptr;
		}

	}
}

void Juego::Actualizar() {
	actual->actualizar(*this);
}
void Juego::Dibujar() {
	actual->dibujar(w);
}

void Juego::ProcesoEventos() {
	sf::Event e;
	while (w.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			w.close();
		}
		else {
			actual->ProcesoEventos(*this, e);
		}
	}
}

void Juego::CambiarScena(Scena* scena_nueva) {
	prox = scena_nueva;
}
void Juego::Salir() {
	w.close();
}