#include "tree.h"






Tree::Tree()
{
    this->left = nullptr;
    this->right = nullptr;
    this->S = 0;
    this->payOff = 0;
    this->H = 0;
    this->way = false;
}
void Tree::SetWay(bool way)
{
    this->way =way;
}

bool Tree::GetWay(Tree* root)
{
    return this->way;
}







void Tree::addLeftChild(Tree * tr)
{
    this->left = tr;
}

void Tree::addRightChild(Tree * tr)
{
    this->right = tr;
}

void Tree::Display(Tree *root, int step, int node) // profondeur
{
    if(root != nullptr)
    {
        std::cout <<"step : " << step << " node : " << node << " value : " << root->S << std::endl;
        step++;
        if(root->left != nullptr)
            this->Display(root->left, step, node);
        node++;
        if(root->right != nullptr)
            this->Display(root->right, step, node+node-1 );
    }

}

void Tree::Display(Tree *root) // Largeur
{
    if(root != nullptr)
    {
       queue<Tree*> fifo;
       fifo.push(root);
       int step = 0;
       int node = 0;
       int deep = this->Deep(root);
       int deepStep = pow(2,step) - 1 ;
       while(!fifo.empty())
        {
            Tree* n = fifo.front();

            fifo.pop();
            cout <<"Step : "<< step << " node : " << node << " value : " <<  n->S << " payOff : " << n->payOff << endl;
            if(node == deepStep)
            {
                node = 0;
                step++;
                deepStep = pow(2,step)-1;
            }
            else
                node++;

            if(n->left != nullptr)
            {
                fifo.push(n->left);
            }
            if(n->right != nullptr)
            {
                fifo.push(n->right);
            }
        }
    }
}

Tree* Tree::SetCorrection(Tree *root, int stepCorrection)
{
    if(root != nullptr)
    {
       queue<Tree*> fifo;
       fifo.push(root);
       int step = 0;
       int node = 0;
       int deep = this->Deep(root);
       int deepStep = pow(2,step) - 1 ;
       while(!fifo.empty())
        {
            Tree* n = fifo.front();
            fifo.pop();
            if(step >= stepCorrection-1)
            {
               n->addLeftChild(nullptr);
               n->addRightChild(nullptr);
            }
            if(node == deepStep)
            {
                node = 0;
                step++;
                deepStep = pow(2,step)-1;
            }
            else
                node++;

            if(n->left != nullptr)
            {
                fifo.push(n->left);
            }
            if(n->right != nullptr)
            {
                fifo.push(n->right);
            }
        }
    }

    return root;
}

void Tree::SetNode(Tree* root,int Step, int Node, double value)
{
    if(root != nullptr)
    {
       queue<Tree*> fifo;
       fifo.push(root);
       int step = 0;
       int node = 0;
       int deep = this->Deep(root);
       int deepStep = pow(2,step) - 1 ;
       while(!fifo.empty())
        {
            Tree* n = fifo.front();
            fifo.pop();
            if(step == Step && node == Node)
            {
               n->S = value;
            }
            if(node == deepStep)
            {
                node = 0;
                step++;
                deepStep = pow(2,step)-1;
            }
            else
                node++;

            if(n->left != nullptr)
            {
                fifo.push(n->left);
            }
            if(n->right != nullptr)
            {
                fifo.push(n->right);
            }
        }
    }
}


void Tree::SetWay(Tree* root,int Step, int Node, bool value)
{
    if(root != nullptr)
    {
       queue<Tree*> fifo;
       fifo.push(root);
       int step = 0;
       int node = 0;
       int deep = this->Deep(root);
       int deepStep = pow(2,step) - 1 ;
       while(!fifo.empty())
        {
            Tree* n = fifo.front();
            fifo.pop();
            if(step == Step && node == Node)
            {
               n->way = value;
            }
            if(node == deepStep)
            {
                node = 0;
                step++;
                deepStep = pow(2,step)-1;
            }
            else
                node++;

            if(n->left != nullptr)
            {
                fifo.push(n->left);
            }
            if(n->right != nullptr)
            {
                fifo.push(n->right);
            }
        }
    }
}


