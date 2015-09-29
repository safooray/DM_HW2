/* 
 * File:   Trie.cpp
 * Author: Ayine
 * 
 * Created on September 27, 2015, 12:43 AM
 */
#include "Trie.h"
#include "Node.h"

Trie::Trie()
{
    root = new Node();
}
Node* Trie::getRoot() {return root;}

Trie::~Trie()
{
    // Free memory
}

void Trie::addWord(string s)
{
    istringstream iss(s);
    vector<string> tokens{istream_iterator<string>{iss},
                      istream_iterator<string>{}};
    Node* current = root;
   
    if ( tokens.size() == 0 )
    {
        current->setWordMarker(); // an empty word
        return;
    }

    for ( int i = 0; i < tokens.size(); i++ )
    {        
        Node* child = current->findChild(tokens.at(i));
        if ( child != NULL )
        {
            current = child;
            current->setWordFreq((current->getWordFreq()) + 1);
        }
        else
        {
            Node* tmp = new Node();
            tmp->setContent(tokens.at(i));
            current->appendChild(tmp);
            current = tmp;
            current->setWordFreq((current->getWordFreq()) + 1);
        }
        if ( i == tokens.size() - 1 )
        {
            current->setWordMarker();
            current->setWordFreq((current->getWordFreq()) + 1);
        }
    }
}


int Trie::searchWord(string s)
{
    Node* current = root;

    while ( current != NULL )
    {
        for ( int i = 0; i < s.length(); i++ )
        {
            Node* tmp = current->findChild(s[i]);
            if ( tmp == NULL )
                return -1;
            current = tmp;
        }

        if ( current->wordMarker() )
            return current->getWordFreq();
        else
            return -1;
    }

    return -1;
}

void Trie::print(Node* current)
{
    if ( current != NULL )
    {
        if (current->wordMarker())
            cout << current->getWordFreq() << endl;
        vector <Node*> children = current->children();
        int i = 0;
        for (;i < children.size(); i++)
        {
            print(children.at(i));
        }
    }
    else
        return;
}