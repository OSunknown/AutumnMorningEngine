#include "Math.h"

//Vector2 Initialize
const Vector2 Vector2::zero(0.0f, 0.0f);
const Vector2 Vector2::one(1.0f, 1.0f);
//Vector3 Initialize
const Vector3 Vector3::zero(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::one(1.0f, 1.0f, 1.0f);
//Think. 좌표계에 따라 달라지겠지만.. 일단 유니티에 맞춰서 만듦
const Vector3 Vector3::up(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::down(0.0f, -1.0f, 0.0f);
const Vector3 Vector3::forword(0.0f, 0.0f, 1.0f);
const Vector3 Vector3::back(0.0f, 0.0f, -1.0f);
const Vector3 Vector3::right(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::left(-1.0f, 0.0f, 0.0f);
//Vector4 Initialize
const Vector4 Vector4::zero(0.0f, 0.0f, 0.0f,0.0f);
const Vector4 Vector4::one(1.0f, 1.0f, 1.0f,1.0f);