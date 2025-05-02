#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cmath>
#include "SquareMat.hpp"

using namespace myMat;

void tsetConstructorAndAccess(){
    SquareMat mat(3);
    assert(mat[0][0] == 0.0); //check initilaize

    //check modify
    mat[0][0] = 1.0;
    mat[1][1] = 2.0;
    mat[2][2] = 3.0;
    assert(mat[0][0] == 1.0);
    assert(mat[1][1] == 2.0);
    assert(mat[2][2] == 3.0);
    
}

void testCopyAndAssignment(){
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    SquareMat mat2(mat1);
    assert(mat2[0][0] == 1.0);
    assert(mat2[0][1] == 2.0);
    assert(mat2[1][0] == 3.0);
    assert(mat2[1][1] == 4.0);

    SquareMat mat3 = mat1;
    assert(mat3[0][0] == 1.0);
    assert(mat3[0][1] == 2.0);
    assert(mat3[1][0] == 3.0);
    assert(mat3[1][1] == 4.0);
}

void testPlusAndMinus(){
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    SquareMat mat2(2);
    mat2[0][0] = 5;
    mat2[0][1] = 6;
    mat2[1][0] = 7;
    mat2[1][1] = 8;

    SquareMat sum = mat1+mat2;
    assert(sum[0][0] == 6.0);
    assert(sum[0][1] == 8.0);
    assert(sum[1][0] == 10.0);
    assert(sum[1][1] == 12.0);

    SquareMat dif = mat1-mat2;
    assert(dif[0][0] == -4.0);
    assert(dif[0][1] == -4.0);
    assert(dif[1][0] == -4.0);
    assert(dif[1][1] == -4.0);
    
    SquareMat neg = -mat1;
    assert(neg[0][0] == -1.0);
    assert(neg[0][1] == -2.0);
    assert(neg[1][0] == -3.0);
    assert(neg[1][1] == -4.0);

    //+=
    SquareMat mat3(mat1);
    mat3+=mat2;
    assert(mat3[0][0] == 6.0);
    assert(mat3[0][1] == 8.0);
    assert(mat3[1][0] == 10.0);
    assert(mat3[1][1] == 12.0);

    //-=
    mat3 = mat1;
    mat3 -= mat2;
    assert(mat3[0][0] == -4.0);
    assert(mat3[0][1] == -4.0);
    assert(mat3[1][0] == -4.0);
    assert(mat3[1][1] == -4.0);
    
}

void testMultiplyAndDivison(){
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    SquareMat mat2(2);
    mat2[0][0] = 5;
    mat2[0][1] = 6;
    mat2[1][0] = 7;
    mat2[1][1] = 8;

    SquareMat result = mat1*mat2;
    assert(result[0][0] == 19.0);
    assert(result[0][1] == 22.0);
    assert(result[1][0] == 43.0);
    assert(result[1][1] == 50.0);

    SquareMat res = mat1*2;
    assert(res[0][0] == 2.0);
    assert(res[0][1] == 4.0);
    assert(res[1][0] == 6.0);
    assert(res[1][1] == 8.0);

    SquareMat res1 = 2*mat1;
    assert(res1[0][0] == 2.0);
    assert(res1[0][1] == 4.0);
    assert(res1[1][0] == 6.0);
    assert(res1[1][1] == 8.0);

    SquareMat div = mat1/2;
    assert(div[0][0] == 0.5);
    assert(div[0][1] == 1.0);
    assert(div[1][0] == 1.5);
    assert(div[1][1] == 2.0);

    SquareMat mat3(mat1);
    mat3 *= mat1;
    assert(mat3[0][0] == 7.0);
    assert(mat3[0][1] == 10.0);
    assert(mat3[1][0] == 15.0);
    assert(mat3[1][1] == 22.0);

    mat3 = mat1;
    mat3 /= 2;
    assert(mat3[0][0] == 0.5);
    assert(mat3[0][1] == 1.0);
    assert(mat3[1][0] == 1.5);
    assert(mat3[1][1] == 2.0);

    bool ex = false;
    try
    {
        SquareMat divi = mat1/0;

    }
    catch(const std::invalid_argument& e)
    {
        ex = true;
    }
    assert(ex);
}

