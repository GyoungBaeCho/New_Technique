#include "Define.fx"
#include "Function.fx"

//-------------------------------------------------------------------------------------------------------------------------------------��ǻ�� ���̴�
struct VS_DIFFUSED_INPUT
{
	float4 position : POSITION;
	float4 color : COLOR0;
};

struct VS_DIFFUSED_OUTPUT
{
	float4 position : SV_POSITION;
	float3 positionW : POSITION;
	float4 color : COLOR0;
};


//��ǻ�� ���� ���� ���̴�
VS_DIFFUSED_OUTPUT VSDiffusedColor(VS_DIFFUSED_INPUT input)
{
    VS_DIFFUSED_OUTPUT output = (VS_DIFFUSED_OUTPUT)0;
	
	output.positionW = mul(input.position, gmtxWorld).xyz;
	output.position = mul(float4(output.positionW, 1), gmtxVP);

    output.color = input.color;
//	output.color = Fog(output.color, output.positionW);
//	output.color = GreyTone(output.color);

    return output;
}

float4 PSDiffusedColor(VS_DIFFUSED_OUTPUT input) : SV_Target
{
//	input.color = Fog(input.color, input.positionW);
	return input.color;
}

PS_MULTIPLE_RENDER_OUTPUT M_PS(VS_DIFFUSED_OUTPUT input) : SV_Target
{
	PS_MULTIPLE_RENDER_OUTPUT output = (PS_MULTIPLE_RENDER_OUTPUT) 0;
	output.color = input.color;
	output.color.a = 0;
	
	float fDepth = input.position.z / input.position.w;
	output.normal = float4(1, 1, 1, fDepth);
	float fSpecular = 1.0f;
	output.position = float4(input.positionW, fSpecular);

	return output;
}


//-------------------------------------------------------------------------------------------------------------------------------------��ǻ�� �ν��Ͻ� ���̴�
struct VS_INSTANCED_DIFFUSED_INPUT
{
    float3 position : POSITION;
    float4 color : COLOR0;
    column_major float4x4 mtxTransform : INSTANCE_MTX;
};

struct VS_INSTANCED_DIFFUSED_OUTPUT
{
    float4 position : SV_POSITION;
    float4 color : COLOR1;
	float3 positionW : POSITION;
//�ý��� ���� ������ ���� ���̴��� ���޵Ǵ� ��ü �ν��Ͻ��� ID�� �ȼ� ���̴��� �����Ѵ�.
//	float4 instanceID : INDEX0;
};

//�ν��Ͻ��� �ϸ鼭 ������ ������ ������ ���� ��� ���� ���̴��� �Է��� ���� ����ü�̴�.
struct VS_MTX_FLT4{
	column_major float4x4 mtxTransform : INSTANCE_MTX;
    float4 instanceColor : INSTANCECOLOR;
};


VS_INSTANCED_DIFFUSED_OUTPUT VSInstancedDiffusedColor(VS_INSTANCED_DIFFUSED_INPUT input)
{
    VS_INSTANCED_DIFFUSED_OUTPUT output = (VS_INSTANCED_DIFFUSED_OUTPUT)1;
	
	output.positionW = mul(float4(input.position, 1), input.mtxTransform).xyz;
	output.position = mul(float4(output.positionW, 1), gmtxVP);
	output.color = input.color;
	output.color = Fog(output.color, output.positionW);
//	output.color = GreyTone(output.color);
//	output.color.a = 1;
    return output;
}

float4 PSInstancedDiffusedColor(VS_INSTANCED_DIFFUSED_OUTPUT input) : SV_Target
{
	return input.color;
}

//-------------------------------------------------------------------------------------------------------------------------------------��ǻ�� �ν��Ͻ� ���� ���̴�
struct VS_INSTANCED_DIFFUSED_RANDOM_INPUT
{
    float3 position : POSITION;
    float4 color : COLOR0;
	VS_MTX_FLT4 transform_color;
//    column_major float4x4 mtxTransform : INSTANCE_MTX;
//    float4 instanceColor : INSTANCECOLOR;
};

struct VS_INSTANCED_DIFFUSED_RANDOM_OUTPUT
{
    float4 position : SV_POSITION;
	float3 positionW : POSITION;
    float4 color : COLOR1;

};

VS_INSTANCED_DIFFUSED_RANDOM_OUTPUT VSInstancedDiffusedRandomColor(VS_INSTANCED_DIFFUSED_RANDOM_INPUT input)
{
    VS_INSTANCED_DIFFUSED_RANDOM_OUTPUT output = (VS_INSTANCED_DIFFUSED_RANDOM_OUTPUT)0;
	
	output.position = mul(mul(float4(input.position, 1), input.transform_color.mtxTransform), gmtxVP);
	output.positionW = mul(float4(input.position, 1.0f), input.transform_color.mtxTransform).xyz;
	output.color = input.transform_color.instanceColor;  
//	output.color = GreyTone(output.color);
	output.color = Fog(output.color, output.positionW);

	return output;
}

float4 PSInstancedDiffusedRandomColor(VS_INSTANCED_DIFFUSED_RANDOM_OUTPUT input) : SV_Target
{
	return input.color;

	input.color = Fog(input.color, input.positionW);

	return input.color;
}