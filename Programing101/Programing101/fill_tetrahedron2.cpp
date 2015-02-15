#include<iostream>

const int MAX_TETRAHEDRONS = 10;

//Calculate the number of tetrahedrons
int numberOfTetrahedrons(int arr[]){
	int number = 0;
	while (arr[number])
		number++;
	return number;
}

//Sort of tetrahedrons
void sorted_tetrahedrons(int arr[]){
	int numb = numberOfTetrahedrons(arr);
	for (int i = 0; i < numb; i++){
		int min = i;
		for (int j = i; j < numb; j++){
			if (arr[min] > arr[j]){
				int tmp = arr[min];
				arr[min] = arr[j];
				arr[j] = tmp;
				min = j;
			}
		}
	}
}

double fill_tetrahedron(const int num){
	int length = num;
	double volume = 0;

	volume = (sqrt(2)*pow(0.1*length, 3)) / 12;

	return volume;
}

int tetrahedron_filled(int arr[], int water){
	sorted_tetrahedrons(arr);
	int countTetrahedrons = 0;
	int i = 0;
	while (water > 0){
		water = water - fill_tetrahedron(arr[i]);
		if (water < 0)
			break;
		countTetrahedrons++;
		i++;
	}
	return countTetrahedrons;
}

int main(){
	int tetrahedrons[MAX_TETRAHEDRONS] = {100, 20, 30};
	int water = 10;
	std::cout << "The maximum number of tetrahedrons that can be field with hater liters of water is: "
		<< tetrahedron_filled(tetrahedrons, water) << std::endl;
	return 0;
}