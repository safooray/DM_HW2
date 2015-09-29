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
    void setContent(std::string s);
    std::string getContent();
    bool wordMarker();
    void setWordMarker();
    Node* findChild(std::string s);
    void appendChild(Node* child);
    vector<Node*> children();
    int setWordFreq(int f);
    int getWordFreq();

private:
    std::string mContent;
    bool mMarker;
    int mFreq;
    vector<Node*> mChildren;
};

#endif	/* NODE_H */

