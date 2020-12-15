#include "node.h"

node::node()
{
}

node::node(int x, int y){
    _x = x;
    _y = y;
}
int node::getx(){
    return _x;
}
int node::gety(){
    return _y;
}

void node::setXNode(int x){
    _x = x;

}
void node::setYNode(int y){
    _y = y;
}

void node::setVisited()
{
    _visited=true;
}
bool node::getVisited()
{
    return _visited;
}

void node::setStepz(int steps)
{
    _steps = steps;
}

int node::getStepz()
{
    return _steps;
}















