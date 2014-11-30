#include "engine.hpp"
#include "logging.hpp"
#include "hooker.hpp"

namespace jui {
	engine::engine() {
		LOG(DEBUG) << "Constructing d3d intercept engine";


	}
	engine::~engine() {}

	HRESULT engine::catch_direct3d_init(_In_   IDXGIAdapter *pAdapter,
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
		_Out_  ID3D11DeviceContext **ppImmediateContext)
	{
		HRESULT res = S_OK;

		LOG(DEBUG) << "Init caught!!!!";
		res = sys_D3D11CreateDeviceAndSwapChain(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext);
		
		_device = *ppDevice;
		_swapChain = *ppSwapChain;
		_deviceContext = *ppImmediateContext;
		return res;
	}
}