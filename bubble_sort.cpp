#include <iostream>
#include <algorithm>

void displayBars(int vet[]){
	for(int j=0;j<=9;j++){
		for(int i=0;i<vet[j];i++){ 
			std::cout << "|";
		}
		std::cout << "[" << vet[j] << "]" << std::endl; 
	}
	
	for (int i=0;i<=9;i++){
        std::cout << "\033[2J\033[1;1H" << std::endl;
    }
}


int main(){
	
	int i, j, vet[10];
	
	for(i=0;i<=9;i++){
		std::cout << "Digite o valor numero " << i+1 << ": ";
		std::cin >> vet[i];
	}
	
	displayBars(vet);
	std::cout << std::endl;
	
	for(j=0;j<=8;j++){
		for(i=0;i<=8;i++){
			if(vet[i]>vet[i+1]){
				std::swap(vet[i],vet[i+1]);
				
				displayBars(vet);
				
				std::cout << std::endl;
			}
		}
	}
	
	for(i=0;i<=9;i++){
		std::cout << "-NUMERO " << i+1 << ": " << vet[i] << std::endl;
	}
	
	return 0;
}
