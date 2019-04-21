## Project: Rolling Hermes

### Front
**Project:** `Rolling Hermes`<br/>
**Author:** `Winnie Jeng, Zijian Zhao`<br/>
**Initiation Date:** `APR 12, 2019`<br/>
**Last Update:** `APR 21, 2019`<br/>

### Description
**_Tower of Hanoi_**, (also called the Tower of Brahma or Lucas' Tower and sometimes pluralized) is a mathematical game or puzzle. It consists of three rods and a number of disks of different sizes, which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top, thus making a conical shape.(Wikipedia). 

### Objective
In order to complete this project, we have to create an ***array based Priority Queue*** class and a ***Linked-List based Stack*** class, and a ***disk*** class, also along with one (or more if needed) **_board_** class to test the program with two different data structures and compare their run times. 
<br/>

### Additional Requirements
No recursive algorithm needed. Which actually makes the project a bit of challenging at the beginning since the game itself is switching disks between pegs recursively. However, we find an approach to find out **HOW TO MAKE THE NEXT MOVE** simply by looking at the current **move** number.

### Insights
In order to analyze how the computer "make moves", we recorded every move that the computer has made and search for a pattern. The initial thought was to find a relationship between disks with differnet sizes, such as "why does #1 go to the #3 pole rather than to #2 the another pole?". Luckily, after we have recorded over sixty moves of Computer's game with initial conditions of 4 and 5 disks (even number condition and odd number condition), we find out a circular pattern of how each disk moves. <br/>
Again, the **goal** is to find out the **Next Move** from current move.<br/>

_p.s. From now, the size (index) of disk will be noted as disk#, and the total number of disks will be noted as DiskNum._ <br/>
_p.p.s. Also, the three pegs will be named as Source, Auxilary (Aux) and Destination (Dest)._

### Patterns 
When DiskNum is **odd**, the next pole which **odd** numbered disk# always moves to is **(Dest - Aux - Source)**; <br/>
When DiskNum is **odd**, the next pole which **even** numbered disk# always moves to is **(Aux - Dest - Source)**. <br/>
When DiskNum is **even**, the next pole which **even** numbered disk# always moves to is **(Dest - Aux - Source)**; <br/>
When DiskNum is **even**, the next pole which **odd** numbered disk# always moves to is **(Aux - Dest - Source)**. <br/>

<br/>Getting there? <br/>
Notice that when _DiskNum_ and _disk#_ are the both odd or even, the moving cycle is **(Dest - Aux - Source)**, otherwise **(Aux - Dest - Source)**. The next step would be simple, just find the relationship between disk# and current move.

## UIKit (ripoff)
Part of Apple's UIKit library rebuilt from scratch with SFML in C++, including UIView, UIButtons, UILabel, and CoreGraphics Library. Functions may be modified for specific use. For more information, please refer to my other project: [Graphic Calculator](https://github.com/JackZhao98/GraphicCalculator-SFML) .

## Screenshots
![screenshot_1](https://github.com/JackZhao98/Rolling_Hermes/blob/master/Rolling%20Hermes/Rolling%20Hermes/UIKit/Resources/ScreenShot_1.png)
![screenshot_2](https://github.com/JackZhao98/Rolling_Hermes/blob/master/Rolling%20Hermes/Rolling%20Hermes/UIKit/Resources/ScreenShot_2.png)
![screenshot_3](https://github.com/JackZhao98/Rolling_Hermes/blob/master/Rolling%20Hermes/Rolling%20Hermes/UIKit/Resources/ScreenShot_3.png)
