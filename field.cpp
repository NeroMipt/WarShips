#include "field.h"
#include <QtWidgets>

Field::Field()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
           fd[i][j] = 0;
        }
    }
}

void Field::addShip(int x, int y, Direction dir, Ship sp)
{
    switch (sp)
    {
    case Ship::battleship :
    {
        Warship tbattle(3, sp);
        army.append(tbattle);
        if(dir == Direction::STRAIGHT)
        {
            if(fd[x][y] + fd[x][y + 1] + fd[x][y + 2] == 0)
            {
                fd[x][y] = 1;
                fd[x][y+1] = 1;
                fd[x][y+2] = 1;
            }else {
                //ERROR MESSAGE
            }
        }else{
            if(fd[x][y] + fd[x + 1][y] + fd[x + 2][y] == 0)
            {
                fd[x][y] = 1;
                fd[x + 1][y] = 1;
                fd[x + 2][y] = 1;
            }else {
                //ERROR MESSAGE
            }
        }
        break;
    }
    case Ship::boat :
    {
        Warship tboat(1, sp);
        army.append(tboat);
            if(fd[x][y] == 0)
                fd[x][y] = 1;
            else{
                //ERROR MESSAGE
            }
            break;
    }
    case Ship::cruiser :
    {
        Warship tcruiser(2, sp);
        army.append(tcruiser);
        if(dir == Direction::STRAIGHT)
        {
            if(fd[x][y] + fd[x][y + 1] + fd[x][y + 2] + fd[x][y + 3] == 0)
            {
                fd[x][y] = 1;
                fd[x][y+1] = 1;
                fd[x][y+2] = 1;
                fd[x][y+3] = 1;
            }else {
                //ERROR MESSAGE
            }
        }else{
            if(fd[x][y] + fd[x + 1][y] + fd[x + 2][y] + fd[x + 3][y] == 0)
            {
                fd[x][y] = 1;
                fd[x + 1][y] = 1;
                fd[x + 2][y] = 1;
                fd[x + 3][y] = 1;
            }else {
                //ERROR MESSAGE
            }
        }
        break;
    }
    case Ship::destroyer :
    {
        Warship tdestroyer(4, sp);
        army.append(tdestroyer);
        if(dir == Direction::STRAIGHT)
        {
            if(fd[x][y] + fd[x][y + 1] == 0)
            {
                fd[x][y] = 1;
                fd[x][y + 1] = 1;
            }else{
                //ERROR MESSGAE
            }
        }else{
            if(fd[x][y] + fd[x + 1][y] == 0)
            {
                fd[x][y] = 1;
                fd[x + 1][y] = 1;
            }else{
                //ERROR MESSGAE
            }
        }
        break;
    }
    }

}

void Field::attacked(int x, int y){
    if(fd[x][y] == 1)
    {

    }
}
