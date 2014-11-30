#pragma once

#include <Winsock2.h>
#include <d3d11.h>

namespace jui {
	class engine {
	public:
		engine();
		~engine();

		
		HRESULT catch_direct3d_init(_In_   IDXGIAdapter *pAdapter,
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
			_Out_  ID3D11DeviceContext **ppImmediateContext);

	protected:
		IDXGISwapChain			*_swapChain; 
		ID3D11Device			*_device;
		ID3D11DeviceContext		*_deviceContext;
	};
}