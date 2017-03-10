#!/usr/bin/python
# -*- coding: UTF-8 -*-

import os

file1name = raw_input("Input file1 name: ")
file1 = open(file1name, "r")
file2name = raw_input("Input file2 name: ")

write_file = open("result.txt", "a")

for line1 in file1.readlines():
	file2 = open(file2name, "r")
	spline = line1.split()
	first = spline[0]
	for line2 in file2.readlines():
		if first in line2:
			write_file.write(line1 + " same " + line2)
