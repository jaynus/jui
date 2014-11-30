//diag_log text format["begin on_RscDisplayRemoteMissions"];

_res = "jui" callExtension "setStage:on_RscDisplayRemoteMissions";
call compile preprocessfilelinenumbers "\x\jui\addons\main\setClientInfo.sqf";

["onLoad",_this,"RscDisplayRemoteMissions",'GUI'] call compile preprocessfilelinenumbers "A3\ui_f\scripts\initDisplay.sqf";