void testModolu(){
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    SquareMat mat2(2);
    mat2[0][0] = 5;
    mat2[0][1] = 6;
    mat2[1][0] = 7;
    mat2[1][1] = 8;

    SquareMat res = mat1%mat2;
    assert(res[0][0] == 5.0);
    assert(res[0][1] == 12.0);
    assert(res[1][0] == 21.0);
    assert(res[1][1] == 32.0);

    SquareMat mat3(mat1);
    mat3 %= mat2;
    assert(mat3[0][0] == 5.0);
    assert(mat3[0][1] == 12.0);
    assert(mat3[1][0] == 21.0);
    assert(mat3[1][1] == 32.0);

}

void testCompare(){
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    SquareMat mat2(2);
    mat2[0][0] = 5;
    mat2[0][1] = 6;
    mat2[1][0] = 7;
    mat2[1][1] = 8;

    SquareMat mat3(2);
    mat3[0][0] = 4;
    mat3[0][1] = 3;
    mat3[1][0] = 2;
    mat3[1][1] = 1;

    assert(mat1==mat3);
    assert(!(mat1==mat2));

    assert(mat1!=mat2);
    assert(!(mat1!=mat3));
    assert(mat1<mat2);

    assert(mat2>mat1);
    assert(mat1<=mat2);

    assert(mat2>=mat1);

}

void testDecAndInc(){
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;
    //pre
    ++mat1;
    assert(mat1[0][0] == 2.0);
    assert(mat1[0][1] == 3.0);
    assert(mat1[1][0] == 4.0);
    assert(mat1[1][1] == 5.0);

    SquareMat mat2(2);
    mat2[0][0] = 1;
    mat2[0][1] = 2;
    mat2[1][0] = 3;
    mat2[1][1] = 4;
    
    //post
    SquareMat res2 = mat2++;
    assert(mat2[0][0] == 2.0);
    assert(mat2[0][1] == 3.0);
    assert(mat2[1][0] == 4.0);
    assert(mat2[1][1] == 5.0);

    //pre
     --mat1;
    assert(mat1[0][0] == 1.0);
    assert(mat1[0][1] == 2.0);
    assert(mat1[1][0] == 3.0);
    assert(mat1[1][1] == 4.0);

    SquareMat mat4(2);
    mat2[0][0] = 1;
    mat2[0][1] = 2;
    mat2[1][0] = 3;
    mat2[1][1] = 4;

}

void testPower(){
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;
    
    SquareMat res = mat1^2;
    assert(res[0][0] == 7.0);
    assert(res[0][1] == 10.0);
    assert(res[1][0] == 15.0);
    assert(res[1][1] == 22.0);

    bool ex = false;
    try
    {
        SquareMat r = mat1^-1;

    }
    catch(const std::invalid_argument& e)
    {
        ex = true;
    }
    assert(ex);
}

void testTranspoes(){
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;
    
    SquareMat res = ~mat1;
    assert(res[0][0] == 1.0);
    assert(res[0][1] == 3.0);
    assert(res[1][0] == 2.0);
    assert(res[1][1] == 4.0);
}

void testDet(){
    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;
    assert(!mat1 == -2);
}

int main(){
    std::cout << "running tests..."<< std::endl;
    tsetConstructorAndAccess();
    testCopyAndAssignment();
    testPlusAndMinus();
    testMultiplyAndDivison();
    testModolu();
    testCompare();
    testDecAndInc();
    testPower();
    testTranspoes();
    testDet();

    std:: cout<< "all tests are passed"<< std::endl;

}