void Tree::SetPayOff(Tree* root,int Step, int Node, double value)
{
    if(root != nullptr)
    {
       queue<Tree*> fifo;
       fifo.push(root);
       int step = 0;
       int node = 0;
       int deep = this->Deep(root);
       int deepStep = pow(2,step) - 1 ;
       while(!fifo.empty())
        {
            Tree* n = fifo.front();
            fifo.pop();
            if(step == Step && node == Node)
            {
               n->payOff = value;
            }
            if(node == deepStep)
            {
                node = 0;
                step++;
                deepStep = pow(2,step)-1;
            }
            else
                node++;

            if(n->left != nullptr)
            {
                fifo.push(n->left);
            }
            if(n->right != nullptr)
            {
                fifo.push(n->right);
            }
        }
    }
}



double Tree::GetNodeValue(Tree* root,int Step, int Node)
{
    double value;
    if(root != nullptr)
    {
       queue<Tree*> fifo;
       fifo.push(root);
       int step = 0;
       int node = 0;
       int deep = this->Deep(root);
       int deepStep = pow(2,step) - 1 ;
       while(!fifo.empty())
        {
            Tree* n = fifo.front();
            fifo.pop();
            if(step == Step && node == Node)
            {
              value = n->S;
            }
            if(node == deepStep)
            {
                node = 0;
                step++;
                deepStep = pow(2,step)-1;
            }
            else
                node++;

            if(n->left != nullptr)
            {
                fifo.push(n->left);
            }
            if(n->right != nullptr)
            {
                fifo.push(n->right);
            }
        }
    }
    return value;
}


Tree* Tree::CreateTree(int deep)
{
       queue<Tree*> queuTree;
       int step = 0;
       int node = 0;
       Tree *root = new Tree();
       int deepR = this->Deep(root);
       int deepStep = pow(2,step) - 1 ;
       queuTree.push(root);
       while(deepR <= deep )
        {
            Tree* temp = queuTree.front();
            queuTree.pop();
            if(temp->left == nullptr)
            {
                Tree *left = new Tree();
                temp->addLeftChild(left);
                queuTree.push(left);
            }
            if(temp->right == nullptr)
            {
                Tree *right = new Tree();
                temp->addRightChild(right);
                queuTree.push(right);
            }
            deepR = this->Deep(root);
        }

        root = this->SetCorrection(root,deep);
        return root;
}


double Tree::SetH(Tree *root,int Step, int Node, double value)
{
    if(root != nullptr)
    {
       queue<Tree*> fifo;
       fifo.push(root);
       int step = 0;
       int node = 0;
       int deep = this->Deep(root);
       int deepStep = pow(2,step) - 1 ;
       while(!fifo.empty())
        {
            Tree* n = fifo.front();
            fifo.pop();
            if(step == Step && node == Node)
            {
               n->H = value;
            }
            if(node == deepStep)
            {
                node = 0;
                step++;
                deepStep = pow(2,step)-1;
            }
            else
                node++;

            if(n->left != nullptr)
            {
                fifo.push(n->left);
            }
            if(n->right != nullptr)
            {
                fifo.push(n->right);
            }
        }
    }
}


void Tree::setValueS(Tree *root)
{
    int deep = this->Deep(root);
    double S0 = 100;
    double up = 3;
    double down = 2;
    double r = 3;
    double q = (r-down) / ( up-down);
    bool way = root->GetWay(root);
    for(int i=0; i<deep; i++)
    {
        for(int j=0; j<= pow(2,i)-1;j++)
        {
            double value = S0*pow((1+up),j)*pow((1+down),(deep - j));
            root->SetNode(root,i,j,value);
            root->SetWay(root,i,j,way);
            if(way) // CAll
            {
                double payoff = std::max(0.0,value-S0);
                root->SetPayOff(root,i,j,payoff);
            }
            if(!way) // PUT
            {
                double payoff = std::max(0.0,S0-value);
                root->SetPayOff(root,i,j,payoff);
            }
          /*  if(deep-1-i == deep-1)
            {
                double Hn1 = root->GetNodeValue(root,deep-1,i+1);
                double Hi = root->GetNodeValue(root,deep-1,i);
                root->SetPayOff(root,i,j,payoff);
            }  */
           // double valueH =
           // root->SetH(root,deep-1-i,j,valueH);

        }
    }
}




int Tree::Deep(Tree *root)
{
    if(root == nullptr)
        return 0;
    else
    {
        return 1 + std::max(this->Deep(root->left), this->Deep(root->right));
    }
}



