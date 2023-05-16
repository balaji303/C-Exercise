/**
 * @file CalculateGrade.c
 * @author @balaji303 (https://github.com/balaji303)
 * @brief a program to find the grade of the student using entered 4 subject marks.
 * @version 1
 * @date 06-05-2023
 * 
 * Copyright (c) 2023 @balaji303
 * 
 */
#include <stdio.h>
#include <stdint.h>

#define MAX_MARK 400

int main(void)
{

    int englishMarks, mathsMarks, scienceMarks, socialMarks;
    float percentageOfStudent;
    int sumOfMarks;
    char studentGrade;

    printf("Enter English Marks:");
    scanf("%d",&englishMarks);
    printf("Enter Maths Marks:");
    scanf("%d",&mathsMarks);
    printf("Enter Science Marks:");
    scanf("%d",&scienceMarks);
    printf("Enter Social Marks:");
    scanf("%d",&socialMarks);

    sumOfMarks = englishMarks + mathsMarks + scienceMarks + socialMarks;
    
    percentageOfStudent =  (double)sumOfMarks /  (double)MAX_MARK;
    
    percentageOfStudent =  percentageOfStudent *100;

    printf("The Precentage of Student is %f\n",percentageOfStudent);

    if(percentageOfStudent > 95.0)
    {
        studentGrade = 'A';
    }

    else if(percentageOfStudent > 85.0)
    {
        studentGrade = 'B';
    }

    else if(percentageOfStudent > 65.0)
    {
        studentGrade = 'C';
    }

    else if(percentageOfStudent > 55.0)
    {
        studentGrade = 'D';
    }

    else if(percentageOfStudent > 40.0)
    {
        studentGrade = 'E';
    }

    else
    {
        studentGrade = 'F';
    }

    printf("The Grade of Student is %c",studentGrade);

    return 0;
}