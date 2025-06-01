#include <find_bits.h>

/* default to searching for EPI */ 
char searchForEPI = 0x1;

void findSingleBits(GroupList* singleBits, int inputSize){
	int row = 0, col = 0;
	switch(inputSize){
		case 2:
			row = 2;
			col = 2;
			break;
		case 3:
			row = 2;
			col = 4;
			break;
		case 4:
			row = 4;
			col = 4;
			break;
		default:
			puts("ERROR: SEOMETHING WENT WRONG IN \"findSingleBits\" function\nWrong inputSize");
	}
	for (size_t i = 0; i < row; i++){
		for (size_t j = 0; j < col; j++){
			if (kMap[i][j] && !kMapSelect[i][j]){
				addPointToGroup(singleBits, i, j);
				if (!searchForEPI){
					kMapSelect[i][j] = 1;
				}
			}
		}
	}
}
void findGroupsOfTwo(GroupList* groupsOfTwo, int inputSize){
	int row = 0, col = 0;
	switch(inputSize){
		case 2:
			row = 2;
			col = 2;
			break;
		case 3:
			row = 2;
			col = 4;
			break;
		case 4:
			row = 4;
			col = 4;
			break;
		default:
			puts("ERROR: SOMETHING WENT WRONG IN \"findGroupsOfTwo\" function\nWrong inputSize");
	}

	/* Groups of two loop */
	for (size_t i = 0; i < row; i++){
		for (size_t j = 0; j < col; j++){
			if (kMap[i][j] && !kMapSelect[i][j]){
				/* Handle vertical groups */
				if (j < (col - 1)){
					if (kMap[i][j + 1]){
						addGroupOfTwo(groupsOfTwo, i, j, i, j + 1);
						if(!searchForEPI){
							kMapSelect[i][j] = 1;
							kMapSelect[i][j+1] = 1;	
						}
					}
				} else {
					if (kMap[i][0] && row > 2){
						addGroupOfTwo(groupsOfTwo, i, j, i, 0);
						if(!searchForEPI){ 
							kMapSelect[i][j] = 1;
							kMapSelect[i][0] = 1;
						}

					}
				}

				/* Handle horizontal groups */
				if (i < (row - 1)){
					if (kMap[i + 1][j]){
						addGroupOfTwo(groupsOfTwo, i, j, i + 1, j);
						if(!searchForEPI){ 
							kMapSelect[i][j] = 1; 
							kMapSelect[i + 1][j] = 1;
						}
					}
				} else {
					if (kMap[0][j] && col > 2){
						addGroupOfTwo(groupsOfTwo, i, j, 0, j);
						if(!searchForEPI){ 
							kMapSelect[i][j] = 1; 
							kMapSelect[0][j] = 1;
						}

					}
				}

				/* check previous squares */
				if (i > 0){
					if (kMap[i - 1][j]){
						addGroupOfTwo(groupsOfTwo, i, j, i - 1, j);
						if (!searchForEPI){
							kMapSelect[i][j] = 1;
							kMapSelect[i - 1][j] = 1;
						}
					}
				}
				if (j > 0){
					if (kMap[i][j - 1]){
						addGroupOfTwo(groupsOfTwo, i, j, i, j - 1);
						if (!searchForEPI){
							kMapSelect[i][j] = 1;
							kMapSelect[i][j - 1] = 1;
						}
					}
				}


				/* check square on opp side */
				if (i == 0 && row > 2){
					if(kMap[(row - 1)][j]){
						addGroupOfTwo(groupsOfTwo, i, j, (row - 1), j);
						if (!searchForEPI){
							kMapSelect[i][j] = 1;
							kMapSelect[(row - 1)][j] = 1;
						}
					}
				}
				if (j == 0 && col > 2){
					if (kMap[i][(col - 1)]){
						addGroupOfTwo(groupsOfTwo, i, j, i, (col - 1));
						if (!searchForEPI){
							kMapSelect[i][j] = 1;
							kMapSelect[i][(col - 1)] = 1;
						}
					}
				}
			}
		}
	}
}

