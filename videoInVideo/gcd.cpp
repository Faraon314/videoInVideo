#include <gcd.h>

//нод
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//нок

int lcm(int a,int b){
    return a*b/gcd(a,b);
}
