#include <iostream>
#include <algorithm>
#include <windows.h>

void eraseLines(int n) {
    COORD pos = {0, 0};
    CONSOLE_SCREEN_BUFFER_INFO info;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get the console cursor position and buffer information
    GetConsoleScreenBufferInfo(hConsole, &info);

    // Calculate the position to start erasing from
    pos.Y = info.dwCursorPosition.Y - n + 1;
    if (pos.Y < 0) {
        pos.Y = 0;
    }

    // Set the cursor position to the starting position
    SetConsoleCursorPosition(hConsole, pos);

    // Erase the desired number of lines
    for (int i = 0; i < n; i++) {
        std::cout << std::string(info.dwMaximumWindowSize.X, ' ');
        SetConsoleCursorPosition(hConsole, pos);
        pos.Y++;
    }

    // Set the cursor position to the beginning of the first erased line
    pos.Y -= n;
    SetConsoleCursorPosition(hConsole, pos);
}

void displayBars(int vet[]){
	for(int j=0;j<=9;j++){
		for(int i=0;i<vet[j];i++){ 
			std::cout << "|";
		}
		std::cout << "[" << vet[j] << "]" << std::endl; 
	}
}


int main(){
	
	int i, j, vet[10];
	
	for(i=0;i<=9;i++){
		std::cout << "Digite o valor numero " << i+1 << ": ";
		std::cin >> vet[i];
	}
	
	std::cout << std::endl;
	
	std::cout << "Unsorted array:" << std::endl;
	displayBars(vet);
	
	std::cout << std::endl;
	
	std::cout << "Sorted array:" << std::endl;
	for(j=0;j<=8;j++){
		for(i=0;i<=8;i++){
			if(vet[i]>vet[i+1]){
				std::swap(vet[i],vet[i+1]);
				}
		}
		
		displayBars(vet);
				
		if(j<8){
			eraseLines(11);
		}
		
	}
	
	return 0;
	
}