void findGroupsOfFour(GroupList* groupsOfFour, int inputSize){
	int row = 0, col = 0;
	switch(inputSize){
		case 3:
			row = 2; 
			col = 4;
			break;
		case 4:
			row = 4;
			col = 4;
			break;
		default:
			puts("ERROR: SOMETHING WENT WRONG IN \"findGroupsOfFour\" function\nWrong inputSize");
	}
	for (size_t i = 0; i < row; i++){
		for (size_t j = 0; j < col; j++){
			if (kMap[i][j] && !kMapSelect[i][j]){
				/* check four surrounding squares */
				if (i < (row - 1) && j < (col - 1)){
					if (kMap[i + 1][j] && kMap[i][j + 1] && kMap[i + 1][j + 1]){
						addGroupOfFour(groupsOfFour, i, j, i + 1, j,
											i, j + 1, i + 1, j + 1);
						if(!searchForEPI){ 
							kMapSelect[i][j] = 1;
							kMapSelect[i + 1][j] = 1;
							kMapSelect[i][j + 1] = 1;
							kMapSelect[i + 1][j + 1] = 1;
						}

					}
				} else if (i < (row - 1) && j == (col - 1)){
					if (kMap[i + 1][j] && kMap[i][j - 1] && kMap[i + 1][j - 1]){
						addGroupOfFour(groupsOfFour, i, j, i + 1, j,
											i, j - 1, i + 1, j - 1);
						if(!searchForEPI){ 
							kMapSelect[i][j] = 1; 
							kMapSelect[i + 1][j] = 1;
							kMapSelect[i][j - 1] = 1;
							kMapSelect[i + 1][j - 1] = 1;
						}

					}

				} else if (i == (row - 1) && j < (col - 1)){
					if (kMap[i][j + 1] && kMap[i - 1][j] && kMap[i - 1][j + 1]){
						addGroupOfFour(groupsOfFour, i, j, i, j + 1, i - 1, j,
											i - 1, j + 1);
						if(!searchForEPI){ 
							kMapSelect[i][j] = 1; 
							kMapSelect[i][j + 1] = 1;
							kMapSelect[i - 1][j] = 1;
							kMapSelect[i - 1][j + 1] = 1;
						}
					}
				} 
	
				/* backwards check */
				if (i > 0 && j > 0){
					if (kMap[i - 1][j] && kMap[i][j - 1] && kMap[i - 1][j - 1]){
						addGroupOfFour(groupsOfFour, i, j, i - 1, j, i, j - 1,
											i - 1, j - 1);
						if (!searchForEPI){ 
							kMapSelect[i][j] = 1; 
							kMapSelect[i - 1][j] = 1;
							kMapSelect[i][j - 1] = 1;
							kMapSelect[i - 1][j - 1] = 1;
						}
					}
				}

				/* opposite side (vertical groups) */
				if (i < (row - 1)){
					if (j == 0){
						if (kMap[i + 1][j] && kMap[i][3] && kMap[i + 1][3]){
							addGroupOfFour(groupsOfFour, i, j, i + 1, 0,
												i, 3, i + 1, 3);
							if (!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[i + 1][j] = 1;
								kMapSelect[i][3] = 1;
								kMapSelect[i + 1][3] = 1;
							}
						}
					} else if (j == 3){
						if (kMap[i + 1][j] && kMap[i][0] && kMap[i + 1][0]){
							addGroupOfFour(groupsOfFour, i, j, i + 1, j, 
												i, 0, i + 1, 0);
							if (!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[i + 1][j] = 1;
								kMapSelect[i][0] = 1;
								kMapSelect[i + 1][0] = 1;
							}
						}
					}
				} else {
					if (j == 0){
						if (kMap[i - 1][j] && kMap[i - 1][3] && kMap[i - 1][3]){
							addGroupOfFour(groupsOfFour, i, j, i - 1, j,
												i, 3, i - 1, 3);
							if (!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[i - 1][j] = 1;
								kMapSelect[i][3] = 1;
								kMapSelect[i - 1][3] = 1;
							}
						}
					} else if (j == 3){
						if (kMap[i - 1][j] && kMap[i][0] && kMap[i - 1][0]){
							addGroupOfFour(groupsOfFour, i, j, i - 1, j, 
												i, 0, i - 1, 0);
							if (!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[i - 1][j] = 1;
								kMapSelect[i][0] = 1;
								kMapSelect[i - 1][0] = 1;
							}
						}
					}
				}

				/* opposite side (horizontal groups) */
				if (j < (col - 1)){
					if (i == 0){
						if (kMap[i][j + 1] && kMap[3][j] && kMap[3][j + 1]){
							addGroupOfFour(groupsOfFour, i, j, i, j + 1,
												3, j, 3, j + 1);
							if (!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[i][j + 1] = 1;
								kMapSelect[3][j] = 1;
								kMapSelect[3][j + 1] = 1;
							}
						}
					} else if (i == 3){
						if (kMap[i][j + 1] && kMap[0][j] && kMap[0][j + 1]){
							addGroupOfFour(groupsOfFour, i, j, i, j + 1,
												0, j, 0, j + 1);
							if (!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[i][j + 1] = 1;
								kMapSelect[0][j] = 1;
								kMapSelect[0][j + 1] = 1;
							}
						}
					}
				} else {
					if (i == 0){
						if (kMap[i][j - 1] && kMap[3][j] && kMap[3][j - 1]){
							addGroupOfFour(groupsOfFour, i, j, i, j - 1,
												3, j, 3, j - 1);
						}
						if (!searchForEPI){
							kMapSelect[i][j] = 1;
							kMapSelect[i][j - 1] = 1;
							kMapSelect[3][j] = 1;
							kMapSelect[3][j - 1] = 1;
						}

					} else if(i == 3){
						if (kMap[i][j - 1] && kMap[0][j] && kMap[0][j - 1]){
							addGroupOfFour(groupsOfFour, i, j, i, j - 1,
												0, j, 0, j - 1);
						}
						if (!searchForEPI){
							kMapSelect[i][j] = 1;
							kMapSelect[i][j - 1] = 1;
							kMapSelect[0][j] = 1;
							kMapSelect[0][j - 1] = 1;
						}

					}
				}

				/* Four in a row  */
				if (i == 0){
					if (kMap[1][j] && kMap[2][j] && kMap[3][j]){
						addGroupOfFour(groupsOfFour, i, j, 1, j, 2, j, 3, j);
						if(!searchForEPI){ 
							kMapSelect[i][j] = 1; 
							kMapSelect[1][j] = 1;
							kMapSelect[2][j] = 1;
							kMapSelect[3][j] = 1;
						}
					}
				}
				if (i == 1){
					if (kMap[0][j] && kMap[2][j] && kMap[3][j]){
						addGroupOfFour(groupsOfFour, i, j, 0, j, 2, j, 3, j);
						if(!searchForEPI){ 
							kMapSelect[i][j] = 1;
							kMapSelect[0][j] = 1;
							kMapSelect[2][j] = 1;
							kMapSelect[3][j] = 1;
						}	
					}
				}
				if (i == 2){
					if (kMap[0][j] && kMap[1][j] && kMap[3][j]){
						addGroupOfFour(groupsOfFour, i, j, 0, j, 1, j, 3, j);
						if(!searchForEPI){
							kMapSelect[i][j] = 1; 
							kMapSelect[0][j] = 1;
							kMapSelect[1][j] = 1;
							kMapSelect[3][j] = 1;
						}
					}
				}
				if (i == 3){
					if (kMap[0][j] && kMap[1][j] && kMap[2][j]){
						addGroupOfFour(groupsOfFour, i, j, 0, j, 1, j, 2, j);
						if(!searchForEPI){
							kMapSelect[i][j] = 1; 
							kMapSelect[0][j] = 1;
							kMapSelect[1][j] = 1;
							kMapSelect[2][j] = 1;
						}
					}
				}
				/* Four in a col */
				if (j == 0){
					if (kMap[i][1] && kMap[i][2] && kMap[i][3]){
						addGroupOfFour(groupsOfFour, i, j, i, 1, i, 2, i, 3);
						if(!searchForEPI){
							kMapSelect[i][j] = 1;
							kMapSelect[i][1] = 1;
							kMapSelect[i][2] = 1;
							kMapSelect[i][3] = 1;
						}
					}
				}
				if (j == 1){
					if (kMap[i][0] && kMap[i][2] && kMap[i][3]){
						addGroupOfFour(groupsOfFour, i, j, i, 0, i, 2, i, 3);
						if(!searchForEPI){
							kMapSelect[i][j] = 1;
							kMapSelect[i][0] = 1;
							kMapSelect[i][2] = 1;
							kMapSelect[i][3] = 1;
						}
					}
				}
				if (j == 2){
					if (kMap[i][0] && kMap[i][1] && kMap[i][3]){
						addGroupOfFour(groupsOfFour, i, j, i, 0, i, 1, i, 3);
						if(!searchForEPI){
							kMapSelect[i][j] = 1; 
							kMapSelect[i][0] = 1;
							kMapSelect[i][1] = 1;
							kMapSelect[i][3] = 1;
						}
					}
				}
				if (j == 3){
					if (kMap[i][0] && kMap[i][1] && kMap[i][2]){
						addGroupOfFour(groupsOfFour, i, j, i, 0, i, 1, i, 2);
						if(!searchForEPI){
							kMapSelect[i][j] = 1;
							kMapSelect[i][0] = 1;
							kMapSelect[i][1] = 1;
							kMapSelect[i][2] = 1;
						}
					}
				}
				/* Four corners in 2^4 kMap */
				if (row == 4){
					if (i == 0 && j == 0){
						if (kMap[0][3] && kMap[3][0] && kMap[3][3]){
							addGroupOfFour(groupsOfFour, i, j, 0, 3, 3, 0, 3, 3);
							if(!searchForEPI){ 
								kMapSelect[i][j] = 1; 
								kMapSelect[0][3] = 1;
								kMapSelect[3][0] = 1;
								kMapSelect[3][3] = 1;
							}
						}
					}
					if (i == 0 && j == 3){
						if (kMap[0][0] && kMap[3][0] && kMap[3][3]){
							addGroupOfFour(groupsOfFour, i, j, 0, 0, 3, 0, 3, 3);
							if(!searchForEPI){ 
								kMapSelect[i][j] = 1; 
								kMapSelect[0][0] = 1;
								kMapSelect[3][0] = 1;
								kMapSelect[3][3] = 1;
							}
						}
					}
					if (i == 3 && j == 0){
						if (kMap[0][0] && kMap[0][3] && kMap[3][3]){
							addGroupOfFour(groupsOfFour, i, j, 0, 0, 0, 3, 3, 3);
							if(!searchForEPI){ 
								kMapSelect[i][j] = 1;
								kMapSelect[0][0] = 1;
								kMapSelect[0][3] = 1;
								kMapSelect[3][3] = 1;
							}
						}
					}
					if (i == 3 && j == 3){
						if (kMap[0][0] && kMap[0][3] && kMap[3][0]){
							addGroupOfFour(groupsOfFour, i, j, 0, 0, 0, 3, 3, 0);
							if(!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[0][0] = 1;
								kMapSelect[0][3] = 1;
								kMapSelect[3][0] = 1;
							}
						}
					}
				}
			}
		}
	}
}

