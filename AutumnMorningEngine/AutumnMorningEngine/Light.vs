

cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float2 tex : TEXCOORD0;
	float3 normal : NORMAL;
};

PixelInputType LightVertexShader(VertexInputType input)
{
	PixelInputType output;

	//Change the position vector to be 4 units for proper matrix calculations
	input.position.w = 1.0;

	//Calculate the position of the vertex against the world, view, projction matrices
	output.position = mul(Input.position,worldMatrix);
	output.position = mul(output.position,viewMatrix);
	output.position = mul(output.position,projectionMatrix)
}