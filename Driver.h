#ifndef NYM_H
#define NYM_H

#include "node.h"
#include "btree.h"

int MinimumSteps(int BoardHeight, int BoardWidth, int KnightStartXPosition,
                     int KnightStartYPosition, int KnightEndXPostion, int KnightEndYPosition)
{

        node target = node(KnightEndXPostion, KnightEndYPosition);
        node current(KnightStartXPosition, KnightStartYPosition);

        return btree::BFS(BoardHeight, BoardWidth, current, target);

}

#endif // NYM_H
