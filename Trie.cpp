#include "Trie.h"

using namespace std;

// Возвращет новый узел с пустыми детьми
TrieNode *getNewNode(void)
{
    // Выделяем память по новый узел
    struct TrieNode *pNode =  new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false; 

    // инициализируем детей нулевым указателем
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = nullptr;

    return pNode;
} 

// Вставляет ключ в дерево, если его нет, 
// иначе если ключ явлется префксом узла дерева 
// помечает вкачестве листового т.е. конец слова
void insert(TrieNode* root, string key) 
{
    TrieNode* node = root; 

    for (int i = 0; i < key.length(); i++)
    {
        // вычисляем индекс в алфите через смещение отнситьельно первой буквы
        int index = key[i] - 'a'; 

        // если указатель пустрой, т.е. детей с таким префиксом нет
        // создаем новый узел
        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
    }

    // помечаем последний узлел как лист, т.е. конец слова
    node->isEndOfWord = true;
}

// Возврашает true если ключ есть в дереве, иначе false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *node = root; 

    for (int i = 0; i < key.length(); i++) 
    {
        int index = key[i] - 'a'; 
        if (!node->children[index]) 
            return false;

        node = node->children[index]; 
    }

    return (node != nullptr && node->isEndOfWord); 
}

// Вохвращает true если root имеет лист, иначе false 
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

//Получаем все слова по префиксу
vector<string> searchAllWords(TrieNode *root, const string &prefix)
{
    vector<string> result;
    struct TrieNode *node = root;
    std::string str = prefix;
    int prefix_length = prefix.length();

    if (root)
    {
        for (int i = 0; i < prefix_length; i++)
        {
            if (node -> children[prefix[i] - 'a'])
                node = node -> children[prefix[i] - 'a'];
            else
                return result;
        }
               
        searchAllWordsInner(node, str, result);  
    }

    return result;
}

void searchAllWordsInner(TrieNode *node, string str, vector<string> &result)
{
    if (node -> isEndOfWord)
        result.push_back(str);

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node -> children[i])
        {
            char ch = i + 'a'; 
            searchAllWordsInner(node -> children[i], str + ch, result);
        }
    }

    return;
}