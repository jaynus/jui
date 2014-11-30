#include "xplatform.hpp"

#if	defined(_MSC_VER)
	#include <d3d11.h>
	#pragma comment (lib, "d3d11.lib")

	#include <Windows.h>
	#include <detours.h>
	#pragma comment(lib, "Shlwapi.lib")
	#pragma comment(lib, "ws2_32.lib")
	#pragma comment(lib, "detours.lib" )

#endif

#include <string>
#include "hooker.hpp"

#include "logging.hpp"
_INITIALIZE_EASYLOGGINGPP

static jui::hooker _hooker;

void initialize() {
	printf("------------enter--------\n");
	
	_hooker.initialize();
}

void release() {
	_hooker.release();
}

void rv_command(char *output, int outputSize, const char *function) {
	LOG(DEBUG) << "rv_command: " << function;
	
	static bool _initialized = false;
	
	if (!_initialized) {
		initialize();
		_initialized = true;
	}
}


#if	defined(_MSC_VER)
	static void load(void) {
		LOG(INFO) << "JUI DLL Loaded";
	}

	static void destroy(void) {
		LOG(DEBUG) << "JUI DLL destroyed";
	}
	BOOL APIENTRY DllMain( HMODULE hModule,
						   DWORD  ul_reason_for_call,
						   LPVOID lpReserved
						 )
	{
		switch (ul_reason_for_call) {
			case DLL_PROCESS_ATTACH:;
				load();
				break;
			case DLL_PROCESS_DETACH:
				destroy();
				break;
			case DLL_THREAD_ATTACH:
			case DLL_THREAD_DETACH:

			default:
				break;
		}
		
		return TRUE;
	}
#else
	static void __attribute__((constructor)) load(void) {
//		LOG(DEBUG) << "JNET DLL Loaded";
		printf("jnet.so Loaded\n");
		jnet::g_Engine = nullptr;
	}

	static void __attribute__((destructor)) destroy(void) {
//		LOG(DEBUG) << "JNET DLL destroyed";
		printf("jnet.so Destroyed\n");
	}
#endif

#if	defined(_MSC_VER)
	extern "C" {
		__declspec(dllexport) void __stdcall RVExtension(char *output, int outputSize, const char *function);
	};

	void __stdcall RVExtension(char *output, int outputSize, const char *function) {
		rv_command(output, outputSize, function);
	}
#else						// Linux
	extern "C" {
		void RVExtension(char *output, int outputSize, const char *function);
	};


	void RVExtension(char *output, int outputSize, const char *function) {
		if (!jnet::g_Engine) {
			jnet::g_Engine = new jnet::john();
			initialize();
		}
		jnet::g_Engine->rv_command(output, outputSize, function);
	}
#endif
