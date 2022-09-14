#include <iostream>



int main(){
    int* ptr_i = new int(3);
    int*& r_ptr_i1 = ptr_i;
    int*& r_ptr_i2 = ptr_i;

    delete r_ptr_i1;
    // delete r_ptr_i2;

    return 0;
}