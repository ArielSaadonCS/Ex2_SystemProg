#include <iostream>
#include <stdexcept>

namespace myMat{
class SquareMat
{
private:
    int size;
    double **data;

    void allocate_memory();
    void copy(const SquareMat &other);
    void free_memory();

public:
    SquareMat(int size);
    ~SquareMat();
    SquareMat(const SquareMat &other);

    SquareMat& operator=(const SquareMat &other);
    //SquareMat& operator=(SquareMat &&other);
    
    //access to data inside the matrix
    double* operator[](int i); //access and change
    const double* operator[](int i)const; // access and not change

    //actions between matrices

    SquareMat operator+(const SquareMat &other)const; //plus between matrices    V
    SquareMat operator-(const SquareMat &other)const; //minus between matrices   V
    SquareMat operator-()const; //unary minus                                    V
    SquareMat operator*(const SquareMat &other)const; //duplicate between matrices     V
    SquareMat operator%(const SquareMat &other)const;       //V

    //actions matrix and scalar
    SquareMat operator*(double scalar)const; //duplicate with scalar  V 
    SquareMat operator/(double scalar)const; //divide with scalar     v
    SquareMat operator%(double scalar)const; //modoulu with scalar

    //actions with assignment

    SquareMat& operator+=(const SquareMat &other); //plus with assignment     V
    SquareMat& operator-=(const SquareMat &other); //minus with assignment       v
    SquareMat& operator*=(const SquareMat &other); //duplicate matrix with assignment        v
    SquareMat& operator*=(double scalar); //duplicate with scalar with assignment        V
    SquareMat& operator/=(double scalar); //divide with scalar with assignment
    SquareMat& operator%=(const SquareMat &other);                    //               V
    SquareMat& operator%=(double scalar);

    //other actions

    SquareMat operator^(int power) const; // power on matrix         V
    SquareMat& operator++();//increaese each in the matrix in 1 pre   V
    SquareMat operator++(int);//increaese each in the matrix in 1 post V
    SquareMat& operator--();//dencreaese each in the matrix in 1 pre  V
    SquareMat operator--(int);//decreaese each in the matrix in 1 post  V
    SquareMat operator~()const;//transpose                  V

    //comparisons

    bool operator==(const SquareMat &other)const;//checking if equal by sum           V
    bool operator!=(const SquareMat &other)const;//checking if not equal               V
    bool operator>(const SquareMat &other)const;//                          V
    bool operator<(const SquareMat &other)const;//                       V
    bool operator>=(const SquareMat &other)const;//                      V
    bool operator<=(const SquareMat &other)const;//                       V

    double operator!()const;//for determinanta
    friend std::ostream& operator<<(std::ostream& os, const SquareMat &mat); 

};
    SquareMat operator*(double scalar, const SquareMat &mat);

};

