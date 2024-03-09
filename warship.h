#ifndef WARSHIP_H
#define WARSHIP_H


enum class Healthstate {Healthy, Dead, Wounded};
enum Ship {boat, destroyer, battleship, cruiser};

class Warship
{
private:
    int  size;
    int    hp;
    Ship type;

public:
    Warship(const int s, const Ship sp);
    Healthstate getState();
    Healthstate attacked();
};

#endif // WARSHIP_H
