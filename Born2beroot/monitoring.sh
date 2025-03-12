#!/bin/bash
# ============================
# System Monitoring Script
# Author: Taron Mkrtumyan
# Date:   6 March 2025
# Displays system statistics
# ============================

banner=$(figlet -f mini "    SYSTEM   MONITORING   REPORT")

arch=$(uname --all)

phys_ps=$(lscpu | grep "^Socket(s)" | awk '{print $2}')
virt_ps=$(lscpu | grep "^CPU(s)" | awk '{print $2}')

used_ram=$(free -m | grep "^Mem:" | awk '{print $3}')
total_ram=$(free -m | grep "^Mem:" | awk '{print $2}')
percent_ram=$(free | grep "^Mem:" | awk '{printf("%.2f"), $3/$2*100}')

used_storage=$(df -m | grep '^/dev/' | grep -v /boot | awk '{a += $3} END {printf("%d",a)}')
avail_storage=$(df -m | grep '^/dev/' | grep -v /boot | awk '{a += $2} END {printf("%d",(a+500)/1000)}')
percent_storage=$(df -m | grep '^/dev/' | grep -v /boot | awk '{a += $3} {b += $2} END {printf("%d",(a/b)*100)}')

util_rate=$(top -bn1 | grep '^%Cpu(s)' | sed 's/,/ /g' | awk '{for(i=1;i<=NF;i++) if ($i=="id") printf("%.1f", 100-$(i-1))}')
last_boot=$(last -n1 reboot --time-format full | awk '{print $5,$6,$7,$8,$9}' | head -n1)
lvms = $(lsblk | grep 'lvm' | wc -l)
lvm_stat=$(if [$lvms == 0]; then echo no; else echo yes; fi)
actv_cons=$(cat /proc/net/sockstat{,6} | awk '$1 == "TCP:" {print $3}')
users_num=$(users | wc -w)
ipv4=$(hostname -I)
mac=$(ip link show | grep ether | awk '{print $2}')
sudo_used=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall   "$banner
# Architecture : ${arch}

# CPU physical : ${phys_ps}
# vCPU : ${virt_ps}

# Memory Usage: ${used_ram}/${total_ram}MB (${percent_ram}%)
# Disk Usage: ${used_storage}/${avail_storage}Gb (${percent_storage}%)
# CPU load: ${util_rate}%

# Last boot: ${last_boot}
# LVM use: ${lvm_stat}
# Sudo : ${sudo_used} cmd
# User log: ${users_num}
# Connections TCP : ${actv_cons} ESTABLISHED
# Network: ${ipv4}${mac}"
