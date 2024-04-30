#include <stdio.h>
#include <string.h>

// Function declaration
void calculate(int matrix[][3], int *gcd, int *coefficient1, int *coefficient2);

// Function to find the maximum width of numbers in the matrix for GUI
int findMaxWidth(int matrix[][3], int rows, int cols) {
    int maxWidth = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int numWidth = snprintf(NULL, 0, "%d", matrix[i][j]);
            if (numWidth > maxWidth) {
                maxWidth = numWidth;
            }
        }
    }
    return maxWidth;
}

// Count how many times printMatrix has run
int stepNumber = 0;

// Function to print a matrix
void printMatrix(int matrix[][3], int *gcd, int *coefficient1, int *coefficient2) {
    int rows = 2;
    int cols = 3;
    stepNumber++;
    printf("\n(#%d)Your new matrix is: \n", stepNumber);

    // Find the maximum width of numbers in the matrix for GUI
    int maxWidth = findMaxWidth(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        printf("|");
        for (int j = 0; j < cols; j++) {
            printf("%*d", maxWidth + 1, matrix[i][j]);
        }
        printf("|");
        printf("\n");
    }
    // Calculate the next matrix
    calculate(matrix, gcd, coefficient1, coefficient2);
}

// Function to perform calculations on the matrix
void calculate(int matrix[][3], int *gcd, int *coefficient1, int *coefficient2) {
    int num1 = matrix[0][0];
    int num2 = matrix[1][0];
    int topNum1 = matrix[0][1];
    int topNum2 = matrix[0][2];
    int botNum1 = matrix[1][1];
    int botNum2 = matrix[1][2];
    
    // GCD has been found
    if (num2 == 0) {
        printf("Calculations finished\n");
        *gcd = num1;
        *coefficient1 = topNum1;
        *coefficient2 = topNum2;
        return;
    } else if (num1 == 0){
        printf("Calculations finished\n");
        *gcd = num2;
        *coefficient1 = botNum1;
        *coefficient2 = botNum2;
        return;
    }
    
    // Perform calculations
    int quotient;
    if (num1 >= num2) {
        quotient = (num1 / num2) * -1;
        printf("%d goes into %d, %d times.\n", num2, num1, -1 * quotient);
        printf("Now multiply the bottom row by %d and add it to the top row.\n", quotient);
        num1 += (num2 * quotient);
        topNum1 += (botNum1 * quotient);
        topNum2 += (botNum2 * quotient);
        printf("The numbers for the top row are now: %d %d %d\n", num1, topNum1, topNum2);
        matrix[0][0] = num1;
        matrix[0][1] = topNum1;
        matrix[0][2] = topNum2;
        printMatrix(matrix, gcd, coefficient1, coefficient2);
    } else {
        // Does the opposite of the if statement
        quotient = (num2 / num1) * -1;
        printf("%d goes into %d, %d times.\n", num1, num2, -1 * quotient);
        printf("Now multiply the top row by %d and add it to the bottom row.\n", quotient);
        num2 += (num1 * quotient);
        botNum1 += (topNum1 * quotient);
        botNum2 += (topNum2 * quotient);
        printf("The numbers for the bottom row are now: %d %d %d\n", num2, botNum1, botNum2);
        matrix[1][0] = num2;
        matrix[1][1] = botNum1;
        matrix[1][2] = botNum2;
        printMatrix(matrix, gcd, coefficient1, coefficient2);
    }
}

// Function to make sure user enters a positive whole number
int validateUserInput() {
    int number;
    do {
        printf("Enter a positive whole number: ");
        scanf("%d", &number);
        if (number <= 0) {
            printf("Invalid input. Please enter a positive whole number.\n");
        }
    } while (number <= 0); // Repeat until a positive whole number is entered
    return number;
}

int main() {
    int input1, input2;

    // Get user input for both numbers
    input1 = validateUserInput();
    input2 = validateUserInput();

    // Check and swap if necessary so that input1 stores the higher number
    if (input2 > input1) {
        int temp = input1;
        input1 = input2;
        input2 = temp;
    }

    int baseMatrix[2][3] = {{input1, 1, 0},
                            {input2, 0, 1}};

    // Variables to store values returned from calculate
    int gcd, coefficient1, coefficient2;

    // Call the function to print the matrix
    printMatrix(baseMatrix, &gcd, &coefficient1, &coefficient2);

    // Display the results
    printf("\nThe GCD(%d,%d) is: %d\n",input1, input2, gcd);
    printf("Numbers to use in formula: %d %d\n", coefficient1, coefficient2);
    // Show the formula
    printf("See for yourself: the formula is gcd = input1(coefficient1) + input2(coefficient2)\n");
    printf("%d = %d(%d) + %d(%d)\n", gcd, input1, coefficient1, input2, coefficient2);
    printf("Program complete\n");

    return 0;
}
