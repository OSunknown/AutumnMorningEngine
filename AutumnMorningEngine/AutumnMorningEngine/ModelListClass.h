///////////////////////////////////////////////////////////////////////////////
// Filename: modellistclass.h
///////////////////////////////////////////////////////////////////////////////
#ifndef _MODELLISTCLASS_H_
#define _MODELLISTCLASS_H_


//////////////
// INCLUDES //
//////////////
#include "Math.h"
#include <stdlib.h>
#include <time.h>


///////////////////////////////////////////////////////////////////////////////
// Class name: ModelListClass
///////////////////////////////////////////////////////////////////////////////
class ModelListClass
{
private:
	struct ModelInfoType
	{
		Vector4 color;
		float positionX, positionY, positionZ;
	};

public:
	ModelListClass();
	ModelListClass(const ModelListClass&);
	~ModelListClass();

	bool Initialize(int);
	void Shutdown();

	int GetModelCount();
	void GetData(int, float&, float&, float&, Vector4&);

private:
	int m_modelCount;
	ModelInfoType* m_ModelInfoList;
};

#endif