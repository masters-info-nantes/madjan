rem Export program release build in bin-windows directory

rd /s /q "bin-windows"
mkdir "bin-windows"
echo "Export windows release in bin-windows directory"

rem copy "build-windows/release/*.*" "bin-windows"
cd "build-windows/release"
copy *.* "../../bin-windows/"

