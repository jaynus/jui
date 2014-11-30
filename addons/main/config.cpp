#include "script_loaders.hpp"

class CfgPatches
{
	class jui_main
	{
		units[] = {};
		requiredVersion = 0.01;
		requiredAddons[] = { "A3_UI_F" };
		version = "1.2.3";
		author[] = {"Jaynus", "Nou"};
		authorUrl = "http://www.idi-systems.com";
	};
};

class Extended_PostInit_EventHandlers
{
	JUI_init = "call compile preprocessFileLineNumbers  ""x\jui\addons\main\on_gameStart.sqf"" ";
};

class PhysXParams
{
	ragdollHitDmgLimit = " call compile preprocessFileLineNumbers  ""x\jui\addons\main\on_processStart.sqf""  ";
};

class RscDisplayEmpty;
class RscStandardDisplay;
class RscChatListDefault;
#include "RscDisplayMultiplayerSetup.hpp"
#include "RscDisplayRemoteMissions.hpp"


class JUI_Events {
	class RscDisplayRemoteMissions {
		jui = "call compile preprocessFileLineNumbers 'x\jui\addons\main\on_RscDisplayRemoteMissions.sqf'";
	};
	
	class RscDisplayMultiplayerSetup {
		jui = "call compile preprocessFileLineNumbers 'x\jui\addons\main\on_RscDisplayMultiplayerSetup.sqf'";
	};
};