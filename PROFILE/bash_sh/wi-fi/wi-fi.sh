#!/bin/bash

if [ -e /etc/wpa_supplicant.conf ]; then
    rm /etc/wpa_supplicant.conf
fi

cp wpa_supplicant.conf /etc/
xwifi=$(cat /proc/net/dev |awk '{i++; if(i>2){print $1}}' |sed 's/[:]*$//g' |grep "wl")
ip link set $xwifi up
wpa_supplicant -i $xwifi -c /etc/wpa_supplicant &
dhclient $xwifi &
