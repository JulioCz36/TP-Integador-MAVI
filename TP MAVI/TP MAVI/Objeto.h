#ifndef OBJETO_H
#define OBJETO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Rect.hpp>
using namespace sf;

class Objeto {
public:
	Objeto();
	virtual  void dibujar(RenderWindow& w) = 0;
	virtual FloatRect verGlobalBounds() = 0;
	virtual void Actulizar(Color col) = 0;
private:
};
#endif