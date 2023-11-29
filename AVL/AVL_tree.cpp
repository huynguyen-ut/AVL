#include "AVL_tree.h"
#include <iostream>
#include "Node.h"
using namespace std;
AVL_tree::AVL_tree()
{
    //ctor
    this->root = nullptr;
}

AVL_tree::~AVL_tree()
{
    //dtor
}
bool AVL_tree::InsertNode(Node* n) {
    Node* p = this->root;
    Node* T=nullptr;
    if (root == nullptr)
    {
        this->root = n;

        return true;
    }
    while (p != nullptr) {
        T = p;

        if (p->Getkey() > n->Getkey())
            p = p->Getleft();
        else
            if (p->Getkey() < n->Getkey())
                p = p->Getright();
            else
                if (p->Getkey() == n->Getkey())
                    return false;
    }

    if (T->Getkey() > n->Getkey())
        T->Setleft(n);
    else T->Setright(n);
    n->Setparent(T);

    Node* x = n;
    Node* parentX = x->Getparent();
    while (x!= nullptr) {
        int bal = this->CheckBal(x);
        switch (bal) {
        case 0:    break;     // Can bang
        case 1:    break;     //
        case -1:   break;   //

        case 2:if (x->Getleft()->Getleft() != nullptr)// LEFT-LEFT
        {
            this->RightRotate(x);
            x->Setparent(parentX);
            if (x->Getkey() > parentX->Getkey())
                parentX->Setright(x);
            else parentX->Setleft(x);
        }
              else // Left-Right
        {

        }
              break;     //
        case -2: if (x->Getright()->Getright() != nullptr)  // RIGHT-RIGHT
        {
            parentX = x->Getparent();
            this->LeftRotate(x);
            x->Setparent(parentX);

            if(parentX!=nullptr)
            if (x->Getkey() > parentX->Getkey())
                parentX->Setright(x);
            else parentX->Setleft(x);
        }
               else // Right-right
        {

        }
               break;   //
        }
        if (x->Getparent() == nullptr)
            this->root = x;
        x = x->Getparent();
       
    }

    return true;

}
Node* AVL_tree::InsertNode(Node* r, Node* p) {
    if (r == nullptr) {
        r = p;
        return r;
    }
    if (r->Getkey() == p->Getkey())
        return nullptr;
    else if (r->Getkey() > p->Getkey()) {
        r->Setleft(InsertNode(r->Getleft(), p));
        return r->Getleft();
    }
    else {
        r->Setright(InsertNode(r->Getright(), p));
        return r->Getright();
    };
    //
 /*   r->Setheight ( 1 + max(r->Getleft()->Getheight(),r->Getright()->Getheight()));

    int valBalance = r->Getleft()->Getheight() - r->Getright()->Getheight();

    if(valBalance>1&&r->Getleft()->Getkey()>p->Getkey())
        this->RightRotate(r);*/

}


void AVL_tree::InsertNodeRe(Node* p) {
    this->root = InsertNode(this->root, p);
}
void AVL_tree::NLR(Node* r) {
    if (r != nullptr) {
        cout << r->Getkey() << "\n";
        NLR(r->Getleft());
        NLR(r->Getright());
    }
}
void AVL_tree::LNR(Node* r) {
    //sinh vien code
}
void AVL_tree::LRN(Node* r) {
    //sinh vien code
}
void AVL_tree::TravelNLR() {
    NLR(this->root);
}
void AVL_tree::TravelLNR() {
    //sinh vien code
}
void AVL_tree::TravelLRN() {
    //sinh vien code
}
Node* AVL_tree::search_x(int k) {
    //sinh vien code
    return nullptr;
}
void AVL_tree::deleteNode(Node* n) {
    Node* p = n;
    if (n->Getleft() == nullptr && n->Getright() == nullptr)
        delete n;
    else {
        if (p->Getright() != nullptr) {
            while (p->Getleft() != nullptr)//
                p = p->Getleft();
            n->Setkey(p->Getkey());
            // Code
            delete p;
        }
        else {
            while (p->Getright() != nullptr)//
                p = p->Getright();

            n->Setkey(p->Getkey());
            //code
            delete p;
        }
    }
}
void AVL_tree::LeftRotate(Node*& P) {
    Node* Q;
    Node* T;
    Q = P->Getright();
    T = Q->Getleft();
    P->Setright(Q->Getleft());
    Q->Setleft(P);
    P->Setparent(Q);
    if(T!=nullptr)
    T->Setparent(P);
    P = Q;
}
void AVL_tree::RightRotate(Node*& P) {
    Node* Q;
    Node* T;
    Q = P->Getright();
    T = Q->Getleft();
    P->Setright(Q->Getleft());
    Q->Setleft(P);
    P->Setparent(Q);
    T->Setparent(P);
    P = Q;
}
int AVL_tree::CheckBal(Node* p) {
    int bal = this->GetHeight(p->Getleft()) - this->GetHeight(p->Getright());
    return bal;
}
int AVL_tree::GetHeight(Node* p) {
    if (p == nullptr) return 0;
    else
    return 1 + max(GetHeight(p->Getleft()), GetHeight(p->Getright()));
}
