/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class MyCustomDataStructure {
    
    private:
    int n;
    int* arr;
    int* st;
    public:
    
    int getMid(int s, int e) { return s + (e -s)/2; } 
    
    int constructSTUtil( int ss, int se, int si)  
    {  

        if (ss == se)  
        {  
            st[si] = arr[ss];  
    
            return arr[ss];  
        }  
  
  
        int mid = getMid(ss, se);  
        st[si] = constructSTUtil(ss, mid, si*2+1) +  
            constructSTUtil(mid+1, se, si*2+2);  
        return st[si];  
    }  
  
    MyCustomDataStructure(int* pArr ,int arraySize)
    {
        
        arr = pArr;    
        n = arraySize;
        
        st = new int[2*arraySize-1];
        
        constructSTUtil(0, n-1, 0); 
        
    };
    
    void addValueUtil(int ss, int se, int i, int diff, int si)  
    {  
        if (i < ss || i > se)  
            return;  
  
        st[si] = st[si] + diff;  
        if (se != ss)  
        {  
            int mid = getMid(ss, se);  
            addValueUtil(ss, mid, i, diff, 2*si + 1);  
            addValueUtil(mid+1, se, i, diff, 2*si + 2);  
        }  
    }  
    
    void addValue(int index,int valueToBeAdd)
    {
        // Check for erroneous input index  
        if (index < 0 || index > n-1)  
        {  
            cout<<"Invalid Input";  
            return;  
        }  
 
  
        // Update the value in array  
        arr[index] = arr[index] + valueToBeAdd;  
  
        // Update the values of nodes in segment tree  
        addValueUtil(0,n-1,index,valueToBeAdd,0);  
        
    }
    
    int getSumUtil(int ss, int se, int qs, int qe, int si)  
    {  

        if (qs <= ss && qe >= se)  
            return st[si];  
  
        if (se < qs || ss > qe)  
            return 0;  
  
        int mid = getMid(ss, se);  
        return getSumUtil(ss, mid, qs, qe, 2*si+1) +  
            getSumUtil(mid+1, se, qs, qe, 2*si+2);  
    }  
    
    int getSumBetweenRange(int qs,int qe)
    {
        if (qs < 0 || qe > n-1 || qs > qe)  
        {  
            cout<<"Invalid Input";  
            return -1;  
        }
        
  
        return getSumUtil(0, n-1, qs, qe, 0); 
        
    }
    
    void print()
    {
        cout << endl;
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
      
        printf("\n");  
        for(int i=0;i<2*n-1;i++)
        {
            cout << st[i] << " ";
        }
    }
    
    
};

int main()
{
    int n;
    
    cin >> n;
    
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        
        cin >> arr[i];
    }

    MyCustomDataStructure* pMyCustomDataStructure = new MyCustomDataStructure(arr,n);
   // pMyCustomDataStructure->print();
    
    // try some random addValue
    
    pMyCustomDataStructure->addValue(2,5);
    //pMyCustomDataStructure->print();
    // try some range sun
    
    cout << pMyCustomDataStructure->getSumBetweenRange(0,n-1);
    
    //pMyCustomDataStructure->print();
}

