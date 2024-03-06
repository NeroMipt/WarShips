#ifndef WARSHIP_H
#define WARSHIP_H


enum class Healthstate {Healthy, Dead, Wounded};

class Warship
{
private:
    int size;
    int   hp;
public:
    Warship( const int s);
    Healthstate getState();
    Healthstate attacked();
};

#endif // WARSHIP_H
