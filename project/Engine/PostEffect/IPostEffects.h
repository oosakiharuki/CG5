#pragma once
#include <cstdint>
#include "DirectXCommon.h"
#include "Input.h"

enum EFFECT {
	Mode_Normal_Image,//None
	Mode_BoxFillter,
	Mode_DepthBasedOutline,
	Mode_Dissolve,
	Mode_GaussianFillter,
	Mode_Grayscale,
	Mode_LuminanceBacedOutline,
	Mode_RadialBlur,
	Mode_Vignette,
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

	virtual void EffectChange() = 0;

	virtual ~IPostEffects();
};