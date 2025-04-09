# git clone https://github.com/rticommunity/rticonnextdds-getting-started.git


# MAKE SURE TO CHECK OUT THE PROPER BRANCH FOR RTIDDS 6.0.1.8!!!!!!!!!!!!

me=$(basename $0)

if [[ $# -eq 0 ]]; then
    echo "usage: $me <idl-filename>"
    exit 1
fi
idlfile=${1}


# -example <> creates pub/sub code and xml files
# -platform <> does not

rtiddsgen -language c++11 -alwaysUseStdVector -platform x64Linux3gcc4.8.2 -create makefiles -create typefiles -d c++11 ${idlfile}
