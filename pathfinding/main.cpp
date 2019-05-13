#include <iostream>
#include <string>

#include "pathfinding.h"
#include "struct.h"

using namespace std;

int main()
{
    loc_t loc_start;
    loc_t loc_end;

    loc_start.x = 10;
    loc_start.y = 10;

    loc_end.x = 50;
    loc_end.y = 50;

    /*
    loc_t obs1;
    obs1.x = 16;
    obs1.y = 11;

    loc_t obs2;
    obs2.x = 15;
    obs2.y = 11;

    loc_t obs3;
    obs3.x = 14;
    obs3.y = 11;
    */

    Pathfinding path = Pathfinding(loc_start, loc_end, 1);


    string way =path.aStar();

    path.draw(way);
}