/*

Here is a program that does encryption and decryption (without key for simplicity)
(Messy code, i know, SORRY)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int betavalue(int beta)
{
    //printf("\nbeta value fn (%d) : ", beta);     //(hide)
    if(beta == 0)
    {
	    beta = 256;
	    //printf(" | beta=0, so beta=256 | ");       //(hide)
    }
	else if(beta < 0)
	{
	    //printf(" | beta<0 | ");       //(hide)
	    if(beta < -255)
	    {
	        beta = beta%(256);
	        //printf(" | beta<-255, so beta=beta%%256=%d | ", beta);       //(hide)
	        beta = betavalue(beta);
	    }
	    else
	    {
	        beta = 256 + beta;
	        //printf(" | 0>beta>-255, so beta=beta+256=%d | ", beta);       //(hide)
	    }
	}
	else if(beta > 256)
	{
	    beta = beta%256;
	    //printf(" | beta>256, so beta=beta%%256=%d | ", beta);       //(hide)
	    beta = betavalue(beta);
	}
	//printf(" return \n");       //(hide)
	return beta;
}



int main() {
    char arr[1000000];
    for(int j=0; j<1000000; j++)
    {
        arr[j] = '0';
    }
    //printf("Zero in whole arr(0 to 1000)\n");       //(hide)
    int what = 1;
    printf("Input the string : ");
    fflush(stdin);
	scanf("%[^\n]", arr);
	//printf("arr = ");         //(hide)
	/*
	for(int y=0; arr[y]!=0; y++)        //(hide)
	{                                   //(hide)
	    printf("%c ",arr[y]);           //(hide)
	}                                   //(hide)
	*/
	printf("\nChoose : \n1. Encryption\n2. Decryption\n");
	fflush(stdin);
	scanf("%d", &what);
	char alpha;
	int a, b, c, beta=0;
	int length = 0;
	if(what == 1)
	{
	    length = strlen(arr);
	    printf("Encrypted string is : ");
	}
	else
	{
	    length = (strlen(arr))/3; 
	    printf("Decrypted string is : ");
	}
	if(what == 1)
	{
	    //printf("\n Encrypting... ");          //(hide)
	for(int i=0; i<1000000 && arr[i]!=0; i++)
	{
	    alpha = arr[i];
	    beta = (int)alpha;
	    //printf("\nalpha = %c, beta = %d ", alpha, beta);          //(hide)
	    if(i%2 == 0)
	    a = 3;
	    else 
	    a = -7;
	    if(i%3 == 0)
	    b = 2;
	    else if(i%3 == 1)
	    b = -4;
	    else
	    b = 5;
	    if(i%2 == 0)
	    c = length-i;
	    else 
	    c = i-length;
	    //printf("\n a = %d, b = %d, c = %d,, sum = %d", a, b, c,a+b+c);          //(hide)
	    beta = beta + (a+b+c);
	    beta = betavalue(beta);
	    //printf("\n beta = %d\n", beta);          //(hide)
	    //arr[i] = (char)beta;
	    if(beta<10)
	    {
	        printf("00%d", beta);
	    }
	    else if(beta<100)
	    {
	        printf("0%d", beta);
	    }
	    else
	    {
	        printf("%d", beta);
	    }
	}
	}
	else 
	{
	    //printf("\n Decrypting... ");          //(hide)
	    for(int i=0; i<1000000 && arr[3*i]!='\0'; i++)
	    {
    	    alpha = arr[3*i];
    	    char alpha2 = arr[3*i+1];
    	    char alpha3 = arr[3*i+2];
    	    //printf("\nalpha = %c, alpha2 = %c, alpha3 = %c", alpha, alpha2, alpha3);          //(hide)
	        beta = (100*(((int)alpha)-48)) + (10*(((int)alpha2)-48)) + (((int)alpha3)-48);
	        //printf("\nBeta = %d", beta);          //(hide)
	        if(beta == 0)
	        break;
	        if(i%2 == 0)
    	    a = 3;
	        else 
	        a = -7;
    	    if(i%3 == 0)
	        b = 2;
	        else if(i%3 == 1)
    	    b = -4;
	        else
	        b = 5;
    	    if(i%2 == 0)
	        c = length-i;
	        else 
	        c = i-length;
    	    //printf("\n a = %d, b = %d, c = %d,, sum = %d", a, b, c,a+b+c);          //(hide)
    	    beta = beta - (a+b+c);
    	    //printf("\n beta = %d\n", beta);          //(hide)
	        beta = betavalue(beta);
	        //arr[i] = (char)beta;
	        printf("%c", (char)beta);
    	}   
	}
	
	/*
	if(what == 1)
	{
	    //printf("Encrypted string is : ");
	    for(int h=0; h<1000 && arr[h]!=0; h++)
	    {
	        printf("%c", &arr[h]);
	    }
	}
	else if(what == 2)
	{
	    //printf("Decrypted string is : ");
	    for(int h=0; h<1000 && arr[h]!=0; h++)
	    {
	        printf("%c", &arr[h]);
	    }
	}
	*/
	
	return 0;
}
