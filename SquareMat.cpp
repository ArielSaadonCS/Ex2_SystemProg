//arielsaadon1446@gmail.com

#include <iostream>
#include <stdexcept>
#include <cmath>
#include "SquareMat.hpp"

namespace myMat{



SquareMat::SquareMat(int n)
{
    if(n <= 0){
        throw std:: invalid_argument("size must be positive");
    }
    size = n;
    data = new double*[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = new double[size];
        for (int j = 0; j < size; j++)
        {
            data[i][j] = 0.0;
        }       
    }
    
}

SquareMat::~SquareMat()
{
    for (int i = 0; i < size; i++)
    {
        delete[] data[i];
    }
    delete[] data;   
}

SquareMat::SquareMat(const SquareMat &other){
    size = other.size;
    data = new double*[size];

    for (int i = 0; i < size; i++)
    {
        data[i] = new double[size];
        for (int j = 0; j < size; j++)
        {
            data[i][j] = other.data[i][j];
        }       
    }
}

SquareMat& SquareMat::operator=(const SquareMat &other){
    if(this != &other){
        for (int i = 0; i < size; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    size= other.size;
    data= new double*[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = new double[size];
        for (int j = 0; j < size; j++)
        {
            data[i][j] = other.data[i][j];
        }
        
    }
    return *this;
}

double* SquareMat::operator[](int i){
    if(i < 0 || i >= size){
        throw std::out_of_range("index out of bounds");
    }
    return data[i];
}

const double* SquareMat::operator[](int i)const{
    if(i < 0 || i >= size){
        throw std::out_of_range("index out of bounds");
    }
    return data[i];
}

SquareMat SquareMat::operator+(const SquareMat &other)const{
    if(size != other.size){
        throw std::invalid_argument("size mismatch");
    }
    SquareMat result(size);
    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
        
    }
    return result;
}

SquareMat& SquareMat::operator+=(const SquareMat &other){
    if(size != other.size){
        throw std::invalid_argument("size mismatch");
    }
    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
             data[i][j] += other.data[i][j];
        }
        
    }
    return *this;
}

SquareMat SquareMat::operator-(const SquareMat &other)const{
    if(size != other.size){
        throw std::invalid_argument("size mismatch");
    }
    SquareMat result(size);
    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
        
    }
    return result;
}

SquareMat SquareMat::operator-()const{
    SquareMat result(size);

    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            result.data[i][j] = -data[i][j];
        }
        
    }
    return result;
}

SquareMat& SquareMat::operator-=(const SquareMat &other){
    if(size != other.size){
        throw std::invalid_argument("size mismatch");
    }
    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
             data[i][j] -= other.data[i][j];
        }
        
    }
    return *this;
}

SquareMat SquareMat::operator*(const SquareMat &other)const{
    if(size != other.size){
        throw std::invalid_argument("size mismatch");
    }
    SquareMat result(size);
    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
            
        }
        
    }
    return result;
}

SquareMat SquareMat::operator*(double scalar)const{
    SquareMat result(size);

    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            result.data[i][j] = data[i][j]*scalar;
        }
        
    }
    return result;
}

SquareMat& SquareMat::operator*=(const SquareMat &other){ 
    *this = (*this) * other;
    return *this;
}

SquareMat& SquareMat::operator*=(double scalar){
    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            data[i][j] *= scalar;
        }
        
    }
    return *this;
}

SquareMat operator*(double scalar, const SquareMat &mat){
    return mat*scalar;
} 

SquareMat SquareMat::operator%(const SquareMat &other)const{
    if(size != other.size){
        throw std::invalid_argument("size mismatch");
    }
    SquareMat result(size);
    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            result.data[i][j] = data[i][j] * other.data[i][j];
        }
        
    }
    return result;
}

SquareMat SquareMat::operator%(double scalar)const{
    SquareMat result(size);

    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            result.data[i][j] = fmod(data[i][j],scalar);
        }
        
    }
    return result;
}

SquareMat& SquareMat::operator%=(const SquareMat &other){
    if(size != other.size){
        throw std::invalid_argument("size mismatch");
    }
    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            data[i][j] *= other.data[i][j];
        }
        
    }
   
    return *this;
}

