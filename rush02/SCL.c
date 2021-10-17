#include <stdlib.h>
#include "utils.h"

void node_alloc(PointSCL *scl, char *s) {
    PointSCL temp;
    PointSCL dest;

    temp = *scl;
    dest = *scl;
    *scl = (PointSCL)malloc(sizeof(NodoSCL));
    (*scl)->lenght = ft_len(s);
    (*scl)->nb = ft_atoi(s);
    (*scl)->string = get_string(s);
    (*scl)->next = NULL;
    if (temp != NULL) 
    {
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = *scl;
        *scl = dest;
    }
}
