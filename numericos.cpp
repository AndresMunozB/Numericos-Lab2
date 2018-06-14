#include <iostream>
#include <time.h>
#include <armadillo>

using namespace arma;
using namespace std;



int main(int argc, char** argv)
{
	cout << "Armadillo version: " << arma_version::as_string() << endl;
	mat A;
	mat B;
	/*A.load("289x289/A289.dat",raw_ascii);
	B.load("289x289/b289.dat",raw_ascii);

	A.load("289x289/A289.dat",raw_ascii);
	B.load("289x289/b289.dat",raw_ascii);
	*/
	A.load("4225x4225/A4225.dat",raw_ascii);
	B.load("4225x4225/b4225.dat",raw_ascii);
	mat L, U;
	lu(L,U,B,A);
	mat X = B.t()*L*U;

	return 0;


}
