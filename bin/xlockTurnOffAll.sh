#!/bin/bash

nmcli networking off
bluetoothctl power off
xsecurelock
nmcli networking on
bluetoothctl power on
