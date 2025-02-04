//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Icon*/        /*Command*/                                /*Update Interval*/         /*Update Signal*/
    {"Temp: ",      "~/dwm/dwm-blocks/scripts/cpuTemp.sh",     10,                         0},
    {"",            "~/dwm/dwm-blocks/scripts/gpuTemp.sh",     10,                         0},
    {"Mem:",        "~/dwm/dwm-blocks/scripts/ramUsage.sh",    30,                         0},
    {"",            "~/dwm/dwm-blocks/scripts/date.sh",        5,                          0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
