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
    //cout << s << endl;
    istringstream iss(s);
    vector<string> tokens;
    copy(istream_iterator<string>(iss),
    istream_iterator<string>(),
    back_inserter(tokens));
    Node* current = root;
   
    if ( tokens.size() == 0 )
    {
        current->setWordMarker(); // an empty word
        return;
    }

    for ( int i = 0; i < tokens.size(); i++ )
    {        
        //cout << tokens.at(i) << endl;
        Node* child = current->findChild(tokens.at(i));
        if ( child != NULL )
        {
            current = child;
            current->setWordMarker();
            current->setWordFreq((current->getWordFreq()) + 1);
        }
        else
        {
            Node* tmp = new Node();
            tmp->setContent(tokens.at(i));
            current->appendChild(tmp);
            current = tmp;
            current->setWordMarker();
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
    istringstream iss(s);
    vector<string> tokens;
    copy(istream_iterator<string>(iss),
    istream_iterator<string>(),
    back_inserter(tokens));
    
    Node* current = root;
    while ( current != NULL )
    {
        for ( int i = 0; i < tokens.size(); i++ )
        {
            Node* tmp = current->findChild(tokens.at(i));
            cout << "cont: " << tmp->getContent() << endl;
            if ( tmp == NULL )
                return -1;
            current = tmp;
        }

        if ( current->wordMarker() )
        {
            //cout << "returning" << current->getWordFreq();
            return current->getWordFreq();
        }
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