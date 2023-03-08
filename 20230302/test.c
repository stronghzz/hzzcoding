#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int val;
    struct list *next;
} List;

List *CreatList()
{
    List *l = (List *)malloc(sizeof(List));
    l->next = NULL;
    l->val = 0;
    return l;
}

void AddLastNode(List *l, int val)
{
    if (l == NULL)
    {
        return;
    }
    List *_l = (List *)malloc(sizeof(List));
    _l->val = val;
    _l->next = NULL;
    while (l->next != NULL)
    {
        l = l->next;
    }
    l->next = _l;
}

void ShowList(List *l)
{
    if (l == NULL)
    {
        return;
    }
    while (l != NULL)
    {
        printf("%d\n", l->val);
        l = l->next;
    }
}

void deletlast(List *l)
{
    List *_l = (List *)malloc(sizeof(List));
    _l = l;
    while (_l->next->next != NULL)
    {
        _l = _l->next;
    }
    free(_l->next);
    _l->next = NULL;
}
int main()
{
    List *l = CreatList();
    AddLastNode(l, 1);
    AddLastNode(l, 2);
    AddLastNode(l, 3);
    ShowList(l);
    deletlast(l);
    ShowList(l);
    return 0;
}