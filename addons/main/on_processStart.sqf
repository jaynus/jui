#include "script_loaders.hpp"

private["_res"];

diag_log text format["JUI Initializing..."];

uiNamespace setVariable ["jui_fnc_eventProcessor", (compile preprocessFileLineNumbers "x\jui\addons\main\fnc_eventProcessor.sqf")];

if(!isDedicated) then {
	diag_log text format["JUI Checking Required Dialog Handlers"];
	_loaders = [
					["RscDisplayMultiplayerSetup", QUOTE(DEF_RscDisplayMultiplayerSetupLoader)],
					["RscDisplayRemoteMissions", QUOTE(DEF_RscDisplayRemoteMissionsLoader)]
			];
	_ok = true;
	{
		if(getText(configFile >> (_x select 0) >> "onLoad") != _x select 1) exitWith {
			_ok = false;
		};
	} forEach _loaders;
	if(_ok) then {
		diag_log text format["JUI Dialog Handlers OK!"];
		_res = "jui" callExtension "init:base";
		call compile preprocessfilelinenumbers "\x\jui\addons\main\setClientInfo.sqf";
		diag_log text format["JUI Initialized!"];
	} else {
		diag_log text format["JUI Dialog Handlers Failed!"];
	};
} else { 
	_res = "jui" callExtension "init:base";
	_res = "jui" callExtension "init:server";
	
	// If it was server, we attempt pulling a test config
	_res = "jui" callExtension "getServerConfig:jvon_enabled";
	diag_log text format["_res=%1", _res];
	diag_log text format["JUI Initialized!"];
};



// config error says minimum is 0.010000. Is this is vanilla?
_res = 0.0;
_res

