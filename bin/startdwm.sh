#!/bin/bash

# Configuracion del teclado
setxkbmap us,es -option 'grp:win_space_toggle'

# ENV variables
export EDITOR=nvim
export MOZ_ENABLE_WAYLAND=0
#->Gnome for x11 config
export GDK_BACKEND=x11
#->QT for x11 config
export QT_QPA_PLATFORM=xcb
export QT_QPA_PLATFORMTHEME=qt5ct
export QT_STYLE_OVERRIDE=kvantum
export QT_QPA_PLATFORMTHEME=qt6ct
#->GTK Theming
#-->cursor
export XCURSOR_THEME=Adwaita
export XCURSOR_SIZE=24
#-->theme
export GTK_THEME=Gruvbox-Dark-Medium-Border:dark
#->Nvidia
export LIBVA_DRIVER_NAME=nvidia 
export __GLX_VENDOR_LIBRARY_NAME=nvidia
export GBM_BACKEND=nvidia-drm 


# Iniciar programas
#picom &
nitrogen --restore &
nm-applet --indicator &
/usr/bin/emacs --daemon &
gsettings set org.gnome.desktop.interface cursor-theme Adwaita &
/home/kur/.config/hypr/scripts/Polkit.sh &
dwmblocks &
dunst &

# DWM configs
#-> Set the monitors config
xrandr --output DP-0 --primary --mode 1920x1080 --rate 144.00 &
xrandr --output HDMI-0 --right-of DP-0 --mode 1920x1080 --rate 60.00 &

# Iniciar DWM
exec dwm
