#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define _USE_MATH_DEFINES

// Function to convert degrees to radians
double toRadians(double degrees)
{
    return (degrees * M_PI) / 180;
}

// Function to convert radians to degrees
double toDegrees(double radians)
{
    return (radians * 180) / M_PI;
}

// Function to solve for missing sides and angles in SSS case
void solveSSS(double a, double b, double c)
{
    // declaration
    double alpha, beta, gamma, perimeter, p, area;
    char angleType[20];
    char triangleType[20];

    // solve for perimeter
    perimeter = a + b + c;
    // semi perimeter
    p = perimeter / 2;
    // solve for area
    area = sqrt(p * (p - a) * (p - b) * (p - c));

    // Solving for angles using Law of Cosines
    alpha = toDegrees(acos((b * b + c * c - a * a) / (2 * b * c)));
    beta = toDegrees(acos((a * a + c * c - b * b) / (2 * a * c)));
    gamma = toDegrees(acos((a * a + b * b - c * c) / (2 * a * b)));

    // Determine triangle type
    if (a == b && b == c)
    {
        strcpy(angleType, "equilateral");
    }
    else if (a == b || b == c || a == c) // all sides are equal
    {
        strcpy(angleType, "isosceles"); // two sides are equal
    }
    else
    {
        strcpy(angleType, "scalene"); // no sides are equal
    }

    // Determine triangle angle type
    if (alpha > 90 || beta > 90 || gamma > 90)
    {
        strcpy(triangleType, "obtuse"); // no sides are equal
    }
    else if (alpha == 90 || beta == 90 || gamma == 90)
    {
        strcpy(triangleType, "right"); // one angle is right
    }
    else
    {
        strcpy(triangleType, "acute"); // one angle is right
    }

    // print all the information
    printf("\n");
    printf("Format: SSS\n");
    printf("a =%8.3f\talpha =%8.3f\n", a, alpha);
    printf("b =%8.3f\tbeta  =%8.3f\n", b, beta);
    printf("c =%8.3f\tgamma =%8.3f\n", c, gamma);
    printf("Perimeter =%8.3f\n", perimeter);
    printf("Area      =%8.3f\n", area);
    printf("Type      = %s, %s\n", angleType, triangleType);
    printf("\n");
}

// Function to solve for missing sides and angles in SAS case
void solveSAS(double a, double b, double c)
{
    // declaration
    double alpha, beta, gamma, radians, side_b, side_c, perimeter, area;
    char angleType[20];
    char triangleType[20];

    gamma = b;  // Assign value of b to variable gamma
    side_b = c; // Assign value of c to variable side_b

    // Convert gamma to radians

    radians = gamma * (M_PI / 180);

    // Calculate side c using the Law of Cosines
    side_c = sqrt(pow(a, 2) + pow(side_b, 2) - 2 * a * side_b * cos(radians));

    // Calculate perimeter
    perimeter = a + side_b + side_c;
    // Calculate area using Heron's formula
    double s = perimeter / 2;
    area = sqrt(s * (s - a) * (s - side_b) * (s - side_c));

    // Calculate angles
    alpha = acos((pow(side_b, 2) + pow(side_c, 2) - pow(a, 2)) / (2 * side_b * side_c));
    beta = acos((pow(a, 2) + pow(side_c, 2) - pow(side_b, 2)) / (2 * a * side_c));
    gamma = acos((pow(a, 2) + pow(side_b, 2) - pow(side_c, 2)) / (2 * a * side_b));

    // Convert angles to degrees
    alpha = alpha * (180 / M_PI);
    beta = beta * (180 / M_PI);
    gamma = gamma * (180 / M_PI);

    // Determine triangle type
    if (a == b && b == c)
    {
        strcpy(angleType, "equilateral"); // Assign value of b to variable gamma
    }
    else if (a == b || b == c || a == c)
    {
        strcpy(angleType, "isosceles"); // Assign value of b to variable gamma
    }
    else
    {
        strcpy(angleType, "scalene"); // no sides are equal
    }

    // Determine triangle angle type
    if (alpha > 90 || beta > 90 || gamma > 90)
    {
        strcpy(triangleType, "obtuse"); // no sides are equal
    }
    else if (alpha == 90 || beta == 90 || gamma == 90)
    {
        strcpy(triangleType, "right"); // no sides are equal
    }
    else
    {
        strcpy(triangleType, "acute"); // no sides are equal
    }

    // print all the information
    printf("\n");
    printf("Format: SAS\n");
    printf("a =%8.3f\talpha =%8.3f\n", a, alpha);
    printf("b =%8.3f\tbeta  =%8.3f\n", side_b, beta);
    printf("c =%8.3f\tgamma =%8.3f\n", side_c, gamma);
    printf("Perimeter =%8.3f\n", perimeter);
    printf("Area      =%8.3f\n", area);
    printf("Type      = %s, %s\n", angleType, triangleType);
    printf("\n");
}

