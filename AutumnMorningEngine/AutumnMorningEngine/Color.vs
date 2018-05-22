///////////
//GLOBALS//
///////////
cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
}

////////////
//TYPEDEFS//
////////////
struct VertexInputType
{
	float4 position : POSITION;
	float4 color : COLOR;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

//Vertex Shader
PixelInputType ColorVertexShader(VertexInputType input)
{
	PixelInputType output;

	//Change the position verctor to be 4 unitys for proper matrix calculations
	input.position.w = 1.0f;

	//Calculate the position of the vertex against the world, view, and , projction matrices
	output.position = mul(input.position, worldMatrix);
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projectionMatrix);

	//Store the input color ofr the pixel shader to use
	output.color = input.color;

	return output;
}