//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Icon*/        /*Command*/                                /*Update Interval*/         /*Update Signal*/
    {"CPU: ",       "/home/kur/.config/sucklessSoftware/dwm-blocks/scripts/cpuUsage.sh",    10,                         0},
    {"GPU: ",       "/home/kur/.config/sucklessSoftware/dwm-blocks/scripts/gpuUsage.sh",    10,                         0},
    {"Temp: ",      "/home/kur/.config/sucklessSoftware/dwm-blocks/scripts/cpuGpuTemp.sh",  10,                         0},
    {"Mem: ",       "/home/kur/.config/sucklessSoftware/dwm-blocks/scripts/ramUsage.sh",    30,                         0},
    {"Vol: ",       "/home/kur/.config/sucklessSoftware/dwm-blocks/scripts/volumeLevel.sh", 30,                         0},
    {"",            "/home/kur/.config/sucklessSoftware/dwm-blocks/scripts/date.sh",        5,                          0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
