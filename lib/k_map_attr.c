#include <k_map_attr.h>


/* initialize array representations of k_map */
int kMap[4][4] = {0};

/* initialize array representations of selected bits */
int kMapSelect[4][4] = {0};

void outputToKMap(int *output, int inputSize){

	switch(inputSize){
		case 2:
			inputOfTwo(output);
			break;
		case 3:
			inputOfThree(output);
			break;
		case 4:
			inputOfFour(output);
			break;
	}


}

void inputOfTwo(int *output){
	int width = 2, outputSize = 4, row = 0, col = 0;
	for (size_t i = 0; i < outputSize; i++){
		if (output[i]){
			kMap[i / width][i % width] = 1;
		}	
	}
}

void inputOfThree(int *output){
	int width = 4, outputSize = 8;
	for (size_t i = 0; i < outputSize; i++){
		if (output[i]){
			switch(i){
				case 2:
					kMap[0][3] = 1;
					break;
				case 3:
					kMap[0][2] = 1;
					break;
				case 6:
					kMap[1][3] = 1;
					break;
				case 7:
					kMap[1][2] = 1;
					break;
				default:
					kMap[i / width][i % width] = 1;
			}
		}
	}
}

void inputOfFour(int *output){
	int outputSize = 16;
	for (size_t i = 0; i < outputSize; i++){
		if (output[i]){
			switch(i){
				case 0:
					kMap[0][0] = 1;
					break;
				case 1:
					kMap[0][1] = 1;
					break;
				case 2:
					kMap[0][3] = 1;
					break;
				case 3:
					kMap[0][2] = 1;
					break;
				case 4:
					kMap[1][0] = 1;
					break;
				case 5:
					kMap[1][1] = 1;
					break;
				case 6:
					kMap[1][3] = 1;
					break;
				case 7:
					kMap[1][2] = 1;
					break;
				case 8:
					kMap[3][0] = 1;
					break;
				case 9:
					kMap[3][1] = 1;
					break;
				case 10:
					kMap[3][3] = 1;
					break;
				case 11:
					kMap[3][2] = 1;
					break;
				case 12:
					kMap[2][0] = 1;
					break;
				case 13:
					kMap[2][1] = 1;
					break;
				case 14:
					kMap[2][3] = 1;
					break;
				case 15:
					kMap[2][2] = 1;
			}
		}
	}
}

void printMap(int inputSize){
	/* Format kMap based on inputSize */
	switch(inputSize){

		case 2:	
			printf("%s", "2^2 K Map: \n");
			printf("%s", " _ _ _ _\n");
			for (size_t i = 0; i < 2; i++){
				printf("%s", "| ");
				for (size_t j = 0; j < 2; j++){
					printf("%d | ", kMap[i][j]);
				}
				puts("");
				printf("%s"," _ _ _ _\n");
			}
			break;
		case 3:
			printf("%s", "2^3 K Map: \n");
			printf("%s", " _ _ _ _ _ _ _ _\n");
			for (size_t i = 0; i < 2; i++){
				printf("%s", "| ");
				for (size_t j = 0; j < 4; j++){
					printf("%d | ", kMap[i][j]);
				}
				puts("");
				printf("%s", " _ _ _ _ _ _ _ _\n");
			}
			break;
		case 4:
			printf("%s", "2^4 K Map: \n");
			printf("%s", " _ _ _ _ _ _ _ _\n");
			for (size_t i = 0; i < 4; i++){
				printf("%s", "| ");
				for (size_t j = 0; j < 4; j++){
					printf("%d | ", kMap[i][j]);
				}
				puts("");
				printf("%s", " _ _ _ _ _ _ _ _ \n");
			}
			break;

	}
	puts("");
}
