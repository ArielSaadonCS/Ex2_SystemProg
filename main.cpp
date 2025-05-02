//arielsaadon1446@gmail.com

#include <iostream>
#include "SquareMat.hpp"

using namespace myMat;

int main(){

    SquareMat mat1(2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    std::cout << "matrix mat1: \n" << mat1 << "\n";

    SquareMat mat2 = mat1+mat1;

    std::cout << "mat2 = mat1+mat1: \n" << mat2 << "\n";

    SquareMat transposed = ~mat1;
    std::cout << "transpose on mat1: \n" << transposed << "\n";

    // SquareMat det = !mat2;
    // std::cout << "detreminant of mat1: \n" << det << "\n";

    SquareMat power = mat1^2;
    std::cout << "power of mat1: \n" << power << "\n";

    ++mat1;
    std::cout << "mat1 after ++: \n" << mat1 << "\n";

    --mat2;
    std::cout << "mat1 after --: \n" << mat1 << "\n";

    if(mat1==mat1){
        std::cout << "check eaual sum of elments\n";
    }

    if(mat1 !=mat2){
        std::cout << "check not eaual sum of elments\n";
    }

    SquareMat mat3 = mat1*mat1;

    std::cout << "mat3 = mat1*mat1: \n" << mat3 << "\n";

    
    SquareMat mat4 = mat3/2;

    std::cout << "mat4 = mat3/mat1: \n" << mat4 << "\n";

    SquareMat mat5 = mat3%mat1;

    std::cout << "mat5 = mat3 modolu mat1: \n" << mat5 << "\n";




}
