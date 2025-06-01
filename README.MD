 WRITTEN BY:

 		Jourdan Rampoldi

 PROJECT:

		simplifyFunction "boolean function"


 DESCRIPTION: 
		
		The simplifyFunction program was written as a means to take a sum of min terms 
	functionand provide information in terms of a kmap, including displaying the map, 
	the groups found, and the most simplified function. 

	~The program is broken into four parts:

			1. Parse the string function provided by the user
		and assign the values in a 2 dimensional array, represented
		by the kMap. 

			2. The kMap will be used to identify Essential Prime Implicants
		by locating all groups associated around one bit in the kMap and 
		determining if only one group is present. The algorithm starts
		with the highest group to the lowest to ensure the lowest amount
		of possible groups with the highest amount of bits grouped.

			3. After EPI bits are found and bits selected in an additional 
		array, called kMapSelect, the locate groups algorithm starts over
		finding Prime Implicants. 

			4. Once all groups are located, the groups are processed and 
		a simplified function is generated and printed to the consol.


	~Additional information provided:

			1. kMap representation of what the user provided

			2. The groups identified. If two of the same are 
		presented, the first group will be EPI and the second
		will be PI.

 HOW TO USE:

		If simplifiedFunctions has not been build, simply run:
				
					chmod 755 runTest.sh
					./runTest.sh

	and it will be built for the user. Otherwise, simply run
	the make command to build the project. Once an executable 
	is produced, run the executable with the desired function
	as an argument to the script. 

 Arguments:

 		Functions must be in the form:

			"f(*DESIRED INPUTS*)=sum(*DESIRED OUTPUTS*)"

			or 

			"f(*DESIRED INPUTS*)=prod(*DESIRED OUTPUTS*)"

			where, *DESIRED INPUTS* is in the form

				x,y		OR 		x,y,z		OR		x,y,z

			and *DESIRED OUTPUTS* is in the form

				0,1,2,3			OR

				0,1,2,...,6,7	OR

				0,1,2,...,14,15

		~Important Note when entering in functions:

			The input terms are parsed by number of commas, 
		not by the number of individual terms provided. For example,
		if the user provides 3 commas, the program will expect 
		*DESIRED OUTPUT* between values of 0-15. If the user provedes 
		1 comma, the program will expect *DESIRED OUTPUT* to be between
		0-3. 

			The output values are expected to be seperated by commas as 
		well. 

 OUTPUT:

 		The output will come in the form:

			Running function: f(x,y,z,w)=sum(0,2,8,10)  
	
			2^4 K Map: 
			_ _ _ _ _ _ _ _
			| 1 | 0 | 0 | 1 | 
			_ _ _ _ _ _ _ _ 
			| 0 | 0 | 0 | 0 | 
			_ _ _ _ _ _ _ _ 
			| 0 | 0 | 0 | 0 | 
			_ _ _ _ _ _ _ _ 
			| 1 | 0 | 0 | 1 | 
			_ _ _ _ _ _ _ _ 

			Groups of 4 found: 
	
				(3,3) (0,0) (0,3) (3,0) 
	
			Simplified Function: b'd'

	where values produced from simplify function have the weight:

			2^4 K Map:

				a: 2^3
				b: 2^2
				c: 2^1
				d: 2^0

			2^3 K Map:

				a: 2^2
				b: 2^1
				c: 2^0

			2^2 K Map

				a: 2^1
				b: 2^0

	In other words, you output weights will be assigned alphabetically. 

	~To see examples, please run "chmod 755 runTest.sh; ./runTest.sh"
