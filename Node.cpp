/* 
 * File:   Node.cpp
 * Author: Ayine
 * 
 * Created on September 27, 2015, 12:45 AM
 */

#include "Node.h"


Node::Node() { mContent = " "; mMarker = false; mFreq = 0;}
Node::~Node() {}
char Node::content() { return mContent; }
void Node::setContent(std::string s) { mContent = s; }
bool Node::wordMarker() { return mMarker; }
void Node::setWordMarker() { mMarker = true; }
int Node::setWordFreq(int f) { mFreq = f; }
int Node::getWordFreq() {return mFreq;}
Node* Node::findChild(std::string s)
{
    for ( int i = 0; i < mChildren.size(); i++ )
    {
        Node* tmp = mChildren.at(i);
        if ( strcmp(tmp->content(), s) == 0)
        {
            return tmp;
        }
    }

    return NULL;
}
void Node::appendChild(Node* child) { mChildren.push_back(child); }
vector<Node*> Node::children() { return mChildren; }

