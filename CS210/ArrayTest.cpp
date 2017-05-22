/*
 *  Date.h
 *  
 *
 *  Created by Noah Greer on 11/25/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int stuScores[3][4] = {{63,80,74,78},{81,99,87,78},{76,82,83,91}}
}

int maxGrade(const int& scores[3][4])
{
	int highest = 0;
	
	for (int r = 0; r < 4; r++) {		
		for (int i = 0; i < 3; i++){
			if ( highest < stuScores[r][i] )
				highest = stuScores[r][i];
		}
	}
}

int minGrade(const int& scores[3][4])
{
	int lowest = 0;
	
	for (int r = 0; r < 4; r++) {		
		for (int i = 0; i < 3; i++){
			if ( lowest > stuScores[r][i] )
				lowest = stuScores[r][i];
		}
	}
}

int averageGrade(const int& scores[3][4])
{
	int total;
	
	for (int r = 0; r < 4; r++) {		
		for (int i = 0; i < 3; i++){
			total += stuScores[r][i];
		}
	}
}