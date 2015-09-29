/* 
 * File:   Tries.h
 * Author: Ayine
 *
 * Created on September 27, 2015, 12:43 AM
 */

#ifndef TRIES_H
#define	TRIES_H
#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

class Trie {
public:
    Trie();
    ~Trie();
    void addWord(string s);
    int searchWord(string s);
    void deleteWord(string s);
    Node* getRoot();
    void print(Node*);
private:
    Node* root;
};

#endif	/* TRIES_H */

