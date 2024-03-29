#pragma once

#include "..\Common\DeviceResources.h"
#include "..\Common\StepTimer.h"
#include "ShaderStructures.h"

namespace _202219808_D3D11_APP
{
	using namespace Windows::System;
	using namespace Windows::UI::Core;

	class TSCoralRenderer
	{
	public:
		class TSCoralRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources);

		void CreateDeviceDependentResources();
		void CreateWindowSizeDependentResources();
		void ReleaseDeviceDependentResources();

		void Update(DX::StepTimer const& timer);
		void Render();

	private:
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources>			m_deviceResources;

		// Direct3D resources for cube geometry.
		Microsoft::WRL::ComPtr<ID3D11InputLayout>		m_inputLayout;
		Microsoft::WRL::ComPtr<ID3D11Buffer>			m_vertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer>			m_indexBuffer;
		Microsoft::WRL::ComPtr<ID3D11VertexShader>		m_vertexShader;
		Microsoft::WRL::ComPtr<ID3D11HullShader>		m_hullShader;
		Microsoft::WRL::ComPtr<ID3D11DomainShader>		m_domainShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader>		m_pixelShader;
		Microsoft::WRL::ComPtr<ID3D11Buffer>			m_constantBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer>			m_timeBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer>			m_tessBuffer;

		// Rasterization
		Microsoft::WRL::ComPtr<ID3D11RasterizerState>	m_rasterizerState;

		// System resources for cube geometry.
		ModelViewProjectionConstantBuffer				m_constantBufferData;
		TimeConstantBuffer								m_timeBufferData;
		TessBuffer										m_tessBufferData;
		uint32											m_indexCount;

		// Variables used with the rendering loop.
		bool											m_loadingComplete;
		float m_tessFactor;
	};
}

