#include "IPostEffects.h"

int IPostEffects::effectNo = Mode_Random;

IPostEffects::~IPostEffects() {}

//素早く変更可能
void IPostEffects::ChangeNumber() {
	if (Input::GetInstance()->TriggerKey(DIK_F1)) {
		effectNo++;
	}
	if (effectNo == Mode_Vignette + 1) {
		effectNo = 0;
	}
}