// Function to solve for missing sides and angles in ASA case
void solveASA(double a, double b, double c)
{

    double side_a, side_b, side_c, alpha, beta, gamma;
    char angleType[20];
    char triangleType[20];

    alpha = a;  // Assign value of a to variable alpha
    side_c = b; // Assign value of b to variable side_c
    beta = c;   // Assign value of c to variable beta

    alpha = (alpha * M_PI) / 180;
    beta = (beta * M_PI) / 180;
    gamma = 180 - (alpha + beta) / (M_PI / 180);

    // calculate the side_a and side_b
    side_a = side_c * sin(alpha) / sin(gamma * M_PI / 180);
    side_b = side_c * sin(beta) / sin(gamma * M_PI / 180);

    // Calculate perimeter
    double perimeter = side_a + side_b + side_c;
    // Calculate area
    double area = (side_a * side_b * sin(gamma * M_PI / 180)) / 2;

    // Determine triangle type
    if (alpha == beta && beta == gamma)
    {
        strcpy(angleType, "equilateral"); // Assign value of a to variable alpha
    }
    else if (alpha == beta || beta == gamma || alpha == gamma)
    {
        strcpy(angleType, "isosceles"); // two sides are equal
    }
    else
    {
        strcpy(angleType, "scalene"); // no sides are equal
    }

    // Determine triangle angle type
    if (alpha > 90 || beta > 90 || gamma > 90)
    {
        strcpy(triangleType, "obtuse"); // one angle is obtuse
    }
    else if (alpha == 90 || beta == 90 || gamma == 90)
    {
        strcpy(triangleType, "right"); // one angle is right
    }
    else
    {
        strcpy(triangleType, "acute"); // all angles are acute
    }

    // print all the information
    printf("\n");
    printf("Format: ASA\n");
    printf("a =%8.3f\talpha =%8.3f\n", side_a, (alpha * 180) / M_PI);
    printf("b =%8.3f\tbeta  =%8.3f\n", side_b, (beta * 180) / M_PI);
    printf("c =%8.3f\tgamma =%8.3f\n", side_c, gamma);
    printf("Perimeter =%8.3f\n", perimeter);
    printf("Area      =%8.3f\n", area);
    printf("Type      = %s, %s\n", angleType, triangleType);
    printf("\n");
}

// Function to solve for missing sides and angles in SSA case
int solveSSA(double a, double b, double c)
{
    double side_b, side_c, beta, side_a, alpha, gamma, gammaPrime, perimeter, area, D;
    char triangleType[20], angleType[20];
    int bGreaterThanC = 1;

    side_b = a; // Assign value of a to side_b
    side_c = b; // Assign value of b to side_c
    beta = c;   // Assign value of c to beta

    // Convert beta to radians
    beta = beta * (M_PI / 180);

    // Calculate D
    D = side_c / side_b * sin(beta);

    // Check if D > 1 or beta >= 90 and b <= c
    if (D > 1 || (beta > 180 && side_b < side_c))
    {
        printf("Impossible triangle\n");
        return EXIT_SUCCESS;
    }

    // Check if D = 1
    if (D == 1)
    {
        gamma = M_PI / 2;
        strcpy(angleType, "right");
    }
    else
    {
        // Check if b >= c
        if (side_b >= side_c)
        {
            gamma = asin(D);
            strcpy(angleType, "obtuse");
        }
        else
        {
            bGreaterThanC = 0;
            gamma = asin(D);
            gammaPrime = M_PI - gamma;
            strcpy(angleType, "obtuse");
        }
    }

    // Calculate alpha
    alpha = M_PI - beta - gamma;

    // Calculate a using law of sines
    side_a = side_b * sin(alpha) / sin(beta);

    // Calculate perimeter and area
    perimeter = side_a + side_b + side_c;
    double s = perimeter / 2;
    area = sqrt(s * (s - side_a) * (s - side_b) * (s - side_c));

    // Check if triangle is scalene, isosceles or equilateral
    if (side_a != side_b && side_b != side_c && side_a != side_c)
    {
        strcpy(triangleType, "scalene");
    }
    else if (side_a == side_b && side_b == side_c)
    {
        strcpy(triangleType, "equilateral");
    }
    else
    {
        strcpy(triangleType, "isosceles");
    }

    // Print informations
    printf("\nFormat: SSA\n");
    if (!bGreaterThanC)
    {
        printf("--> Gamma\n");
    }
    printf("a =%8.3f\talpha =%8.3f\n", side_a, (alpha * 180) / M_PI);
    printf("b =%8.3f\tbeta  =%8.3f\n", side_b, (beta * 180) / M_PI);
    printf("c =%8.3f\tgamma =%8.3f\n", side_c, (gamma * 180) / M_PI);
    printf("Perimeter =%8.3f\n", perimeter);
    printf("Area      =%8.3f\n", area);
    printf("Type      = %s, %s\n", triangleType, angleType);
    printf("\n");

    if (!bGreaterThanC) // check if b is not greater than c
    {

        // Convert beta to radians
        beta = beta * (M_PI / 180);

        // Calculate a using law of cosines
        side_a = sqrt(side_b * side_b + side_c * side_c - 2 * side_b * side_c * cos(beta)); // Calculate alpha

        beta = beta * (180 / M_PI);

        alpha = M_PI - beta - gammaPrime;

        // Calculate perimeter and area
        perimeter = side_a + side_b + side_c;
        area = (side_b * side_c * cos(beta)) / 2;

        // Print results for gamma'
        printf("--> gamma'\n");
        printf("a =%8.3f\talpha =%8.3f\n", side_a, (alpha * 180) / M_PI);
        printf("b =%8.3f\tbeta  =%8.3f\n", side_b, (beta * 180) / M_PI);
        printf("c =%8.3f\tgamma =%8.3f\n", side_c, (gammaPrime * 180) / M_PI);
        printf("Perimeter =%8.3f\n", perimeter);
        printf("Area      =%8.3f\n", area * (M_PI / 180));
        printf("Type      = %s, %s\n", triangleType, angleType);
        printf("\n");
    }
}

