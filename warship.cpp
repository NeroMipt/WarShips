#include "warship.h"

Warship::Warship( const int s )
{
    size = s;
    hp   = s;
}

Healthstate Warship::attacked()
{
    if(hp > 1){
        hp--;
        return Healthstate::Wounded;
    }
    else{
        hp--;
        return Healthstate::Dead;
    }
}

Healthstate Warship::getState()
{
    if(hp == size) return Healthstate::Healthy;
    if(hp == 0) return Healthstate::Dead;
    else return Healthstate::Wounded;
}
