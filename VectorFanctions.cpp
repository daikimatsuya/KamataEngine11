#include "VectorFanctions.h"
#include "math.h"


Vector3 VectorFanctions::Add(const Vector3& v1, const Vector3& v2) {
	Vector3 tmp={};
	tmp.x = v1.x + v2.x;
	tmp.y = v1.y + v2.y;
	tmp.z = v1.z + v2.z;
	return tmp;
}

Vector3 VectorFanctions::Subtract(const Vector3& v1, const Vector3& v2){
	Vector3 tmp={};
	tmp.x = v1.x - v2.x;
	tmp.y = v1.y - v2.y;
	tmp.z = v1.z - v2.z;
	return tmp;
}

Vector3 VectorFanctions::Multiply(const Vector3& v1, float scalar){
	Vector3 tmp={};
	tmp.x = v1.x * scalar;
	tmp.y = v1.y * scalar;
	tmp.z = v1.z * scalar;
	return tmp;
}

float VectorFanctions::Dot(const Vector3& v1, const Vector3& v2){
	float tmp={};
	tmp = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return tmp;
}

float VectorFanctions::Length(const Vector3& v1){
	float tmp={};
	tmp = sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	return tmp;
}

Vector3 VectorFanctions::Normalize(const Vector3& v1){
	float tmp1={};
	Vector3 tmp2={};
	tmp1 = sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	tmp2.x = v1.x / tmp1;
	tmp2.y = v1.y / tmp1;
	tmp2.z = v1.z / tmp1;
	return tmp2;
}

Vector3 VectorFanctions::Cross(const Vector3& vector1, const Vector3& vector2){
	Vector3 tmp;
	tmp = { vector1.y * vector2.z - vector1.z * vector2.y,vector1.z * vector2.x - vector1.x * vector2.z,vector1.x * vector2.y - vector1.y * vector1.y };
	return tmp;
}


