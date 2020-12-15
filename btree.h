#ifndef BTREE_H
#define BTREE_H

#include <node.h>


class btree
{
public:
    btree();

    static int MinimumSteps(int BoardHeight, int BoardWidth, int KnightStartXPosition,
                            int KnightStartYPosition, int KnightEndXPostion, int KnightEndYPosition);


    static bool checkBoard(int BoardHeight, int BoardWidth, int KnightStartXPosition,
                    int KnightStartYPosition, int KnightEndXPostion, int KnightEndYPosition);


    static int BFS(int BoardHeight, int BoardWidth, node current, node target);

    static std::vector<node> catchChildren(int BoardHeight, int BoardWidth, node n, int KnightEndXPosition, int KnightEndYPosition);


private:

};

#endif // BTREE_H
