#ifndef XYZ_H
#define XYZ_H
#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <sstream>
 
std::random_device generator;
std::uniform_real_distribution<float> unitInterval(0.0f,1.0f);
std::uniform_real_distribution<float> symmetricInterval(-1.0f,1.0f);
constexpr double PI  =3.141592653589793238463;

class xyz {

public:
	float x;
	float y;
	float z;
	xyz();
	xyz(float X, float Y, float Z);
	float magnitude();
	std::string print_xyz();
	void set_xyz(float X, float Y, float Z);

	friend xyz operator+(const xyz &v1, const xyz &v2);
	friend xyz operator-(const xyz &v1, const xyz &v2);
	friend float operator*(const xyz &v1, const xyz &v2);
	friend xyz operator*(const float &c1, const xyz &v1);
	friend xyz operator*(const xyz &v1, const float &c1);
	friend xyz operator/(const xyz &v1, const float &c1);

};

xyz::xyz(){
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

xyz::xyz(float X,float Y, float Z){
	x = X;
	y = Y;
	z = Z;
}

void xyz::set_xyz(float X,float Y, float Z){
	x = X;
	y = Y;
	z = Z;
}

float xyz::magnitude(){
	return sqrt((x*x+y*y+z*z));
}



std::string xyz::print_xyz(){
	std::stringstream result;
	result << "(" << x << "," << y << "," << z << ")" ;
	return result.str(); 
}

//Define vector addition

xyz operator+(const xyz &v1, const xyz &v2){
	xyz result;
	result.set_xyz(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z);
	return result;
}

//Define vector subtraction

xyz operator-(const xyz &v1, const xyz &v2){
	xyz result;
	result.set_xyz(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z);
	return result;
}

//Dot product

float operator*(const xyz &v1, const xyz &v2){
	return (v1.x*v2.x)+(v1.y*v2.y)+(v1.z*v2.z);
}

//Vector scaling

xyz operator*(const float &c1, const xyz &v1){
	xyz result;
	result.set_xyz(c1*v1.x,c1*v1.y,c1*v1.z);
	return result;
}
xyz operator*(const xyz &v1, const float &c1){
	xyz result;
	result.set_xyz(c1*v1.x,c1*v1.y,c1*v1.z);
	return result;
}

//Vector division by constant

xyz operator/(const xyz &v1, const float &c1){
	xyz result;
	result.set_xyz(v1.x/c1, v1.y/c1, v1.z/c1);
	return result;
}

//Random vector generation for unit interval 0-1. 

xyz xyz_unit_interval(){
	xyz result;
	result.set_xyz(unitInterval(generator),unitInterval(generator),unitInterval(generator));
	return result;
}

//Random vector generation for interval -1 to 1. 

xyz xyz_symm_interval(){
	xyz result;
	result.set_xyz(symmetricInterval(generator),symmetricInterval(generator),symmetricInterval(generator));
	return result; 
}

//Choose random unit vector from surface of sphere. 

 xyz rand_direction(){
 	float theta = unitInterval(generator) * 2.0f * PI;
 	float u = symmetricInterval(generator);
 	xyz result;
 	result.set_xyz(sqrt(1-(u*u))*cos(theta),sqrt(1-(u*u))*sin(theta),u);
 	return result;
 }

#endif
