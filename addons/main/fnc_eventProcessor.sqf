//fnc_eventProcessor.sqf

_eventType = _this select 0;
_eventClass = (configFile >> "JUI_Events" >> _eventType);

for "_x" from 0 to (count _eventClass)-1 do {
	_event = _eventClass select _x;
	if(isText _event) then {
		[] call (compile (getText(_event)));
	};
};