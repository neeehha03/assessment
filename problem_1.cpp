/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

void decToBinary(int n) 
{ 
    // array to store binary number 
    int binaryNum[32]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
} 

int getNextNumberWithSameBits(int n) {
    int a=n&-n, b=a+n;
    return b|(n^b)/a>>2;
  }
  
  
int getNthBinaryNumberWithKOnes(int k,int n)
{
    int startNum = pow(2,k)-1;
    
    for(int i=1;i<n;i++)    
    {
       // printf("number %d ",i);
      //  decToBinary(startNum);
    //    printf("\n");
        startNum = getNextNumberWithSameBits(startNum);
    }
            
    return startNum;
    
}

int main()
{
    int n;
    int k;
    
    cin >> n;
    
    cin >> k;
	
    cout << getNthBinaryNumberWithKOnes(k,n);
    
}