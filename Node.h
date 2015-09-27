/* 
 * File:   Node.h
 * Author: Ayine
 *
 * Created on September 27, 2015, 12:45 AM
 */

#ifndef NODE_H
#define	NODE_H
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node();
    Node(const Node& orig);
    virtual ~Node();
    char content();
    void setContent(char c);
    bool wordMarker();
    void setWordMarker();
    Node* findChild(char c);
    void appendChild(Node* child);
    vector<Node*> children();

private:
    char mContent;
    bool mMarker;
    vector<Node*> mChildren;
};

#endif	/* NODE_H */

