#include "Menu.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include "Scena.h"
#include "Rectangulo.h"
#include "Info.h"
#include "Partida.h"
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "Juego.h"
using namespace std;
using namespace sf;


Menu::Menu(RenderWindow& w) : ventana(w){
	pt.loadFromFile("assets/fondoPartida.png");
	ps.setTexture(pt);
	CuadroS = new Rectangulo(Vector2f(290.0f, 100.0f), 3, 0, Color::White);
	CuadroT = new Rectangulo(Vector2f(290.0f, 250.0f), 3, 0, Color::White);
	CuadroSalir = new Rectangulo(Vector2f(290.0f, 400.0f), 3, 0, Color::White);

	CuadroSe = new Rectangulo(Vector2f(290.0f, 100.0f), 3, 0, Color::Blue);
	select.setString("Jugar");
	select.setCharacterSize(30);
	select.setFillColor(Color::White);
	select.setPosition(350, 120);

	fuente.loadFromFile("assets/Starborn.ttf");

	start.setFont(fuente);
	info.setFont(fuente);
	select.setFont(fuente);
	salir.setFont(fuente);

}
Menu::~Menu() {
	delete CuadroS, CuadroT, CuadroSe, CuadroSalir;
}


void Menu::actualizar(Juego& j) {
	start.setString("Jugar");
	start.setCharacterSize(30);
	start.setFillColor(Color::Blue);
	start.setPosition(350, 120);

	info.setString("Info");
	info.setCharacterSize(30);
	info.setFillColor(Color::Blue);
	info.setPosition(350, 270);

	salir.setString("Salir");
	salir.setCharacterSize(30);
	salir.setFillColor(Color::Blue);
	salir.setPosition(350, 420);
}


void Menu::dibujar(RenderWindow& w) {
	w.draw(ps);

	CuadroS->dibujar(w);
	CuadroT->dibujar(w);
	CuadroSalir->dibujar(w);

	w.draw(start);
	w.draw(info);
	w.draw(salir);

	CuadroSe->dibujar(w);
	w.draw(select);
}

void Menu::ProcesoEventos(Juego& j, Event& event) {
	if (event.type == Event::KeyPressed and event.key.code == Keyboard::Escape) {
		j.Salir();

	}

	if (event.type == Event::KeyPressed and event.key.code == Keyboard::Up) {
		if (seleccionado == 1) {
			seleccionado = 0;
			CuadroSe = new Rectangulo(Vector2f(290.0f, 100.0f), 3, 0, Color::Blue);
			select.setString("Jugar");
			select.setCharacterSize(30);
			select.setFillColor(Color::White);
			select.setPosition(350, 120);
		}
		else if (seleccionado == 2) {
			seleccionado = 1;

			CuadroSe = new Rectangulo(Vector2f(290.0f, 250.0f), 3, 0, Color::Blue);
			select.setString("Info");
			select.setCharacterSize(30);
			select.setFillColor(Color::White);
			select.setPosition(350, 270);
		}
	}

	if (event.type == Event::KeyPressed and event.key.code == Keyboard::Down) {
		if (seleccionado == 0) {
			seleccionado = 1;
			CuadroSe = new Rectangulo(Vector2f(290.0f, 250.0f), 3, 0, Color::Blue);
			select.setString("Info");
			select.setCharacterSize(30);
			select.setFillColor(Color::White);
			select.setPosition(350, 270);
		}
		else if (seleccionado == 1) {
			seleccionado = 2;
			CuadroSe = new Rectangulo(Vector2f(290.0f, 400.0f), 3, 0, Color::Blue);
			select.setString("Salir");
			select.setCharacterSize(30);
			select.setFillColor(Color::White);
			select.setPosition(350, 420);
		}
	}

	if (event.type == Event::KeyPressed and event.key.code == Keyboard::Return) {
		if (seleccionado == 0) {
			j.CambiarScena(new Partida(ventana));
		}
		else if (seleccionado == 1) {
			j.CambiarScena(new Info(ventana));
		}
		else if (seleccionado == 2) {
			j.Salir();
		}
	}
}
