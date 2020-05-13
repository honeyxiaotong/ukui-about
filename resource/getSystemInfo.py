#!/usr/bin/env python3
# coding: utf-8

import os
import configparser
from gi.repository import GLib
import sys

#print(sys.argv[0])          #sys.argv[0] 类似于shell中的$0,但不是脚本名称，而是脚本的路径   
#print(sys.argv[1])          #sys.argv[1] 表示传入的第一个参数
cf = configparser.ConfigParser()
info = ""
text = ""
kylin_version = ""
info_build = ""
if os.path.exists("/etc/.kyinfo"):
    cf.read("/etc/.kyinfo")
    secs = cf.sections()
    opts = cf.options("servicekey")
    str_key = cf.get("servicekey", "key")
    info_key = "服务序列号：" + str_key
    str_version = cf.get("dist", "dist_id")
    info_version = "版本信息：" + str_version
    str_customer = cf.get("os", "to")
    info_customer = "客户单位：" + str_customer
    str_term = cf.get("os", "term")
    info_term = "技术服务截止日期：" + str_term
    str_time = cf.get("dist", "time")
    tmp = str_time[2:4] + str_time[5:7] + str_time[8:10]

    f = open("/etc/lsb-release", 'r')
    lines = f.readlines()
    f.close()

    for line in lines:
        if line.startswith("DISTRIB_ID"):
            name = line[11:len(line)-1]
        if line.startswith("DISTRIB_KYLIN_RELEASE"):
            kylin_version = line[22:len(line)-1]

    info_build = name + " "+kylin_version+" \nBuild " + tmp
    if sys.argv[1]=="ShowTerm":
        info = info_version + "\n" + info_customer.strip("\n") + "\n" + info_key + "\n" + info_term + "\n" + "温馨提示：如有问题请咨询销售\n" + "咨询电话：400-089-1870"
    else:
        info = info_version + "\n" + info_customer.strip("\n") + "\n" + info_key + "\n" + "温馨提示：如有问题请咨询销售\n" + "咨询电话：400-089-1870"
else:
    f = open("/etc/lsb-release", 'r')
    lines = f.readlines()
    f.close()

    for line in lines:
        if line.startswith("DISTRIB_ID"):
            name = line[11:len(line)-1]
        if line.startswith("DISTRIB_RELEASE"):
            version = line[16:len(line)-1]

    if len(lines) >= 6 and lines[5].strip().endswith("community"):
        info = name + " " + version + "\n" + "银河麒麟社区版\n"
    else:
        info = name + " " + version + "\n" + "当前版本未授权！\n"

info = info_build + "\n" + info
f = open(GLib.get_home_dir() + "/.info", 'w')
f.write(info)
f.close()
