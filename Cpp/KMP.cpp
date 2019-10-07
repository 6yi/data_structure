#include<stdio.h>
#include<string.h>
#include <iostream>

void GetNext(string P, int next[])
{
    int p_len = P.size();
    int i = 0;   // P ╣доб╠Й
    int j = -1;  
    next[0] = -1;
    
    while (i < p_len - 1)
    {
        if (j == -1 || P[i] == P[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}



int main(){
	
} 
