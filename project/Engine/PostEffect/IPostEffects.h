#pragma once
#include <cstdint>
#include "DirectXCommon.h"

enum EFFECT {
	copyImage,//None
	boxFillter,
	depthBasedOutline,
	gaussianFillter,
	grayscale,
	luminanceBacedOutline,
	radialBlur,
	vignette,
};

class IPostEffects {
protected:
	static int effectNo;
public:
	virtual void Finalize() = 0;
	virtual void Initialize(DirectXCommon* dxCommon) = 0;

	virtual void Command() = 0;
	
	int GetEffectNo() { return effectNo; }

	//PSO
	virtual void RootSignature() = 0;
	virtual void GraphicsPipeline() = 0;

	virtual ~IPostEffects();
};