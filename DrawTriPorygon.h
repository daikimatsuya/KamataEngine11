#pragma once
#include "AffineMatrixFunctions.h"
#include "RenderingPipelineFunctions.h"
#include "MatrixFunctions.h"
#include "Novice.h"
#include "Input.h"
//#include "Input.h"
class DrawTriPorygon{
public:
	DrawTriPorygon();
	~DrawTriPorygon();
	void Initialize();
	void Update();
	void Draw();
private:
	AffineMatrixFunctions amf_;
	MatrixFunctions mf_;
	RenderingPipelineFunctions rpf_;

	Input* input_=nullptr;
	Vector3 Move_ = {};
	Vector3 Scale_ = {};
	Vector3 Rotate_ = {};
	Vector3 Translate_ = {};
	Vector3 CameraPosition = {};
	Vector3 kLocalVertices[3] = { {} };
	Vector3 translateStrage;
	Vector3 rotateStrage;
};

