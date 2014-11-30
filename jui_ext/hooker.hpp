#pragma once

#include "xplatform.hpp"


#if	defined(_MSC_VER)
#include <d3d11.h>

extern HRESULT(WINAPI * sys_D3D11CreateDevice)(
	_In_   IDXGIAdapter *pAdapter,
	_In_   D3D_DRIVER_TYPE DriverType,
	_In_   HMODULE Software,
	_In_   UINT Flags,
	_In_   const D3D_FEATURE_LEVEL *pFeatureLevels,
	_In_   UINT FeatureLevels,
	_In_   UINT SDKVersion,
	_Out_  ID3D11Device **ppDevice,
	_Out_  D3D_FEATURE_LEVEL *pFeatureLevel,
	_Out_  ID3D11DeviceContext **ppImmediateContext
	);

extern HRESULT(WINAPI * sys_D3D11CreateDeviceAndSwapChain)(
	_In_   IDXGIAdapter *pAdapter,
	_In_   D3D_DRIVER_TYPE DriverType,
	_In_   HMODULE Software,
	_In_   UINT Flags,
	_In_   const D3D_FEATURE_LEVEL *pFeatureLevels,
	_In_   UINT FeatureLevels,
	_In_   UINT SDKVersion,
	_In_   const DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
	_Out_  IDXGISwapChain **ppSwapChain,
	_Out_  ID3D11Device **ppDevice,
	_Out_  D3D_FEATURE_LEVEL *pFeatureLevel,
	_Out_  ID3D11DeviceContext **ppImmediateContext
	);

#endif

namespace jui {
	class engine;
#if	defined(_MSC_VER)
	HRESULT WINAPI  h_D3D11CreateDevice(_In_   IDXGIAdapter *pAdapter, _In_   D3D_DRIVER_TYPE DriverType, _In_   HMODULE Software, _In_   UINT Flags, _In_   const D3D_FEATURE_LEVEL *pFeatureLevels, _In_   UINT FeatureLevels, _In_   UINT SDKVersion, _Out_  ID3D11Device **ppDevice, _Out_  D3D_FEATURE_LEVEL *pFeatureLevel, _Out_  ID3D11DeviceContext **ppImmediateContext);
	HRESULT WINAPI  h_D3D11CreateDeviceAndSwapChain(_In_   IDXGIAdapter *pAdapter, _In_   D3D_DRIVER_TYPE DriverType, _In_   HMODULE Software, _In_   UINT Flags, _In_   const D3D_FEATURE_LEVEL *pFeatureLevels, _In_   UINT FeatureLevels, _In_   UINT SDKVersion, _In_   const DXGI_SWAP_CHAIN_DESC *pSwapChainDesc, _Out_  IDXGISwapChain **ppSwapChain, _Out_  ID3D11Device **ppDevice, _Out_  D3D_FEATURE_LEVEL *pFeatureLevel, _Out_  ID3D11DeviceContext **ppImmediateContext);
#endif

	class hooker {
	public:
		hooker();
		~hooker();
	
		void initialize();
		void release();

		static engine _engine;
	protected:
		
	};
};