#include "DrawTriPorygon.h"
#include "Input.h"

DrawTriPorygon::DrawTriPorygon(){
	
}

DrawTriPorygon::~DrawTriPorygon(){

}

void DrawTriPorygon::Initialize(){

	input_ = Input::GetInstance();

	Scale_ = { 1.0f,1.0f,1.0f };
	Rotate_ = { 0.0f,0.0f,0.0f };
	Translate_ = { 0.0f,0.0f,0.0f };;
	CameraPosition = { 0.0f,0.5f,-10.0f };
	kLocalVertices[0] = { 0.0f,1.0f,0.0f, };
	kLocalVertices[1] = { 0.5f,0.0f,0.0f };
	kLocalVertices[2] = {-0.5f,0.0f,0.0f };
	
	
}

void DrawTriPorygon::Update()
{
	if (input_->PushKey(DIK_W)) {
		translateStrage.z += 0.1f;
	}
	if (input_->PushKey(DIK_S)) {
		translateStrage.z-= 0.1f;
	}
	if (input_->PushKey(DIK_A)) {
		translateStrage.x -= 0.1f;
	}
	if (input_->PushKey(DIK_D)) {
		translateStrage.x += 0.1f;
	}
	rotateStrage.y -= 0.1f;

	Translate_ = translateStrage;
	Rotate_ = rotateStrage;
}

void DrawTriPorygon::Draw(){

	Update();

	Matrix4x4 worldMatrix = amf_.MakeAffinMatrix(amf_.MakeScaleMatrix(Scale_),amf_.MakeRotateMatrix(Rotate_), amf_.MakeTranslateMatrix(Translate_));
	Matrix4x4 cameraMatrix = amf_.MakeAffinMatrix(amf_.MakeScaleMatrix({ 1.0f,1.0f,1.0f }), amf_.MakeRotateMatrix({ 0.0f,0.0f,0.0f }), amf_.MakeTranslateMatrix(CameraPosition));
	Matrix4x4 viewMatrix = mf_.Inverse(cameraMatrix);
	Matrix4x4 ProjectionMatrix = rpf_.MakePerspectiveFovMatrix(0.45f, 1280.0f / 720.0f, 0.1f, 100.0f);
	Matrix4x4 worldViewProjectionMatrix = mf_.Multiply(worldMatrix, mf_.Multiply(viewMatrix, ProjectionMatrix));
	Matrix4x4 viewPortMatrix = rpf_.MakeViewportMatrix(0.0f, 0.0f, 1280.0f, 720.0f, 0.0f, 0.0f);
	
	Vector3 screenvirtices[3] = {};
	for (int i = 0; i < 3; i++) {
		Vector3 ndcVertex = amf_.Transform(kLocalVertices[i], worldViewProjectionMatrix);
		screenvirtices[i] = amf_.Transform(ndcVertex, viewPortMatrix);
		int c = 0;
		c++;
	}


	

	Novice::DrawTriangle( int(screenvirtices[0].x), int( screenvirtices[0].y), int(screenvirtices[1].x), int(screenvirtices[1].y), int(screenvirtices[2].x), int (screenvirtices[2].y), RED, kFillModeSolid);

}