void findGroupsOfEight(GroupList* groupsOfEight){
	int row = 4, col = 4;
	for (size_t i = 0; i < row; i++){
		for (size_t j = 0; j < col; j++){
			if (kMap[i][j] && !kMapSelect[i][j]){
				/* Vertical Groups */
				if (j < 3){
					if (i == 0){
						if (kMap[1][j] && kMap[2][j] && kMap[3][j] && kMap[0][j + 1]
							&& kMap[1][j + 1] && kMap[2][j + 1] && kMap[3][j + 1]){
							addGroupOfEight(groupsOfEight, i, j, 1, j, 2, j, 3, j, 
												0, j + 1, 1, j + 1, 2, j + 1, 3, j + 1);
							if (!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[1][j] = 1;
								kMapSelect[2][j] = 1;
								kMapSelect[3][j] = 1;
								kMapSelect[0][j + 1] = 1;
								kMapSelect[1][j + 1] = 1;
								kMapSelect[2][j + 1] = 1;
								kMapSelect[3][j + 1] = 1;
							}
						}
					} else if (i == 1) {
						if (kMap[0][j] && kMap[2][j] && kMap[3][j] && kMap[0][j + 1]
							&& kMap[1][j + 1] && kMap[2][j + 1] && kMap[3][j + 1]){
							addGroupOfEight(groupsOfEight, i, j, 0, j, 2, j, 3, j, 
												0, j + 1, 1, j + 1, 2, j + 1, 3, j + 1);
							if (!searchForEPI){
								kMapSelect[0][j] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[2][j] = 1;
								kMapSelect[3][j] = 1;
								kMapSelect[0][j + 1] = 1;
								kMapSelect[1][j + 1] = 1;
								kMapSelect[2][j + 1] = 1;
								kMapSelect[3][j + 1] = 1;
							}
						}
					} else if (i == 2) {
						if (kMap[0][j] && kMap[1][j] && kMap[3][j] && kMap[0][j + 1]
							&& kMap[1][j + 1] && kMap[2][j + 1] && kMap[3][j + 1]){
							addGroupOfEight(groupsOfEight, i, j, 0, j, 1, j, 3, j,
												0, j + 1, 1, j + 1, 2, j + 1, 3, j + 1);
							if (!searchForEPI){
								kMapSelect[0][j] = 1;
								kMapSelect[1][j] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[3][j] = 1;
								kMapSelect[0][j + 1] = 1;
								kMapSelect[1][j + 1] = 1;
								kMapSelect[2][j + 1] = 1;
								kMapSelect[3][j + 1] = 1;
							}
						}
					} else {
						if (kMap[0][j] && kMap[1][j] && kMap[2][j] && kMap[0][j + 1]
							&& kMap[1][j + 1] && kMap[2][j + 1] && kMap[3][j + 1]){
							addGroupOfEight(groupsOfEight, i, j, 0, j, 1, j, 2, j,
												0, j + 1, 1, j + 1, 2, j + 1, 3, j + 1);
							if (!searchForEPI){
								kMapSelect[0][j] = 1;
								kMapSelect[1][j] = 1;
								kMapSelect[2][j] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[0][j + 1] = 1;
								kMapSelect[1][j + 1] = 1;
								kMapSelect[2][j + 1] = 1;
								kMapSelect[3][j + 1] = 1;
							}
						}
					}
				}
				/* Vertical starting on left */
				if (j == 0){
					if (i == 0){
						if (kMap[1][0] && kMap[2][0] && kMap[3][0] && kMap[0][3]
							&& kMap[1][3] && kMap[2][3] && kMap[3][3]){
							addGroupOfEight(groupsOfEight, i, j, 1, 0, 2, 0, 3, 0,
												0, 3, 1, 3, 2, 3, 3, 3);
							if (!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[1][0] = 1;
								kMapSelect[2][0] = 1;
								kMapSelect[3][0] = 1;
								kMapSelect[0][3] = 1;
								kMapSelect[1][3] = 1;
								kMapSelect[2][3] = 1;
								kMapSelect[3][3] = 1;
							}
						}
					} else if (i == 1) {
						if (kMap[0][0] && kMap[2][0] && kMap[3][0] && kMap[0][3]
							&& kMap[1][3] && kMap[2][3] && kMap[3][3]){
							addGroupOfEight(groupsOfEight, i, j, 0, 0, 2, 0, 3, 0,
												0, 3, 1, 3, 2, 3, 3, 3);
							if (!searchForEPI){
								kMapSelect[0][0] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[2][0] = 1;
								kMapSelect[3][0] = 1;
								kMapSelect[0][3] = 1;
								kMapSelect[1][3] = 1;
								kMapSelect[2][3] = 1;
								kMapSelect[3][3] = 1;
							}
						}
					} else if (i == 2) {
						if (kMap[0][0] && kMap[1][0] && kMap[3][0] && kMap[0][3]
							&& kMap[1][3] && kMap[2][3] && kMap[3][3]){
							addGroupOfEight(groupsOfEight, i, j, 0, 0, 1, 0, 3, 0,
												0, 3, 1, 3, 2, 3, 3, 3);
							if (!searchForEPI){
								kMapSelect[0][0] = 1;
								kMapSelect[1][0] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[3][0] = 1;
								kMapSelect[0][3] = 1;
								kMapSelect[1][3] = 1;
								kMapSelect[2][3] = 1;
								kMapSelect[3][3] = 1;
							}
						}
					} else {
						if (kMap[0][0] && kMap[1][0] && kMap[2][0] && kMap[0][3]
							&& kMap[1][3] && kMap[2][3] && kMap[3][3]){
							addGroupOfEight(groupsOfEight, i, j, 0, 0, 1, 0, 2, 0,
												0, 3, 1, 3, 2, 3, 3, 3);
							if (!searchForEPI){
								kMapSelect[0][0] = 1;
								kMapSelect[1][0] = 1;
								kMapSelect[2][0] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[0][3] = 1;
								kMapSelect[1][3] = 1;
								kMapSelect[2][3] = 1;
								kMapSelect[3][3] = 1;
							}
						}
					}
				}
				/* Vertical starting on right*/
				if (j == 3){
					if (i == 0){
						if (kMap[1][3] && kMap[2][3] && kMap[3][3] && kMap[0][0]
							&& kMap[1][0] && kMap[2][0] && kMap[3][0]){
							addGroupOfEight(groupsOfEight, i, j, 1, 3, 2, 3, 3, 3,
												0, 0, 1, 0, 2, 0, 3, 0);
							if (!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[1][3] = 1;
								kMapSelect[2][3] = 1;
								kMapSelect[3][3] = 1;
								kMapSelect[0][0] = 1;
								kMapSelect[1][0] = 1;
								kMapSelect[2][0] = 1;
								kMapSelect[3][0] = 1;
							}
						}
					} else if (i == 1) {
						if (kMap[0][3] && kMap[2][3] && kMap[3][3] && kMap[0][0]
							&& kMap[1][0] && kMap[2][0] && kMap[3][0]){
							addGroupOfEight(groupsOfEight, i, j, 0, 3, 2, 3, 3, 3,
												0, 0, 1, 0, 2, 0, 3, 0);
							if (!searchForEPI){
								kMapSelect[0][3] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[2][3] = 1;
								kMapSelect[3][3] = 1;
								kMapSelect[0][0] = 1;
								kMapSelect[1][0] = 1;
								kMapSelect[2][0] = 1;
								kMapSelect[3][0] = 1;
							}
						}
					} else if (i == 2) {
						if (kMap[0][3] && kMap[1][3] && kMap[3][3] && kMap[0][0]
							&& kMap[1][0] && kMap[2][0] && kMap[3][0]){
							addGroupOfEight(groupsOfEight, i, j, 0, 3, 1, 3, 3, 3,
												0, 0, 1, 0, 2, 0, 3, 0);
							if (!searchForEPI){
								kMapSelect[0][3] = 1;
								kMapSelect[1][3] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[3][3] = 1;
								kMapSelect[0][0] = 1;
								kMapSelect[1][0] = 1;
								kMapSelect[2][0] = 1;
								kMapSelect[3][0] = 1;
							}
						}
					} else {
						if (kMap[0][3] && kMap[1][3] && kMap[2][3] && kMap[0][0]
							&& kMap[1][0] && kMap[2][0] && kMap[3][0]){
							addGroupOfEight(groupsOfEight, i, j, 0, 3, 1, 3, 2, 3,
												0, 0, 1, 0, 2, 0, 3, 0);
							if (!searchForEPI){
								kMapSelect[0][3] = 1;
								kMapSelect[1][3] = 1;
								kMapSelect[2][3] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[0][0] = 1;
								kMapSelect[1][0] = 1;
								kMapSelect[2][0] = 1;
								kMapSelect[3][0] = 1;
							}
						}
					}
				}
				/* Horizontal Groups */
				if (i < 3){
					if (j == 0){
						if (kMap[i][1] && kMap[i][2] && kMap[i][3] && kMap[i + 1][0]
							&& kMap[i + 1][1] && kMap[i + 1][2] && kMap[i + 1][3]){
							addGroupOfEight(groupsOfEight, i, j, i, 1, i, 2, i, 3,
												i + 1, 0, i + 1, 1, i + 1, 2, i + 1, 3);
							if (!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[i][1] = 1;
								kMapSelect[i][2] = 1;
								kMapSelect[i][3] = 1;
								kMapSelect[i + 1][j] = 1;
								kMapSelect[i + 1][1] = 1;
								kMapSelect[i + 1][2] = 1;
								kMapSelect[i + 1][3] = 1;
							}
						}
					} else if (j == 1) {
						if (kMap[i][0] && kMap[i][2] && kMap[i][3] && kMap[i + 1][0]
							&& kMap[i + 1][1] && kMap[i + 1][2] && kMap[i + 1][3]){
							addGroupOfEight(groupsOfEight, i, j, i, 0, i, 2, i, 3,
												i + 1, 0, i + 1, 1, i + 1, 2, i + 1, 3);
							if (!searchForEPI){
								kMapSelect[i][0] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[i][2] = 1;
								kMapSelect[i][3] = 1;
								kMapSelect[i + 1][0] = 1;
								kMapSelect[i + 1][j] = 1;
								kMapSelect[i + 1][2] = 1;
								kMapSelect[i + 1][3] = 1;
							}
						}
					} else if (j == 2) {
						if (kMap[i][0] && kMap[i][1] && kMap[i][3] && kMap[i + 1][0]
							&& kMap[i + 1][1] && kMap[i + 1][2] && kMap[i + 1][3]){
							addGroupOfEight(groupsOfEight, i, j, i, 0, i, 1, i, 3,
												i + 1, 0, i + 1, 1, i + 1, 2, i + 1, 3);
							if (!searchForEPI){
								kMapSelect[i][0] = 1;
								kMapSelect[i][1] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[i][3] = 1;
								kMapSelect[i + 1][0] = 1;
								kMapSelect[i + 1][1] = 1;
								kMapSelect[i + 1][j] = 1;
								kMapSelect[i + 1][3] = 1;
							}
						}
					} else {
						if (kMap[i][0] && kMap[i][1] && kMap[i][2] && kMap[i + 1][0]
							&& kMap[i + 1][1] && kMap[i + 1][2] && kMap[i + 1][3]){
							addGroupOfEight(groupsOfEight, i, j, i, 0, i, 1, i, 2,
												i + 1, 0, i + 1, 1, i + 1, 2, i + 1, 3);
							if (!searchForEPI){
								kMapSelect[i][0] = 1;
								kMapSelect[i][1] = 1;
								kMapSelect[i][2] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[i + 1][0] = 1;
								kMapSelect[i + 1][1] = 1;
								kMapSelect[i + 1][2] = 1;
								kMapSelect[i + 1][j] = 1;
							}
						}
					}
				}
				/* Horizontal starting on top */
				if (i == 0){
					if (j == 0){
						if (kMap[0][1] && kMap[0][2] && kMap[0][3] && kMap[3][0]
							&& kMap[3][1] && kMap[3][2] && kMap[3][3]){
							addGroupOfEight(groupsOfEight, i, j, 0, 1, 0, 2, 0, 3,
												3, 0, 3, 1, 3, 2, 3, 3);
							if (!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[0][1] = 1;
								kMapSelect[0][2] = 1;
								kMapSelect[0][3] = 1;
								kMapSelect[3][0] = 1;
								kMapSelect[3][1] = 1;
								kMapSelect[3][2] = 1;
								kMapSelect[3][3] = 1;
							}
						}
					} else if (j == 1) {
						if (kMap[0][0] && kMap[0][2] && kMap[0][3] && kMap[3][0]
							&& kMap[3][1] && kMap[3][2] && kMap[3][3]){
							addGroupOfEight(groupsOfEight, i, j, 0, 0, 0, 2, 0, 3,
												3, 0, 3, 1, 3, 2, 3, 3);
							if (!searchForEPI){
								kMapSelect[0][0] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[0][2] = 1;
								kMapSelect[0][3] = 1;
								kMapSelect[3][0] = 1;
								kMapSelect[3][1] = 1;
								kMapSelect[3][2] = 1;
								kMapSelect[3][3] = 1;
							}
						}
					} else if (j == 2) {
						if (kMap[0][0] && kMap[0][1] && kMap[0][3] && kMap[3][0]
							&& kMap[3][1] && kMap[3][2] && kMap[3][3]){
							addGroupOfEight(groupsOfEight, i, j, 0, 0, 0, 1, 0, 3,
												3, 0, 3, 1, 3, 2, 3, 3);
							if (!searchForEPI){
								kMapSelect[0][0] = 1;
								kMapSelect[0][1] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[0][3] = 1;
								kMapSelect[3][0] = 1;
								kMapSelect[3][1] = 1;
								kMapSelect[3][2] = 1;
								kMapSelect[3][3] = 1;
							}
						}
					} else {
						if (kMap[0][0] && kMap[0][1] && kMap[0][2] && kMap[3][0]
							&& kMap[3][1] && kMap[3][2] && kMap[3][3]){
							addGroupOfEight(groupsOfEight, i, j, 0, 0, 0, 1, 0, 2,
												3, 0, 3, 1, 3, 2, 3, 3);
							if (!searchForEPI){
								kMapSelect[0][0] = 1;
								kMapSelect[0][1] = 1;
								kMapSelect[0][2] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[3][0] = 1;
								kMapSelect[3][1] = 1;
								kMapSelect[3][2] = 1;
								kMapSelect[3][3] = 1;
							}
						}
					}
				}
				/* Horizontal starting on bottom */
				if (i == 3){
					if (j == 0){
						if (kMap[3][1] && kMap[3][2] && kMap[3][3] && kMap[0][0]
							&& kMap[0][1] && kMap[0][2] && kMap[0][3]){
							addGroupOfEight(groupsOfEight, i, j, 3, 1, 3, 2, 3, 3,
												0, 0, 1, 0, 2, 0, 3, 0);
							if (!searchForEPI){
								kMapSelect[i][j] = 1;
								kMapSelect[3][1] = 1;
								kMapSelect[3][2] = 1;
								kMapSelect[3][3] = 1;
								kMapSelect[0][0] = 1;
								kMapSelect[0][1] = 1;
								kMapSelect[0][2] = 1;
								kMapSelect[0][3] = 1;
							}
						}
					} else if (j == 1) {
						if (kMap[3][0] && kMap[3][2] && kMap[3][3] && kMap[0][0]
							&& kMap[0][1] && kMap[0][2] && kMap[0][3]){
							addGroupOfEight(groupsOfEight, i, j, 3, 0, 3, 2, 3, 3,
												0, 0, 1, 0, 2, 0, 3, 0);
							if (!searchForEPI){
								kMapSelect[3][0] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[3][2] = 1;
								kMapSelect[3][3] = 1;
								kMapSelect[0][0] = 1;
								kMapSelect[0][1] = 1;
								kMapSelect[0][2] = 1;
								kMapSelect[0][3] = 1;
							}
						}
					} else if (j == 2) {
						if (kMap[3][0] && kMap[3][1] && kMap[3][3] && kMap[0][0]
							&& kMap[0][1] && kMap[0][2] && kMap[0][3]){
							addGroupOfEight(groupsOfEight, i, j, 3, 0, 3, 1, 3, 3,
												0, 0, 1, 0, 2, 0, 3, 0);
							if (!searchForEPI){
								kMapSelect[3][0] = 1;
								kMapSelect[3][1] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[3][3] = 1;
								kMapSelect[0][0] = 1;
								kMapSelect[0][1] = 1;
								kMapSelect[0][2] = 1;
								kMapSelect[0][3] = 1;
							}
						}
					} else {
						if (kMap[3][0] && kMap[3][1] && kMap[3][2] && kMap[0][0]
							&& kMap[0][1] && kMap[0][2] && kMap[0][3]){
							addGroupOfEight(groupsOfEight, i, j, 3, 0, 3, 1, 3, 2,
												0, 0, 1, 0, 2, 0, 3, 0);
							if (!searchForEPI){
								kMapSelect[3][0] = 1;
								kMapSelect[3][1] = 1;
								kMapSelect[3][2] = 1;
								kMapSelect[i][j] = 1;
								kMapSelect[0][0] = 1;
								kMapSelect[0][1] = 1;
								kMapSelect[0][2] = 1;
								kMapSelect[0][3] = 1;
							}
						}
					}
				}
			}
		}

	}
}

