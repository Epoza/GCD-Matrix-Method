#include <stdio.h>
#include <string.h>

void updateMatrix() {

}

void calculate(int matrix[][3], int rows, int cols){
    int num1 = matrix[0][0];
    int num2 = matrix[1][0];
    int topNum1 = matrix[0][1];
    int topNum2 = matrix[0][2];
    int botNum1 = matrix[1][1];
    int botNum2 = matrix[1][2];
    if (num2 == 0)
    {
        printf("Done");
        // function that finishes program
    }
    
    int quotient;
    if (num1 >= num2) {
        quotient = (num1 / num2)*-1;
        printf("%d goes into %d, %d times.\n", num2, num1, -1*quotient);
        printf("Now multiply the bottom row by %d and add it from the top row \n", quotient);
        num1 += (num2*quotient);
        topNum1 += (botNum1*quotient);
        topNum2 += (botNum2*quotient); 
        printf("The numbers for the top row are now: %d%3d%3d\n", num1, topNum1, topNum2);
        // call updateMatrix function
    } else {
        quotient = num2 / num1;
        printf("%d goes into %d, %d times.\n", num1, num2, quotient);
    }
}

// Function to print a matrix
void printMatrix(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("|");
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("|");
        printf("\n");
    }
    // function to calculate next matrix
    calculate(matrix, 2, 3);
}

int main() {
    // Eventually get user input for both numbers
    int num1 = 129;
    int num2 = 60;
    int topNum1 = 1;
    int topNum2 = 0;
    int botNum1 = 0;
    int botNum2 = 1;
    int matrix[2][3] = {{num1, topNum1, topNum2},
                        {num2, botNum1, botNum2}};

    // Call the function to print the matrix
    printMatrix(matrix, 2, 3); // 2 rows, 3 columns

    return 0;
}
