//not working. segmentation fault
#include <bits/stdc++.h>
using namespace std;
typedef struct trie_n_t{
    char* data;
    struct trie_n_t *next[256];
} trie_node_t;

trie_node_t *get_node()
{
    cout << "Enter the word\n";
    char* word;
    cin >> word;
    trie_node_t *node;
    node->data = word;
    return node;
}

trie_node_t *create_trie(void)
{
    trie_node_t *tmp_node;
    int i;
    tmp_node = get_node();
    for(i = 0; i<256; i++)
    {
        tmp_node->next[i] = NULL;
    }
    return (tmp_node);
}
 
int insert(trie_node_t *trie, char *new_string, trie_node_t *new_object)
{
    trie_node_t *tmp_node, *new_node;
    char *query_next;
    tmp_node = trie; query_next = new_string;
    while(*query_next != '\0')
    {
        if(tmp_node->next[(int)(*query_next)] == NULL)
        {
            new_node = get_node();
            for(int i = 0; i<256; i++)
                new_node->next[i] = NULL;
            tmp_node->next[(int)(*query_next)] = new_node;
        }
        tmp_node = tmp_node->next[(int)(*query_next)];
        query_next += 1;
    }
    if(tmp_node->next[(int)'\0'] != NULL)
        return (-1);
    else 
        tmp_node->next[(int)'\0'] = (trie_node_t *) new_object;
    return (0);
}

int main()
{
    trie_node_t *ans = create_trie();
    return 0;
}