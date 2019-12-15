int main(void) {

    int a = 5, b = 10, c = -4, d = 50;
    int *pa = &a;
    const int* pb = &b;
    // *pb = 6; 
    // this is not possible
    // pb is pointing const int
    b = 6;
    int* const pc = &c;
    // pc = &a; 
    // this is not possible
    // pc is const pointer 
    *pc = a;
    const int * const pd = &d;
    // pd = &c;
    // *pd = 10;
    // none of above are possible
    // pc is const pointer 

    return 0;
}