void selectEPIBits(GroupList *myGroup){
	if (myGroup->head == NULL){
		/* No EPIs in List */
		return;
	} else {
		LinkedNode *currentNode = myGroup->head;
		LinkedList *currentList = currentNode->list;
		Node *point = currentList->head;
		while (currentNode != NULL){
			currentList = currentNode->list;
			point = currentList->head;
			while (point != NULL){
				kMapSelect[point->data[0]][point->data[1]] = 1;
				point = point->next;
			}
			currentNode = currentNode->nextList;
		}
	}
}
void locateEPI(GroupList *EPIGroups, GroupList *testGroups){
	/* Init comparison variables */
	LinkedNode *targetListNode = testGroups->head;
	LinkedNode *compareListNode = targetListNode;
	int x1, y1, x2, y2;

	/* default to true */
	char isEPI = 0x1;

	while (targetListNode != NULL){

		compareListNode = testGroups->head;
		x1 = targetListNode->list->head->data[0];
		y1 = targetListNode->list->head->data[1];

		while (compareListNode != NULL){

			x2 = compareListNode->list->head->data[0];
			y2 = compareListNode->list->head->data[1];
			if (targetListNode != compareListNode &&
					x1 == x2 && y1 == y2){
				isEPI = 0x0;
				break;
			}

			compareListNode = compareListNode->nextList;
		}

		if (isEPI){
			addListToGroup(EPIGroups, targetListNode->list);
		}
		targetListNode = targetListNode->nextList;
		isEPI = 0x1;
	}
	if (EPIGroups->size > 0){
		removeDoubles(EPIGroups);
		selectEPIBits(EPIGroups);
	}
	if (testGroups->size > 0){
		emptyGroup(testGroups);
	}
}
void removeDoubles(GroupList * EPIGroups){
	LinkedNode *tempHold = EPIGroups->head;
	LinkedNode *testList = tempHold;
	LinkedNode *compareList = testList;

	int test_x, test_y;

	while(testList != NULL){

		compareList = testList->nextList;
		test_x = testList->list->head->data[0];
		test_y = testList->list->head->data[1];

		while(compareList != NULL){
			if(isInList(compareList->list, test_x, test_y)){
				tempHold = testList->nextList;
				deleteListFromGroup(EPIGroups, testList);
				testList = NULL;
				break;
			}
			compareList = compareList->nextList;

		}

		if (testList == NULL){
			testList = tempHold;
		} else {
			testList = testList->nextList;
		}
	}
}

