LAB_NAME="zad2"

#------------------------------------------------
rm -rf output
mkdir output
cd output

verilator \
    --top-module ${LAB_NAME} \
    -Wall \
    +define+SIM_ONLY \
    --timescale 1ns/1ns \
    --trace-fst \
    --cc \
    ../../gowin/src/*.sv \
    --exe versim.cpp \
    --Mdir .

make -f V${LAB_NAME}.mk V${LAB_NAME}

./V${LAB_NAME}

#verilator ../../1.gowin/src/${LAB_NAME}.sv -xml-only --bbox-sys --Mdir .
#xml2stems V${LAB_NAME}.xml V${LAB_NAME}.stems
#gtkwave --stems V${LAB_NAME}.stems waveform.fst &

gtkwave waveform.fst

#------------------------------------------------
#for the most curious, to understand everything,
#  contact:  tarik.ibrahimovic@chili-chips.xyz
#------------------------------------------------