SquareMat& SquareMat::operator%=(double scalar){
    
    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            data[i][j] = fmod(data[i][j],scalar);
        }
        
    }
    return *this;
}


SquareMat& SquareMat::operator/=(double scalar){
    
    if(scalar==0){
        throw std::invalid_argument("can't divide by zero");
    }

    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            data[i][j] /= scalar;
        }
        
    }
    return *this;
}

SquareMat SquareMat::operator/(double scalar)const{

    if(scalar==0){
        throw std::invalid_argument("can't divide by zero");
    }
    SquareMat result(size);

    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            result.data[i][j] = data[i][j]/scalar;
        }
        
    }
    return result;
}

SquareMat SquareMat::operator~()const{
    SquareMat result(size);

    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            result.data[i][j] = data[j][i];
        }
        
    }
    return result;
}

bool SquareMat::operator==(const SquareMat &other)const{
    double sum1 = 0;
    double sum2 = 0;
    
    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            sum1 += data[i][j];
            sum2 += other.data[i][j];
        }
        
    }
    return sum1==sum2;
}

bool SquareMat::operator!=(const SquareMat &other)const{
    return !(*this==other);
}

bool SquareMat::operator<(const SquareMat &other)const{
    double sum1 = 0;
    double sum2 = 0;
    
    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            sum1 += data[i][j];
            sum2 += other.data[i][j];
        }
        
    }
    return sum1<sum2;
}

bool SquareMat::operator>(const SquareMat &other)const{
    double sum1 = 0;
    double sum2 = 0;
    
    for (int i = 0; i < size; i++)
    {
        for( int j = 0; j < size; j++)
        {
            sum1 += data[i][j];
            sum2 += other.data[i][j];
        }
        
    }
    return sum1>sum2;
}

bool SquareMat::operator>=(const SquareMat &other)const{
    return !(*this < other);
}

bool SquareMat::operator<=(const SquareMat &other)const{
    return !(*this > other);
}

SquareMat SquareMat::operator^(int power)const{
    if(power < 0){
        throw std::invalid_argument("not supporting negetive power");
     }
     SquareMat result(size);
     for (int i = 0; i < size; i++)
     {
        result.data[i][i] = 1;

     }
     SquareMat base(*this);
        while (power)
        {
            if(power % 2 == 1){
                result = result*base;
            }
            base= base*base;
            power /= 2;
        }
        
     
     return result;
}

SquareMat& SquareMat::operator++(){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            ++data[i][j];
        }
        
    }
    return *this;

}

SquareMat SquareMat::operator++(int){
    SquareMat temp(*this);
    ++(*this);
    return temp;
}

SquareMat& SquareMat::operator--(){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            --data[i][j];
        }
        
    }
    return *this;
}

SquareMat SquareMat::operator--(int){
    SquareMat temp(*this);
    --(*this);
    return temp;
}

double SquareMat::operator!()const{
    if(size == 1){
        return data[0][0];
    }
    if(size==2){
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }

    SquareMat temp(*this);
    double det =1;
    int sign =1;

    for (int i = 0; i < size; i++)
    {
        if(temp.data[i][i] == 0){
            bool found = false;
        
        for (int j = i+1; j < size; ++j)
        {
            if(temp.data[j][i] != 0){
            for (int k = 0; k < size; k++)
            {
                double tmp = temp.data[i][k];
                temp.data[i][k] = temp.data[j][k];
                temp.data[j][k] = tmp;
            }
            sign *= -1;
            found = true;
            break;
            }
        }
        if (!found) return 0;
    }
     det *= temp.data[i][i];

     for (int k = i+1; k < size; k++)
     {
        double factor = temp.data[k][i] / temp.data[i][i];
        for (int j = i; j < size; j++)
        {
            temp.data[k][j] -= factor * temp.data[i][j];
        }
        
     }
     
}
    return det*sign;

}

std::ostream& operator<<(std::ostream &os, const SquareMat &mat){
    for (int i = 0; i < mat.size; i++)
    {
        for (int j = 0; j < mat.size; j++)
        {
            os <<mat.data[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}






















};

