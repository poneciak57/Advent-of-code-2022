# My Advent of Code 2022

- [About days](#about)
- [How to run](#using)
- [Disclaimer](#disclaimer)

<br>

# About 

| Day      | Stars | Description |
| ----------- | ----------- | ----------- |
|Day1|:star: :star:| warm up|
|Day2|:star: :star:| i overcomplicated this and predefined a lot|
|Day3|:star: :star:| some fancy ascii operations |
|Day4|:star: :star:| i change input a little bit :grimacing:|
|Day5|:star: :star:| my challeng was to read the input without changes |
|Day6|:star: :star:| just 3 nested for loops|
|Day7|:star: :star:| looked really hard but was easy|
|Day8|:star: :star:| i think i saw similar task year ago|
|Day9|:star: :star:| it was pretty tough for me to complete second star|
|Day10|:star: :star:| very satisfying i really like image output tasks|

<br>
<br>

# Using 
Project uses makefile for certain tasks such as:

- adding new day from template
- running specific star from specific day
- making snapshot for certain star in specific day

I also made `config.env` where initial values can be changed 

--- 
## Adding new day:
To add new day run command
```cmd
make add
```
this will create new day folder according to `Template` and `DAY` variable in `config.env`. To specify day without always changing `congig.env` variable run:
```cmd
make add DAY=<your_day>
```
---
## Running any day and any star:
To run star that you want from any day use command like:
```cmd
make DAY=<your_day> STAR=<your_star>
```
or
```cmd
make all DAY=<your_day> STAR=<your_star>
```
## Making snapshot
To make snapshot run command 
```cmd
make snapshot DAY=<your_day> STAR=<your_star>
```
if its first snapshot it will create folder for snapshot in `your_day` forlder and create copy of requested star in this folder 
> it will add date to the name of the copy so u dont need to worry about having multiple snapshots with the same name



<br>
<br>

# Disclaimer
If you want to use it as a template for your advent of code solutions do not change anything in config or makefile. If you are not sure what you are doing just follow the instructions. Makefile was writen only for my purposes and can not work corectly on all devices and its simple by design.

Commits on github might be in a wrong order because i created repo on day 10 and tried to group everything right