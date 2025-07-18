#pragma once
#include "IPostEffects.h"
#include "RadialBlur.h"
#include "Vignette.h"

class PostEffectManager {
public:

	void Initialize(DirectXCommon* dxCommon);
	void Update();
	void Command();
	void Finalize();

	static PostEffectManager* GetInstance();

private:
	void Change(int prev, int current);//シーン入れ替え

	//最大数
	static const uint32_t effectNum = 8;

	IPostEffects* effectArr_[effectNum];

	int currentNo_;//現在シーン
	int prevNo_;//前シーン



	static PostEffectManager* instance;

	PostEffectManager() = default;
	~PostEffectManager() = default;
	PostEffectManager(PostEffectManager&) = default;
	PostEffectManager& operator=(PostEffectManager&) = default;

	static uint32_t kSRVIndexTop;

	DirectXCommon* dxCommon_;
};