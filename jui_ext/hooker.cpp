#include "xplatform.hpp"

#if	defined(_MSC_VER)


#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <detours.h>
#else
#include "plthook/plthook.h"

#endif

#include "hooker.hpp"
#include "engine.hpp"
#include "logging.hpp"

#if	defined(_MSC_VER)

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
	) = D3D11CreateDevice;

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
	) = D3D11CreateDeviceAndSwapChain;

#endif

namespace jui {

	HRESULT WINAPI h_D3D11CreateDevice(
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
	) {
		HRESULT res;
		res = sys_D3D11CreateDevice(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext);
		LOG(DEBUG) << "enter";
		

		return res;
	}

	HRESULT WINAPI  h_D3D11CreateDeviceAndSwapChain(
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
		) {
		return hooker::_engine.catch_direct3d_init(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext);
	}
	
	void hooker::initialize() {
#if	defined(_MSC_VER)
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());

		DetourAttach(&(PVOID &)sys_D3D11CreateDevice, h_D3D11CreateDevice);
		DetourAttach(&(PVOID &)sys_D3D11CreateDeviceAndSwapChain, h_D3D11CreateDeviceAndSwapChain);

		DetourTransactionCommit();
#endif
	}

	void hooker::release() {
#if	defined(_MSC_VER)
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());

		DetourDetach(&(PVOID &)sys_D3D11CreateDevice, h_D3D11CreateDevice);
		DetourDetach(&(PVOID &)sys_D3D11CreateDeviceAndSwapChain, h_D3D11CreateDeviceAndSwapChain);

		if ((DetourTransactionCommit()) == NO_ERROR) {
			LOG(DEBUG) << "Detours successful";
		}
#else
		// Do linux detach
		printf("Placeholder");
#endif
	}

	hooker::hooker() {
		//initialize();
	}
	hooker::~hooker() {
		//release();
	}

	jui::engine jui::hooker::_engine = jui::engine();
};
