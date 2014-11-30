diag_log text format["JUI Initialized"];

if(!isDedicated) then {
	_res = "jui" callExtension "init:gameStart";
	call compile preprocessfilelinenumbers "\x\jui\addons\main\setClientInfo.sqf";
} else { 
	_res = "jui" callExtension "init:gameStart";
};

