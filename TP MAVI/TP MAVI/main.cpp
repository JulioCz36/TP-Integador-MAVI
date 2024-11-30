#include <SFML/Graphics.hpp>
#include <cmath>
#include "Menu.h"
#include <SFML/Window/Keyboard.hpp>
#include "Juego.h"
using namespace std;
using namespace sf;

int main() {
	RenderWindow ventana(VideoMode(800, 600), "TP MAVI");
	Juego j(new Menu(ventana));
	j.jugar();

	return 0;
}
