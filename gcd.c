#include <stdio.h>
#include <string.h>

// Function declaration
void calculate(int matrix[][3], int *gcd, int *topNum1, int *topNum2);

// Function to update the matrix
void updateMatrix() {
    // Implementation
}

// Function to print a matrix
void printMatrix(int matrix[][3], int *gcd, int *topNum1, int *topNum2) {
    printf("\nYour new matrix is: \n");

    int rows = 2;
    int cols = 3;
    for (int i = 0; i < rows; i++) {
        printf("|");
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("|");
        printf("\n");
    }
    // function to calculate next matrix
    calculate(matrix, gcd, topNum1, topNum2);
}

// Function to perform calculations on the matrix
void calculate(int matrix[][3], int *gcd, int *topNum1, int *topNum2) {
    int num1FromCalculate = matrix[0][0];
    int num2 = matrix[1][0];
    int topNum1FromCalculate = matrix[0][1];
    int topNum2FromCalculate = matrix[0][2];
    int botNum1 = matrix[1][1];
    int botNum2 = matrix[1][2];
    
    if (num2 == 0) {
        printf("Calulations finished\n");
        *gcd = num1FromCalculate;
        *topNum1 = topNum1FromCalculate;
        *topNum2 = topNum2FromCalculate;
        return;
    }
    
    int quotient;
    if (num1FromCalculate >= num2) {
        quotient = (num1FromCalculate / num2) * -1;
        printf("%d goes into %d, %d times.\n", num2, num1FromCalculate, -1 * quotient);
        printf("Now multiply the bottom row by %d and add it to the top row.\n", quotient);
        num1FromCalculate += (num2 * quotient);
        topNum1FromCalculate += (botNum1 * quotient);
        topNum2FromCalculate += (botNum2 * quotient);
        printf("The numbers for the top row are now: %d %d %d\n", num1FromCalculate, topNum1FromCalculate, topNum2FromCalculate);
        matrix[0][0] = num1FromCalculate;
        matrix[0][1] = topNum1FromCalculate;
        matrix[0][2] = topNum2FromCalculate;
        printMatrix(matrix, gcd, topNum1, topNum2);
    } else {
        // Does the opposite of the if statement
        quotient = (num2 / num1FromCalculate) * -1;
        printf("%d goes into %d, %d times.\n", num1FromCalculate, num2, -1 * quotient);
        printf("Now multiply the top row by %d and add it to the bottom row.\n", quotient);
        num2 += (num1FromCalculate * quotient);
        botNum1 += (topNum1FromCalculate * quotient);
        botNum2 += (topNum2FromCalculate * quotient);
        printf("The numbers for the bottom row are now: %d %d %d\n", num2, botNum1, botNum2);
        matrix[1][0] = num2;
        matrix[1][1] = botNum1;
        matrix[1][2] = botNum2;
        printMatrix(matrix, gcd, topNum1, topNum2);
    }
}

int main() {
    // Eventually get user input for both numbers
    int input1 = 129;
    int input2 = 60;
    int baseMatrix[2][3] = {{input1, 1, 0},
                            {input2, 0, 1}};
                            
    // Variables to store values returned from calculate
    int gcd, coefficient1, coefficient2;

    // Call the function to print the matrix
    printMatrix(baseMatrix, &gcd, &coefficient1, &coefficient2); // 2 rows, 3 columns

    // Display the results
    printf("\nThe GCD is: %d\n", gcd);
    printf("Numbers to use in formula: %d %d\n", coefficient1, coefficient2);
    // give option to user to show the formula
    // formula is gcd = input1(coefficient1) + input2(coefficient2)
    printf("Program complete\n");

    return 0;
}
