
OPTION=$1

if [ "$OPTION" = 'help' ]; then
    echo build.sh - build debug library
    echo build.sh clean - clean the build
    echo build.sh release - build release library
elif [ "$OPTION" = "release" ]; then
    ./build/bin/release/rive_recorder
else
    ./build/bin/debug/rive_recorder $1
fi
