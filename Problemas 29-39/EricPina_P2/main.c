#include <stdio.h>
/* Eric Pina 2023-0042 */

void main() {

    int i = 15, j, k, l;

    j = (15 > i--) > (14 < ++i);
    printf("\nEl valor de j es de: %d", j);

    k = ! ('b' != 'd') > (!i - 1);
    printf("\nEl valor de k es de: %d", k);

    l = (!(34>(70%2))||0);
    printf("\nEl valor de k es de: %d", l);

}

