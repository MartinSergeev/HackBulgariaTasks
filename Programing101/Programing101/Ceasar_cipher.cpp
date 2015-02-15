#include<iostream>

const int MAX_LEN = 100;

char* ceasar_encrypt(char* str, const int n){
	char* current = str;
	char alphaL[27] = "abcdefghijklmnopqrstuvwxyz";
	char alphaU[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; current[i] != '\0'; i++){
		if (current[i] >= 'a' && current[i] <= 'z'){
			int j = 0;
			while (current[i] != alphaL[j])
				j++;
			current[i] = alphaL[(j + n) % 26];
		}
		else if (current[i] >= 'A' && current[i] <= 'Z'){
			int j = 0;
			while (current[i] != alphaU[j])
				j++;
			current[i] = alphaU[(j + n) % 26];
		}
		else
			return 0;
	}
	return current;
}

int main(){
	char str[MAX_LEN] = "gGQWER";
	int n = 1;

	std::cout << ceasar_encrypt(str, n) << std::endl;
	return 0;
}