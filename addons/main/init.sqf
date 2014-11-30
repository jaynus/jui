diag_log text format["JUI Initialized"];

_res = "jui" callExtension "init:base";

if(!isServer) then {
	_res = "jui" callExtension "init:client";
} else {
	if(isDedicated) then {
		_res = "jui" callExtension "init:server";
	};
};

