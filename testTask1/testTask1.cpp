#include <iostream>

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main()
{
    int x1 = 3, x2 = 3;
    int y1 = 5, y2 = 5;
    printf("MIN(%d, %d) = %d;\n", x1, y1, MIN(x1++, y1));
    printf("MIN(%d, %d) = %d;\n", x1, y1, MIN(++x1, y1));
    printf("min(%d, %d) = %d;\n", x2, y2, min(++x2, y2));
    printf("min(%d, %d) = %d;\n", x2, y2, min(x2++, y2));


}

/*
* output:
* MIN(5, 5) = 4;
* MIN(6, 5) = 5;
* min(4, 5) = 4;
* min(5, 5) = 4;
* 
* there are only 2 correct lines in the output, they had ++x operator, and not x++
* this is due to how ++x works, it increases the value before returning it
* we can also see that in the first line x1 is increased by 2, 
* thats because is was basically turned into (x1++<y1?x1++:y1), and x1 was increased twice
* and because of the order of execution in expressions with commas, we have already increaced number in the output
* also the seccond line is correct only because it didn't return the value that we passed via increment operator,
* if we had MIN(++x1, ++y1), the results wouldn't be right
* so it's better to just not use macros with increment/decrement operators
*/