#include <stdio.h>
#include <conio.h>
#define MAX 10

void muiltiply_matrix(int first_Matrix[MAX][MAX], int second_matrix[MAX][MAX], int result[MAX][MAX], int first_rows, int first_column, int second_row, int second_column)
{
    for (int i = 0; i < first_rows; i++)
    {
        for (int j = 0; j < second_column; j++)
        {
            result[i][j] = 0;
        }
    }
    for (int i = 0; i < first_rows; i++)
    {
        for (int j = 0; j < second_column; j++)
        {
            for (int k = 0; k < second_row; k++)
            {
                result[i][j] += first_Matrix[i][k] * second_matrix[k][j];
            }
        }
    }
}

void print_matrix(int matrix[MAX][MAX], int rows, int column)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    printf("\n Welcome to matrix calculator!!\n");

    printf("\n--------------------------------------------------\n");

    int Choices_01;
    int matrix[3][3], det;
    float matrix_01[3][3];
    float det_01;

    do
    {

        printf("\nPlease Enter the one of the choices:\n");
        printf("1.Determinant of matrix 3 x 3.\n");
        printf("2.Inverse of matrix of 3 x 3\n");
        printf("3.Inverse of matrix of 2 x 2\n");
        printf("4.Matrix multiplication.\n");
        printf("5.Exit\n");
        printf("\n--------------------------------------------------\n");
        scanf("%d", &Choices_01);

        if (Choices_01 == 5)
        {
            break;
        }

        else if (Choices_01 == 1)
        {

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("Enter the entry of matrix: [%d][%d]\n", i, j);
                    scanf(" %d", &matrix[i][j]);
                }
            }

            printf("\n--------------------------------------------------\n");
            printf("--------------------------------------------------\n");

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            printf("\n--------------------------------------------------\n");
            printf("--------------------------------------------------\n");

            for (int i = 0; i < 3; i++)
            {

                for (int j = 0; j < 3; j++)
                {

                    det = matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1])) - matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0])) + matrix[0][2] * ((matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]));
                }
            }
            printf("The determinant of matrix is %d\n", det);
        }

        else if (Choices_01 == 2)
        {

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("Enter the entry of matrix_01: [%d][%d]\n", i, j);
                    scanf(" %f", &matrix_01[i][j]);
                }
            }

            printf("\n--------------------------------------------------\n");
            printf("--------------------------------------------------\n");

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%.2f  ", matrix_01[i][j]);
                }
                printf("\n");
            }
            printf("\n--------------------------------------------------\n");
            printf("--------------------------------------------------\n");

            for (int i = 0; i < 3; i++)
            {

                for (int j = 0; j < 3; j++)
                {

                    det_01 = matrix_01[0][0] * ((matrix_01[1][1] * matrix_01[2][2]) - (matrix_01[1][2] * matrix_01[2][1])) - matrix_01[0][1] * ((matrix_01[1][0] * matrix_01[2][2]) - (matrix_01[1][2] * matrix_01[2][0])) + matrix_01[0][2] * ((matrix_01[1][0] * matrix_01[2][1] - matrix_01[1][1] * matrix_01[2][0]));
                }
            }
            printf("The determinant of matrix_01 is %.2f\n", det_01);

            if (det_01 == 0)
            {
                printf("Inverse of matrix_01 is not possible.\n");
                return 1;
            }

            printf("--------------------------------------------------\n");

            int temp_a11 = (matrix_01[1][1] * matrix_01[2][2] - matrix_01[1][2] * matrix_01[2][1]);
            float a11 = (temp_a11) / det_01;

            int temp_a12 = -(matrix_01[1][0] * matrix_01[2][2] - matrix_01[1][2] * matrix_01[2][0]);
            float a12 = (temp_a12) / det_01;

            int temp_a13 = (matrix_01[1][0] * matrix_01[2][1] - matrix_01[1][1] * matrix_01[2][0]);
            float a13 = (temp_a13) / det_01;

            int temp_a21 = -(matrix_01[0][1] * matrix_01[2][2] - matrix_01[0][2] * matrix_01[2][1]);
            float a21 = (temp_a21) / det_01;

            int temp_a22 = (matrix_01[0][0] * matrix_01[2][2] - matrix_01[0][2] * matrix_01[2][0]);
            float a22 = (temp_a22) / det_01;

            int temp_a23 = -(matrix_01[0][0] * matrix_01[2][1] - matrix_01[0][1] * matrix_01[2][0]);
            float a23 = (temp_a23) / det_01;

            int temp_a31 = (matrix_01[0][1] * matrix_01[1][2] - matrix_01[0][2] * matrix_01[1][1]);
            float a31 = (temp_a31) / det_01;

            int temp_a32 = -(matrix_01[0][0] * matrix_01[1][2] - matrix_01[0][2] * matrix_01[1][0]);
            float a32 = (temp_a32) / det_01;

            int temp_a33 = (matrix_01[0][0] * matrix_01[1][1] - matrix_01[0][1] * matrix_01[1][0]);
            float a33 = (temp_a33) / det_01;

            float inverse_matrix[3][3] = {a11, a21, a31, a12, a22, a32, a13, a23, a33};

            printf("\nThe inverse of matrix is:\n");

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%.2f   ", inverse_matrix[i][j]);
                }

                printf("\n");
            }
        }

        else if (Choices_01 == 3)
        {

            float matrix_02[2][2];
            float det_02;

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    printf("\nEnter the entry of matrix_01: [%d][%d]\n", i, j);
                    scanf(" %f", &matrix_02[i][j]);
                }
            }

            printf("\n--------------------------------------------------\n");
            printf("--------------------------------------------------\n");

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    printf("%.2f  ", matrix_02[i][j]);
                }
                printf("\n");
            }
            printf("\n--------------------------------------------------\n");
            printf("--------------------------------------------------\n");

            for (int i = 0; i < 2; i++)
            {

                for (int j = 0; j < 2; j++)
                {

                    det_02 = (matrix_02[0][0] * matrix_02[1][1]) - (matrix_02[0][1] * matrix_02[1][0]);
                }
            }
            printf("The determinant of matrix_01 is %.2f\n", det_02);

            if (det_02 == 0)
            {
                printf("Inverse of matrix_01 is not possible.\n");
                return 1;
            }

            printf("--------------------------------------------------\n");

            int temp_b11 = matrix_02[1][1];
            float b11 = (temp_b11) / det_02;

            int temp_b12 = -(matrix_02[0][1]);
            float b12 = (temp_b12) / det_02;

            int temp_b21 = -(matrix_02[1][0]);
            float b21 = (temp_b21) / det_02;

            int temp_b22 = (matrix_02[0][0]);
            float b22 = (temp_b22) / det_02;

            float inverse_matrix_02[2][2] = {b11, b12, b21, b22};

            printf("\nThe inverse of matrix is:\n");

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    printf("%.2f   ", inverse_matrix_02[i][j]);
                }

                printf("\n");
            }
        }

        else if (Choices_01 == 4)
        {
            int first_Matrix[MAX][MAX], second_matrix[MAX][MAX], result[MAX][MAX];
            int first_rows, first_column, second_row, second_column;

            printf("\n--------------------------------------------------\n");

            printf("Enter the number of rows and column of first matrix:\n");
            scanf(" %d  %d", &first_rows, &first_column);

            printf("\nEnter the First matrix:\n");
            for (int i = 0; i < first_rows; i++)
            {
                for (int j = 0; j < first_column; j++)
                {
                    scanf("%d", &first_Matrix[i][j]);
                }
            }

            printf("\n--------------------------------------------------\n");

            for (int i = 0; i < first_rows; i++)
            {
                for (int j = 0; j < first_column; j++)
                {
                    printf(" %d", first_Matrix[i][j]);
                }
                printf("\n");
            }

            printf("\nEnter the number of rows and column of second matrix:\n");
            scanf(" %d  %d", &second_row, &second_column);

            if (first_column != second_row)
            {
                printf("Enter the correct entry!!");
                return 1;
            }

            printf("\nEnter the elements of second matrix:\n");
            for (int i = 0; i < second_row; i++)
            {
                for (int j = 0; j < second_column; j++)
                {
                    scanf("%d", &second_matrix[i][j]);
                }
            }

            printf("\n--------------------------------------------------\n");

            for (int i = 0; i < second_row; i++)
            {
                for (int j = 0; j < second_column; j++)
                {
                    printf(" %d", second_matrix[i][j]);
                }
                printf("\n");
            }

            printf("\n--------------------------------------------------\n");
            printf("\n--------------------------------------------------\n");

            muiltiply_matrix(first_Matrix, second_matrix, result, first_rows, second_row, first_column, second_column);

            printf("\nThe multiplication of matrix is:\n");

            print_matrix(result, first_rows, second_column);
        }

    } while (Choices_01 != 5);
    return 0;
}