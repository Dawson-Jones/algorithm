#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int str_len(char *str){
	int i=0;
	for (i; str[i] !='\0'; ++i)
		;
	return i;
}

int gcd(int a, int b){
	return b==0?a:gcd(b, a%b);
}

char * gcdOfStrings(char * str1, char * str2){
	char one_add_two[2002];
	char two_add_one[2002];
	strcpy(one_add_two, str1);
	strcat(one_add_two, str2);
	strcpy(two_add_one, str2);
	strcat(two_add_one, str1);
	for(int i=0;one_add_two[i]!='\0';i++)
		if (one_add_two[i]!=two_add_one[i])
			return "";

	int s1_len = str_len(str1);
	int s2_len = str_len(str2);
	int numOfMaxDivisor = gcd(s1_len, s2_len);
	str1[numOfMaxDivisor] = '\0';
	return str1;
}

int main(int argc, char const *argv[]){
	char *s1 = "ababab";
	char *s2 = "abab";
	char *res = gcdOfStrings(s1, s2);
	printf("%s\n", res);
	return 0;
}