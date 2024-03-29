#include "field.h"


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
        if(dir == Direction::STRAIGHT)
        {
            if(fd[x][y] + fd[x][y + 1] + fd[x][y + 2] + fd[x][y-1] + fd[x][y+3] + fd[x-1][y-1] + fd[x+1][y-1] + fd[x+1][y+3] + fd[x-1][y+3] +fd[x-1][y] +fd[x-1][y+1] + fd[x-1][y+2] + fd[x+1][y+1] + fd[x+1][y+2] + fd[x+1][y] == 0)
            {
                fd[x][y] = 1;
                fd[x][y+1] = 1;
                fd[x][y+2] = 1;
            }else {
                //ERROR MESSAGE
            }
        }else{
            if(fd[x][y] + fd[x + 1][y] + fd[x + 2][y] + fd[x - 1][y] + fd[x+3][y] + fd[x-1][y-1] + fd[x-1][y+1] + fd[x+3][y+1] + fd[x+3][y-1] +fd[x][y - 1] +fd[x+1][y-1] + fd[x+2][y-1] + fd[x+1][y+1] + fd[x+2][y+1] + fd[x][y+1] == 0)
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

            if(fd[x][y] + fd[x-1][y] + fd[x+1][y] + fd[x+1][y+1] + fd[x+1][y-1] + fd[x][y-1] + fd[x][y+1] + fd[x-1][y+1] + fd[x-1][y-1] == 0)
                fd[x][y] = 1;
            else{
                //ERROR MESSAGE
            }
            break;
    }
    case Ship::cruiser :
    {
        if(dir == Direction::STRAIGHT)
        {
            if(fd[x][y] + fd[x][y + 1] + fd[x][y + 2] + fd[x][y + 3] + fd[x][y-1] + fd[x-1][y-1] + fd[x-1][y] + fd[x-1][y+1] + fd[x-1][y+2] + fd[x-1][y+3] + fd[x-1][y+4] + fd[x][y+4] + fd[x+1][y+4] + fd[x+1][y+3] + fd[x+1][y+2] + fd[x+1][y+1] + fd[x+1][y] + fd[x+1][y-1] == 0)
            {
                fd[x][y] = 1;
                fd[x][y+1] = 1;
                fd[x][y+2] = 1;
                fd[x][y+3] = 1;
            }else {
                //ERROR MESSAGE
            }
        }else{
            if(fd[x][y] + fd[x + 1][y] + fd[x + 2][y] + fd[x + 3][y] + fd[x-1][y] + fd[x-1][y+1] + fd[x][y+1] + fd[x+1][y+1] + fd[x+2][y+1] + fd[x + 3][y+1] + fd[x + 4][y+1] + fd[x+4][y] + fd[x+4][y-1] + fd[x+3][y-1] + fd[x+2][y-1] + fd[x+1][y-1] + fd[x][y-1] + fd[x-1][y-1]== 0)
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
        if(dir == Direction::STRAIGHT)
        {
            if(fd[x][y] + fd[x][y + 1] + fd[x][y-1] + fd[x-1][y-1] + fd[x-1][y] + fd[x-1][y+1] + fd[x-1][y+2] + fd[x][y+2] + fd[x+1][y+2] + fd[x+1][y+1] + fd[x+1][y] + fd[x+1][y-1] == 0)
            {
                fd[x][y] = 1;
                fd[x][y + 1] = 1;
            }else{
                //ERROR MESSGAE
            }
        }else{
            if(fd[x][y] + fd[x + 1][y] + fd[x-1][y] + fd[x-1][y+1] + fd[x][y+1] + fd[x+1][y+1] + fd[x + 2][y+1] + fd[x + 2][y] + fd[x+2][y-1] + fd[x+1][y-1] + fd[x][y-1]+fd[x-1][y-1] == 0)
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

int Field::sumOfField()
{
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
           sum += fd[i][j];
        }
    }
    return sum;
}

void Field::attacked(int x, int y){

    if(fd[x][y] == 1)
    {
        if(sumOfField() == 1)
        {
            //YOU DIED
        }
        totalHp--;
    }
}
