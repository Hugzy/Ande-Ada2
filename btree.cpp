#include "btree.h"
#include <iostream>
#include <vector>
#include "node.h"
#include <queue>
#include <array>




using namespace std;

btree::btree()
{


}

int btree::MinimumSteps(int BoardHeight, int BoardWidth, int KnightStartXPosition, int KnightStartYPosition, int KnightEndXPostion, int KnightEndYPosition)
{

/*
    // x and y direction, where a knight can move
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    std::queue<node> q;
    q.push(node(KnightStartXPosition,KnightStartYPosition, BoardHeight, BoardWidth));


    node t;
    int x,y;

    bool visit[BoardHeight+1][BoardWidth+1];
    //std::vector<std::vector<bool>> visit[BoardHeight+1][BoardWidth+1];

    //make all spots unvisited
    for(int i=1; i<=BoardHeight;i++){
        for (int j=1; j<=BoardWidth;j++){
            visit[i][j] = false;
        }
    }

    visit[KnightStartXPosition][KnightStartYPosition] = true;

    //Loop until theres 1 element in queue.
    while (!q.empty())
    {
        t=q.front();
        q.pop();

        // if current node is equal to target node
        //return its distance
        if (t.x == KnightEndXPostion && t.y == KnightEndYPosition){
            return t.steps;
        }
    //Loop for all reachable states

        for(int i=0; i<= KnightEndXPostion && i<=KnightEndYPosition;i++){
            x=t.x + dx[i];
            y=t.y + dy[i];



            //if reachable stateis not yet visited and
            // inside board, push that state into queue
            if (checkBoard(BoardHeight, BoardWidth, KnightStartXPosition,
                                  KnightStartYPosition,  KnightEndXPostion, KnightEndYPosition) && !visit[x][y])){
                //visit[x][y] = true;
                q.push(node(x,y,t.steps+1));

            }
        }

    }
    return t.steps;
*/

    node target = node(KnightEndXPostion, KnightEndYPosition);
    node current(KnightStartXPosition, KnightStartYPosition);

    return BFS(BoardHeight, BoardWidth, current, target);



}


bool btree::checkBoard(int BoardHeight, int BoardWidth, int KnightStartXPosition,
                       int KnightStartYPosition, int KnightEndXPostion, int KnightEndYPosition){

    if (KnightStartXPosition >= 1 && KnightStartXPosition <= BoardHeight && KnightStartYPosition >= 1 && KnightStartYPosition <= BoardWidth
            && KnightEndXPostion >= 1 && KnightEndXPostion <= BoardHeight && KnightEndYPosition >=1 && KnightEndYPosition<=BoardWidth)
        return true;
    return false;
}

std::vector<node> btree::catchChildren(int BoardHeight, int BoardWidth, node n, int KnightEndXPosition, int KnightEndYPosition)
{
    node m1 = node(n.getx()+2, n.gety()+1);
    node m2 = node(n.getx()+2, n.gety()-1);
    node m3 = node(n.getx()-2, n.gety()+1);
    node m4 = node(n.getx()-2, n.gety()-1);

    node m5 = node(n.getx()+1, n.gety()+2);
    node m6 = node(n.getx()+1, n.gety()-2);
    node m7 = node(n.getx()-1, n.gety()+2);
    node m8 = node(n.getx()-1, n.gety()-2);

    std::vector<node> cc;

    if (m1.getx() <= BoardWidth && m1.gety() <= BoardHeight && m1.getx() >=0 && m1.gety() >=0)
    {
        cc.push_back(m1);
    }

    if (m2.getx() <= BoardWidth && m2.gety() <= BoardHeight && m2.getx() >=0 && m2.gety() >=0)
    {
        cc.push_back(m2);
    }

    if (m3.getx() <= BoardWidth && m3.gety() <= BoardHeight && m3.getx() >=0 && m3.gety() >=0)
    {
        cc.push_back(m3);
    }
    if (m4.getx() <= BoardWidth && m4.gety() <= BoardHeight && m4.getx() >=0 && m4.gety() >=0)
    {
        cc.push_back(m4);
    }
    if (m5.getx() <= BoardWidth && m5.gety() <= BoardHeight && m5.getx() >=0 && m5.gety() >=0)
    {
        cc.push_back(m5);
    }
    if (m6.getx() <= BoardWidth && m6.gety() <= BoardHeight && m6.getx() >=0 && m6.gety() >=0)
    {
        cc.push_back(m6);
    }
    if (m7.getx() <= BoardWidth && m7.gety() <= BoardHeight && m7.getx() >=0 && m7.gety() >=0)
    {
        cc.push_back(m7);
    }
    if (m8.getx() <= BoardWidth && m8.gety() <= BoardHeight && m8.getx() >=0 && m8.gety() >=0)
    {
        cc.push_back(m8);
    }

    return cc;
}

int btree::BFS(int BoardHeight, int BoardWidth, node current, node target)
{
    std::queue<node> q;
    std::vector<node> cc;
    std::vector<node> visit;


    current.setVisited();
    q.push(current);
    visit.push_back(current);


    node v;
    v.setStepz(0);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        if(v.getx() == target.getx() && v.gety() == target.gety() )
        {
            return v.getStepz();
        }

        cc.clear();

        cc = catchChildren(BoardHeight, BoardWidth, v,target.getx(),target.gety());

        for(int i=0; i<cc.size();i++)
        {
            node temp=cc.at(i);
            for(int j=0;j<visit.size();j++)
            {
                if(temp.getx() == visit.at(j).getx() && temp.gety() == visit.at(j).gety())
                {
                    cc.at(i).setVisited();
                }
            }
        }
        for(int i=0; i<cc.size(); i++)
        {
            if(!cc.at(i).getVisited())
            {
                cc.at(i).setStepz(v.getStepz()+1);
                q.push(cc.at(i));
                visit.push_back(cc.at(i));

            }
        }
   }






}






















