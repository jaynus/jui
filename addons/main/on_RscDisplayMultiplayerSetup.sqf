//diag_log text format["begin on_RscDisplayMultiplayerSetup"];

_res = "jui" callExtension "setStage:on_RscDisplayMultiplayerSetup";
call compile preprocessfilelinenumbers "\x\jui\addons\main\setClientInfo.sqf";

["onLoad",_this,"RscDisplayMultiplayerSetup",'GUI'] call compile preprocessfilelinenumbers "A3\ui_f\scripts\initDisplay.sqf";