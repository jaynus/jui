copy build\Debug\jui.dll .

makepbo -P addons\main addons\jui_main.pbo

cd c:\arma\arma3
"C:\arma\arma3\arma3.exe" -window -exThreads=7 -cpuCount=8 -nosplash -showScriptErrors -profiles=Profiles -mod=x\jui -connect=192.168.1.11 -port=2302