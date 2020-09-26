/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int getDecimalFromBinary(int* binaryNumber,int size)
{
    int retVal = 0;
    for(int i=0;i<size;i++)
    {
        retVal = retVal+binaryNumber[size-i-1]*pow(2,i);
    }
 
    return retVal;
}

int getNthBinaryNumberWithKOnes(int k,int n)
{
    int binaryNumber[32];
    
    for(int i=0;i<32;i++)
        binaryNumber[i] = 0;
        
    for(int i=0;i<k;i++)
        binaryNumber[32-i-1] = 1;
     
    for(int i=1;i<n;i++)    
    {
        next_permutation(binaryNumber, binaryNumber +32);
    }
            
    return getDecimalFromBinary(binaryNumber,32);
    
}

int main()
{
    int n;
    int k;
    
    cin >> n;
    
    cin >> k;
    
    cout << getNthBinaryNumberWithKOnes(k,n);
    
}