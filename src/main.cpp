#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define INPUT_SIZE 3

typedef double couple[2];

double hypothesis( double x , double theta);
double linearRegression (couple points [], double* theta, double const alpha);
double gradientDescent (couple points[], double theta);

int main()
{
    srand(time(NULL));
    couple points[] = { {1,55},{2,55},{3,55} };
    double static theta = 5 ;// What you want your initial theta to be -- Usually we try and keep this between 0 and 1 and scale the input and correlating output so that they stay within the bounds also
    double const alpha = .001; //How big steps you want to take for gradient descent
    double finalError = 0;

    for(double i = 0 ; i <    5000000 ; i++)
        finalError = linearRegression(points,&theta,alpha);

// std::cout<<"Total Error: "<<linearRegression(points,&theta,alpha)<<std::endl<<std::endl;

    std::cout<<"Theta: "<<theta<<std::endl;
    std::cout<<"Total Error: "<<finalError<<std::endl<<std::endl;

}

double hypothesis( double x , double theta)
{
    return x*theta;
}


double linearRegression (couple points [], double* theta, double const alpha) //Cost function for outputting the error with respect to the theta
{
    double errorSum = 0;




    for(int i = 0 ; i < INPUT_SIZE ; i++)
    {
        errorSum += hypothesis(points[i][0], *theta) - points[i][1]; //Get a sum of all computed error values representing the difference between what our hypothesis function output with the x and our own changing theta and the known output of y
    }

    *theta -= alpha * gradientDescent(points,*theta); //subtracting the gradient step we want to take because we want to take a negative step if the slope is positive and vice versa to find the local min.
    return pow(errorSum,2)/ (INPUT_SIZE * 2); //returns error

}

double gradientDescent (couple points[], double theta)
{
    double errorSum = 0;



    for(int i = 0 ; i < INPUT_SIZE ; i++)
    {
        errorSum += (hypothesis(points[i][0], theta) - points[i][1]) * points[i][0]; //Get a sum of all computed error values representing the difference between what our hypothesis function output with the x and our own changing theta and the known output of y
    }

    return errorSum / (INPUT_SIZE); //returns error

}
