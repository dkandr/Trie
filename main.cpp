#include <iostream>
#include "Trie.h"

bool checkString(string &str)
{
    for(char ch : str)
    {
        if (ch < 'a' || ch > 'z')
            return false;        
    }

    return true;
}

int main()
{
    TrieNode *trieRoot = new TrieNode();
    std::string str;
    char operation;

    do
    {
        std::cout << "1. Add word to dictionary" << std::endl;
        std::cout << "2. Show words with prefix" << std::endl;
        std::cout << "3. Quit" << std::endl;

        std::cin >> operation;

        switch (operation)
        {
        case '1':
            std::cout << "Input word : ";
            std::cin >> str;

            if (checkString(str))
            {
                insert(trieRoot, str);
            }
            else
                std::cout << "Bad symbol in word. Use only [a-z] symbols." << std::endl;
            
            break;

        case '2':
            std::cout << "Input pefix : ";
            std::cin >> str;
        
            if (checkString(str))
            {
                std::cout << "Find words:" << std::endl;

                for(auto &s : searchAllWords(trieRoot, str))
                {
                    std::cout << s << std::endl;
                }
            }
            else
                std::cout << "Bad symbol in prefix. Use only [a-z] symbols." << std::endl;
            
            break;        

        case '3':
            break;

        default:
            std::cout << "Choose 1, 2 or 3.." << std::endl;
            break;
        }

    } while (operation != '3');
    
    delete trieRoot;

    return 0;
}