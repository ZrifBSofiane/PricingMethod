#ifndef _TREE_HPP
#define _TREE_HPP
#include <math.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Tree
{

private:
    double S;
    double payOff;
    bool way; // 1 is Call 0 is Put
    double H;
    Tree *left;
    Tree *right;
    Tree* SetCorrection(Tree *root, int stepCorrection);

public:
    Tree();
    bool GetWay(Tree* root);
    void SetWay(bool way);
    void addLeftChild(Tree * tr);
    void addRightChild(Tree * tr);
    void Display(Tree *root, int step, int node);
    void Display(Tree *root);
    int Deep(Tree *root);
    Tree* CreateTree(int deep);
    double SetH(Tree *root,int Step, int Node, double value);
    void SetNode(Tree* root,int Step, int Node, double value);
    void SetWay(Tree* root,int Step, int Node, bool value);
    void SetPayOff(Tree* root,int Step, int Node, double value);
    double GetNodeValue(Tree* root,int step, int node);
    void setValueS(Tree *root);

};



#endif // _TREE_HPP


