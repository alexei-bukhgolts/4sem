#include <SFML/Graphics.hpp>
#include <vector>
#include "vec2.h"
#include <cmath>

#define CHARGE_SIZE 20.
#define DL 3
#define SIZE_X 2560
#define SIZE_Y 1440
#define LINES_PER_CHARGE 36
#define N_CHARGES 20

using namespace std;


struct Charge {
    float x;
    float y;
    float q;
};

void putCharge(Charge charge);

vector<Charge> charges(0);
sf::RenderWindow window(sf::VideoMode(SIZE_X, SIZE_Y), "Lines of force!");

float rand_FloatRange(float a, float b) {
    return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

void drawCircle(float x, float y, sf::Color color) {
    sf::CircleShape shape(CHARGE_SIZE);
    shape.setPosition(x - CHARGE_SIZE , y - CHARGE_SIZE );
    shape.setFillColor(color);
    window.draw(shape);
}

bool shouldEndLineOfForce(float x, float y, bool positiveLine) {
    if (x < -.2 * SIZE_X || x > 1.2 * SIZE_X || y < -.2 * SIZE_Y || y > 1.2 * SIZE_Y)
        return true;
    for (auto charge: charges) {
        if ((positiveLine != (charge.q > 0)) && vec2(x - charge.x, y - charge.y).len() < CHARGE_SIZE)
            return true;
    }
    return false;
}

void drawLineOfForce(float x, float y, bool positiveLine) {
    sf::VertexArray arr(sf::LineStrip);
    while (!shouldEndLineOfForce(x, y, positiveLine)) {
        arr.append(sf::Vertex(sf::Vector2f(x, y)));
        vec2 E(0, 0);
        for(auto charge: charges) {
            auto r = vec2(x - charge.x, y - charge.y);
            E += charge.q * r / (r.len() * r.len() * r.len());
        }
        auto dr = (positiveLine ? 1 : -1) * E.getNormalized() * DL;
        x += (float)dr.x;
        y += (float)dr.y;
    }
    window.draw(arr);
}

void drawLines() {
    for (auto charge : charges) {
        drawCircle(charge.x, charge.y, charge.q > 0 ? sf::Color().Red : sf::Color().Blue);
        for (double angle = 0.001; angle < 2 * 3.14159265358979; angle += 2 * 3.14159265358979 / LINES_PER_CHARGE) {
            drawLineOfForce((float)(charge.x + CHARGE_SIZE * cos(angle)), (float)(charge.y + CHARGE_SIZE * sin(angle)), charge.q > 0);
        }
    }
}

void putCharge(Charge charge) {
    charges.push_back(charge);
}


int main() {
    srand(time(0));
    window.clear();
    for (int i = 0; i < N_CHARGES; ++i) {
        Charge charge = {.x = rand_FloatRange(0, SIZE_X), rand_FloatRange(0, SIZE_Y), rand_FloatRange(-1, 1)};
        putCharge(charge);
    }
//    putCharge(charge2);

    drawLines();
    window.display();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::sleep(sf::milliseconds(10));
        drawLines();
        window.display();
        window.clear();

    }

    return 0;
    }

