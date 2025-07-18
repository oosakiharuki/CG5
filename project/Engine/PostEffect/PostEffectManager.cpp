#include "PostEffectManager.h"


PostEffectManager* PostEffectManager::instance = nullptr;

uint32_t PostEffectManager::kSRVIndexTop = 1;

PostEffectManager* PostEffectManager::GetInstance() {
	if (instance == nullptr) {
		instance = new PostEffectManager;
	}
	return instance;
}

void PostEffectManager::Finalize() {
	effectArr_[currentNo_]->Finalize();
	delete effectArr_[currentNo_];

	delete instance;
	instance = nullptr;
}

void PostEffectManager::Change(int prev, int current) {

	//前のシーンの解放
	effectArr_[prev]->Finalize();
	delete effectArr_[prev];
	effectArr_[prev] = nullptr;

	//scene_ = current;
	switch (current)
	{
	case Mode_RadialBlur:
		effectArr_[current] = new RadialBlur();
		break;
	case Mode_Vignette:
		effectArr_[current] = new Vignette();
		break;
	}
}
void PostEffectManager::Initialize(DirectXCommon* dxCommon) {
	
	
	effectArr_[Mode_RadialBlur] = new RadialBlur();

	prevNo_ = 0;
	currentNo_ = Mode_RadialBlur;
	

	dxCommon_ = dxCommon;
	effectArr_[currentNo_]->Initialize(dxCommon_);	
}

void PostEffectManager::Update() {

	prevNo_ = currentNo_;
	currentNo_ = effectArr_[currentNo_]->GetEffectNo();

	if (prevNo_ != currentNo_) {
		Change(prevNo_, currentNo_);
		effectArr_[currentNo_]->Initialize(dxCommon_);
	}
	
	effectArr_[currentNo_]->EffectChange();

}

void PostEffectManager::Command() {
	effectArr_[currentNo_]->Command();
}
