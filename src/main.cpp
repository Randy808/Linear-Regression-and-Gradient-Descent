#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define INPUT_SIZE 3

typedef double couple[2];


/******************************************************/
/*            Theta 1 - Feature 1 Coefficient          /
/*            Theta 2 - Constant                       /
/******************************************************/

double hypothesis( double x , double theta);
double linearRegression (couple points [], double* theta, double const alpha);
double gradientDescent (couple points[], double theta);

double linearRegression (couple points [], double* theta1, double* theta2, double const alpha);
double hypothesis( double x , double theta1, double theta2);
double gradientDescent (couple points[], double theta1, double theta2,bool feature1);

/*
double linearRegression (couple points [], double* theta, double* theta2, double const alpha);
double hypothesis( double x , double theta1, double theta2);
double gradientDescent (couple points[], double theta1, double theta2,bool feature1);
*/

int main()
{
    srand(time(NULL));

    int g = 0;
    std::cout<<"Enter g: ";
    std::cin>>g;

    couple points[] = { {1,5},{2,10},{3,15} };
    double const ALPHA = .001; //How big steps you want to take for gradient descent
    double static theta = 5 ;// What you want your initial theta to be -- Usually we try and keep this between 0 and 1 and scale the input and correlating output so that they stay within the bounds also
    double static theta2 = 5 ;
    double finalError = 0;

    while(g != 0)
    {
        //couple points[] = { {g,55},{2,55},{g,55} };

        for(double i = 0 ; i <    50000 ; i++)
            finalError = linearRegression(points,&theta,&theta2, ALPHA);


        std::cout<<"\nTheta: "<< ((theta > .00001) ? theta : 0);
        std::cout<<"\nTheta2: "<< ((theta2 < .00001 && theta2 > 0) ?  0 : theta2  ) <<std::endl;
        std::cout<<"Total Error: "<<finalError<<std::endl;
        std::cout<<theta<< "x + " << ((theta2 < .00001 && theta2 > 0) ?  0 : theta2)  <<std::endl<<std::endl;

        std::cout<<"Enter new g : ";
        std::cin>>g;
    }

}



/***************************************************************************/

/*************************Linear Regression , 1 feature*********************/

/***************************************************************************/

double hypothesis( double x , double theta)
{
    return x*theta;
}



////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\



double linearRegression (couple points [], double* theta, double const alpha) //Cost function for outputting the error with respect to the theta
{
    double errorSum = 0;




    for(int i = 0 ; i < INPUT_SIZE ; i++)
    {
         errorSum += pow(hypothesis(points[i][0], *theta1, *theta2) - points[i][1], 2); //Get a sum of all the squared(because we want the error to be positive, and it makes the whole function easier to derive) computed error values representing the difference between what our hypothesis function output with the x and our own changing theta and the known output of y
    }

    *theta -= alpha * gradientDescent(points,*theta); //subtracting the gradient step we want to take because we want to take a negative step if the slope is positive and vice versa to find the local min.
    return errorSum/ (INPUT_SIZE * 2); //returns error

}


////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


double gradientDescent (couple points[], double theta)
{
    double errorSum = 0;



    for(int i = 0 ; i < INPUT_SIZE ; i++)
    {
        errorSum += (hypothesis(points[i][0], theta) - points[i][1]) * points[i][0]; //Get a sum of all computed error values representing the difference between what our hypothesis function output with the x and our own changing theta and the known output of y
    }

    return errorSum / (INPUT_SIZE); //returns error

}



/***************************************************************************/

/*************Linear Regression with constant******************************/

/***************************************************************************/







double hypothesis( double x , double theta1, double theta2)
{
    return x*theta1 + theta2;
}



////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\



double linearRegression (couple points [], double* theta1, double* theta2, double const alpha) //Cost function for outputting the error with respect to the theta
{
    double errorSum = 0;
    double deltat1, deltat2;



    for(int i = 0 ; i < INPUT_SIZE ; i++)
    {
        errorSum += pow(hypothesis(points[i][0], *theta1, *theta2) - points[i][1], 2); //Get a sum of all computed error values representing the difference between what our hypothesis function output with the x and our own changing theta and the known output of y
    }

    deltat1 = alpha * gradientDescent(points, *theta1, *theta2 ,true); //subtracting the gradient step we want to take because we want to take a negative step if the slope is positive and vice versa to find the local min.
    deltat2 = alpha * gradientDescent(points, *theta1, *theta2,false);

    *theta1 -= deltat1;
    *theta2 -= deltat2;

    return errorSum/ (INPUT_SIZE * 2); //returns error

}




////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


double gradientDescent (couple points[], double theta1, double theta2,bool feature1)
{
    double errorSum = 0;


//get the error sum, times error sum by the x, and divide by training set number to get the derivative

    if(feature1)
    {


        for(int i = 0 ; i < INPUT_SIZE ; i++)
        {
            errorSum += (hypothesis(points[i][0], theta1,theta2) - points[i][1]) * points[i][0]; //Get a sum of all computed error values representing the difference between what our hypothesis function output with the x and our own changing theta and the known output of y
        }
    }
    else
    {
        for(int i = 0 ; i < INPUT_SIZE ; i++)
        {
            errorSum += (hypothesis(points[i][0], theta1,theta2) - points[i][1]); //Get a sum of all computed error values representing the difference between what our hypothesis function output with the x and our own changing theta and the known output of y
        }

    }

    return errorSum / (INPUT_SIZE); //returns error









/***************************************************************************/

/*****************************Gradient Descent******************************/

/***************************************************************************/



//TWO FEATURES


}
