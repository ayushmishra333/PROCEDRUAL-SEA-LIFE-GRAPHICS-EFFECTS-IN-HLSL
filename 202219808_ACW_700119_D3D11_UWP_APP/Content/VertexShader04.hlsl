cbuffer ModelViewProjectionConstantBuffer : register(b0)
{
    matrix model;
    matrix view;
    matrix projection;
};

struct VS_Canvas
{
    float4 Position : SV_POSITION;
    float2 canvasXY : TEXCOORD0;
};


VS_Canvas main(float3 vPos : POSITION)
{
    VS_Canvas Output;
    //vPos.xyz *= 30.0;
    //vPos.z -= 15.0;
    //vPos.y += 0.;
    //vPos.x -= 12.0;
     
    vPos.xyz *= 25.0;
    vPos.x -= 4.5;
    vPos.x *= 3.0;
    vPos.y += 1.1;
    vPos.y *= 3.0;
    vPos.z -= 14.0;
  
    Output.Position = float4(vPos, 1.0);
    Output.Position = mul(Output.Position, view);
    Output.Position = mul(Output.Position, projection);
    
    float AspectRatio = projection._m11 / projection._m00;
    Output.canvasXY = sign(vPos.xy) * float2(AspectRatio, 1.8);

    return Output;
}