int main()
{
    char inputChar[5]; // variable to store the Format
    char input[100];   // variable to store the user input
    double a, b, c;    // variables to store the # values

    while (true) // loop to continuously prompt for user input
    {
        printf("-> ");
        // reads user input, spaces, and variable
        fgets(input, 100, stdin);
        int res = sscanf(input, "%s %lf %lf %lf", inputChar, &a, &b, &c); // formatted input of the user

        // if the user inputs exit, quit, or bye, the will program end
        if (strcmp(inputChar, "exit") == 0 || strcmp(inputChar, "quit") == 0 || strcmp(inputChar, "bye") == 0)
        {
            return 0;
        }

        // Convert format string to upper case
        for (int i = 0; inputChar[i]; i++)
        {
            inputChar[i] = toupper(inputChar[i]);
        }

        // Convert negative inputs to positive
        a = fabs(a);
        b = fabs(b);
        c = fabs(c);

        if (res < 4) // check the number of variables (Format, #, #, #)
        {
            printf("Bad command: Format # # #\n where Format = SSS|SAS|ASA|SSA\n # = a real number\n\n");
            continue; // continues to next loop
        }

        // checks if the inputChar is not equal to "SSS", "SAS", "ASA", or "SSA"
        if (strcmp(inputChar, "SSS") != 0 && strcmp(inputChar, "SAS") != 0 && strcmp(inputChar, "ASA") != 0 && strcmp(inputChar, "SSA") != 0)
        {
            printf("Unknown command triangle format '%s'\n", inputChar);
            continue; // continues to next loop
        }

        // Validate input for impossible triangles
        if (strcmp(inputChar, "SSS") == 0)
        { // check if a, b, c is 0
            if (a == 0 || b == 0 || c == 0)
            {
                printf("Impossible triangle\n");
                continue; // continues to next loop
            }
            else if (a + b < c || a + c < b || b + c < a)
            {
                printf("Impossible triangle\n");
                continue; // continues to next loop
            }
        }
        else if (strcmp(inputChar, "SAS") == 0)
        { // check if a, b, c is 0
            if (a == 0 || b == 0 || c == 0)
            {
                printf("Impossible triangle\n");
                continue; // continues to next loop
            }
        }
        else if (strcmp(inputChar, "ASA") == 0)
        {
            /*if (a + b <= c || a + c <= b || b + c <= a)
            {
                printf("Impossible triangle\n");
                continue;
            }*/

            if (a == 0 || b == 0 || c == 0)
            {
                printf("Impossible triangle\n");
                continue; // continues to next loop
            }
        }
        else if (strcmp(inputChar, "SSA") == 0)
        {
            /* if (a >= b + c || b >= a + c || c >= a + b)
             {
                 printf("Impossible triangle.\n");
                 continue;
             }*/

            if (a == 0 || b == 0 || c == 0)
            {
                printf("Impossible triangle\n");
                continue; // continues to next loop
            }
        }

        // Call appropriate function to solve for missing sides and angles
        if (strcmp(inputChar, "SSS") == 0)
        {
            solveSSS(a, b, c);
        }
        else if (strcmp(inputChar, "SAS") == 0)
        {
            solveSAS(a, b, c);
        }
        else if (strcmp(inputChar, "ASA") == 0)
        {
            solveASA(a, b, c);
        }
        else if (strcmp(inputChar, "SSA") == 0)
        {
            solveSSA(a, b, c);
        }
    }

    return 0;
}
