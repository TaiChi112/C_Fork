#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum e_stove
{
    GAS,
    ELECTRIC,
    INDUCTION,
};
typedef struct s_stove
{
    enum e_stove type;
    void (*show_stove_type)(struct s_stove *stove);
    void (*set_stove_type)(struct s_stove *stove, enum e_stove type);
    int (*get_stove_type)(struct s_stove *stove);
} s_stove;
void set_stove_type(s_stove *stove, enum e_stove type)
{
    stove->type = type;
}
int get_stove_type(s_stove *stove)
{
    return stove->type;
}
void show_stove_type(s_stove *stove)
{
    switch (stove->type)
    {
    case GAS:
        printf("Stove type: GAS\n");
        break;
    case ELECTRIC:
        printf("Stove type: ELECTRIC\n");
        break;
    case INDUCTION:
        printf("Stove type: INDUCTION\n");
        break;
    default:
        printf("Unknown stove type\n");
        break;
    }
}



int main()
{
    s_stove stove = {GAS};
    stove.show_stove_type = show_stove_type;
    stove.show_stove_type(&stove);

    stove.set_stove_type = set_stove_type;
    stove.set_stove_type(&stove, ELECTRIC);
    stove.show_stove_type(&stove);

    stove.get_stove_type = get_stove_type;
    int type = stove.get_stove_type(&stove);
    printf("Stove type (enum): %d\n", type);
    printf("Stove type (string): %s\n", type == GAS ? "GAS" : type == ELECTRIC ? "ELECTRIC" : "INDUCTION");
    return 0;
}