#ifndef NODE_H
#define NODE_H
#include <vector>

struct node
{    
public:
    node();

    node(int x,int y);


    int getx();
    int gety();
    void setXNode(int x);
    void setYNode(int y);

    void setVisited();
    bool getVisited();

    void setStepz(int steps);
    int getStepz();






private:
    int _x = 0;
    int _y = 0;
    int _steps=0;
    bool _visited = false;

};

#endif // NODE_H
