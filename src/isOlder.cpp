/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-')
		return -1;
	for (int i = 0; dob1[i] != '\0' || dob2[i] != '\0'; i++){
		if (dob1[i] - 48 > 10 || dob2[i] - 48 > 10)
			return -1;
	}
	int year1 = ((dob1[6] - 48) * 1000) + ((dob1[7] - 48) * 100) + ((dob1[8] - 48) * 10) + (dob1[9] - 48);
	int year2 = ((dob2[6] - 48) * 1000) + ((dob2[7] - 48) * 100) + ((dob2[8] - 48) * 10) + (dob2[9] - 48);
	int month1 = ((dob1[3] - 48) * 10) + (dob1[4] - 48);
	int month2 = ((dob2[3] - 48) * 10) + (dob2[4] - 48);
	int day1 = ((dob1[0] - 48) * 10) + (dob1[1] - 48);
	int day2 = ((dob2[0] - 48) * 10) + (dob2[1] - 48);
	if (month1 > 12 || month2 > 12)
		return -1;
	else if (day1 == 29 && month1 == 2){
		if (year1 % 400 != 0 && year1 % 4 != 0)
			return -1;
	}
	else if (day2 == 29 && month2 == 2){
		if (year2 % 400 != 0 && year2 % 4 != 0)
			return -1;
	}
	if (year1 > year2)
		return 2;
	else if (year2 > year1)
		return 1;
	else{
		if (month1 > month2)
			return 2;
		else if (month2 > month1)
			return 1;
		else{
			if (day1 > day2)
				return 2;
			else if (day2 > day1)
				return 1;
			else
				return 0;
		}
	}
}
