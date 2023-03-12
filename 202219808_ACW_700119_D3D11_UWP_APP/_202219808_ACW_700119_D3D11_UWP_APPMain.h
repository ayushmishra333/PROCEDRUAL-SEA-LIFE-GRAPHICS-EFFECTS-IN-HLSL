﻿#pragma once

#include "Common\StepTimer.h"
#include "Common\DeviceResources.h"
#include "Content\Sample3DSceneRenderer.h"
#include "Content\SampleFpsTextRenderer.h"

// Renders Direct2D and 3D content on the screen.
namespace _202219808_ACW_700119_D3D11_UWP_APP
{
	class _202219808_ACW_700119_D3D11_UWP_APPMain : public DX::IDeviceNotify
	{
	public:
		_202219808_ACW_700119_D3D11_UWP_APPMain(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		~_202219808_ACW_700119_D3D11_UWP_APPMain();
		void CreateWindowSizeDependentResources();
		void Update();
		bool Render();

		// IDeviceNotify
		virtual void OnDeviceLost();
		virtual void OnDeviceRestored();

	private:
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		// TODO: Replace with your own content renderers.
		std::unique_ptr<Sample3DSceneRenderer> m_sceneRenderer;
		std::unique_ptr<SampleFpsTextRenderer> m_fpsTextRenderer;

		// Rendering loop timer.
		DX::StepTimer m_timer;
	};
}