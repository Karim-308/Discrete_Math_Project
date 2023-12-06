
#include <iostream>

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


using namespace std;

int gcd (int x , int y ){
    if (( x%y)==0)
    return y;
    
    return gcd ( y, x%y);
}

int modInverse(int A, int M) 
{ 
    for (int X = 1; X < M; X++) {
        if ((A * X) % M == 1) 
            return X;
    }

    // If the loop completes without finding the inverse
    return -1;
} 

int main()
{
    /*cout<<gcd(7,26);*/
    
    
    int a ,b ;
    a= 7 , b= 2;
    
    
    string msg;
    cin>> msg;
    
    string deciphered;
    
    
    for (int i ; i<msg.length() ; i++)
    {
        for (int j = 0 ; j < 26 ; j++){
        if (msg[i]==alphabet[j])
        
            deciphered = deciphered + alphabet[ j % 26 +   modInverse(a, 26)  ] ;
        }
    }
    
    
    cout <<deciphered;
    
    
    

    return 0;
}
