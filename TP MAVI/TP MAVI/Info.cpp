#include "Info.h"
#include "Menu.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include "Rectangulo.h"
#include "Info.h"
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "Juego.h"
using namespace std;
using namespace sf;


Info::Info(RenderWindow& w):ventana(w) {
	pt.loadFromFile("assets/fondoPartida.png");
	ps.setTexture(pt);

	fuente.loadFromFile("assets/Starborn.ttf");

	info.setFont(fuente);
	salir.setFont(fuente);

}


void Info::actualizar(Juego& j) {
	string textoInstrucciones =
		"Intrucciones:\n"
		"- Se apunta y dispara con el \n puntero del raton\n"
		"- Cada disparo acertado a un \n enemigo suma 1 punto\n"
		"- Cada disparo acertado a un \n inocente resta una vida y 1 punto\n"
		"- Si el enemigo dispara resta una \n vida\n"
		"- Se gana matando 10 enemigos\n"
		"- Se pierde si gastamos 3 vidas\n";

	info.setString(textoInstrucciones);
	info.setCharacterSize(30);
	info.setFillColor(Color::White);
	info.setPosition(35, 100);

	salir.setString("Salir (ESC)");
	salir.setCharacterSize(30);
	salir.setFillColor(Color::White);
	salir.setPosition(0, 0);
}


void Info::dibujar(RenderWindow& w) {
	w.draw(ps);


	w.draw(info);
	w.draw(salir);

}

void Info::ProcesoEventos(Juego& j, Event& event) {
	if (event.type == Event::KeyPressed and event.key.code == Keyboard::Escape) {
		j.CambiarScena(new Menu(ventana));

	}
}
