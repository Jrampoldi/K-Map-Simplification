#include <parse_function.h>

int getInputSize(const char *func_str){

	
	int size = 1;
	const char *currentChar = func_str;

	while (*currentChar != ')'){
		if (*currentChar == ','){size++;}
		currentChar++;
	}

	return size;

}

void getOutputValues(const char *func_str, int *outputs, size_t outputSize){

	char *isSum = strstr(func_str, "sum"); 


	const char *previousChar = func_str;
	const char *currentChar = func_str;

	if (isSum == NULL){
		for (size_t i = 0; i < outputSize; i++){
			outputs[i] = 1;
		}
	}

	while(*currentChar != '\0'){
		currentChar++;

		if (isdigit(*currentChar) && (!isdigit(*previousChar))){
			if (isSum == NULL){
				outputs[atoi(currentChar)] = 0;
			} else {
				outputs[atoi(currentChar)] = 1;
			}
		}

		previousChar++;
	}

}
