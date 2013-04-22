rm -rf obj
rm -rf vc110.pdb
rm -rf ../ndll/Windows
rm -rf all_objs
haxelib run hxcpp Build.xml -Dwindows
cp ../ndll/Windows/HypPhoton.ndll ../bin-debug/windows/cpp/bin/HypPhoton.ndll