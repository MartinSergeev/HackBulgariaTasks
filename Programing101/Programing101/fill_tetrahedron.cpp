#include<iostream>

double fill_tetrahedron(const int num){
	int length = num;
	double volume = 0;
	
	volume = (sqrt(2)*pow(0.1*length,3))/12;
	
	return volume;
}

int main(){
	std::cout << "Enter the edge length of the regular tetrahedron in centimetres: ";
	int length;
	std::cin >> length;
	std::cout << "The amount of water that can be  filled in the tetrahedron is: " 
			  << fill_tetrahedron(length) << std::endl;
	return 0;
}