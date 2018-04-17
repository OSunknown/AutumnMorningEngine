#pragma once
#include<D3D11.h>
#include <D3DX10math.h>
#pragma comment(lib,"D3D11.lib")

#include "textureClass.h"
class ModelClass
{
private:
	//color
	/*struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR4 color;
	};*/
	//Texture
	/*struct VertexType
	{
		Vector3 position;
		Vector2 texture;
	};
*/
	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
		D3DXVECTOR3 normal;
	};
public:
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();

	bool Initialize(ID3D11Device*, WCHAR*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();
	
	ID3D11ShaderResourceView* GetTexture();
private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	bool LoadTexture(ID3D11Device*, WCHAR*);
	void ReleaseTexture();
private:
	ID3D11Buffer * m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;

	TextureClass* m_Texture;
};

