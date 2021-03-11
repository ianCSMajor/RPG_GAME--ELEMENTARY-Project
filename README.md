# Elementary
 Authors: [Richard Tobing](https://github.com/Koogleblitz),
  	  [Ian Oh](https://github.com/ianCSMajor),
 	  [Sanat Mishra](https://github.com/SanatMishra),
	    [Ian Kim](https://github.com/yanathan)

![Screenshot (550)](https://user-images.githubusercontent.com/57507406/110731639-8d175380-81d7-11eb-9df5-92ce603b1b6f.png)

## Project Description
This Project is a turn-based RPG with battle mechanics roughly based on pokemon. Its focus is the interaction between the four Greek elements; fire, earth, wind, and water.  Each element has one element that it is strong against, and one that it is weak against. The battle system essentially works like rock-paper-scissors, in which you choose an element-based attack, and your enemy does the same, and each turn, you and your enemy exchange attacks. The effectiveness of you and your enemy's attack is based on how the chosen element of each party interacts against the other.

An RPG is interesting for our group because an RPG provides us an ideal structure for the design patterns that we learned and gives us a chance 
to implement them in creative and fun ways. 

Project input/output:
* INPUT - Keyboard input for different attacks you can choose for each turn. 
* OUTPUT- The event happens as a result of each turn; the output of you and your enemy's attack and how it affects your health points. 

The technologies we will use are:
* [C++](https://en.wikipedia.org/wiki/C%2B%2B) - C++ is optimal for game development so it is the preferred language for optimizing our game. It is the language our group is most familiar with.  
* [Visual Studio Code][https://code.visualstudio.com/] - Visual studeo code has a liveshare option that promotes communication and interaction throughout our team. 
* [Repl][https://repl.it/] - Alternative browser-based IDE for promoting collaboration, allows us to code concurrently on the same files. 
* 	Project on Repl: https://repl.it/@Koogleblitz/Elementary-formerly-Magic-Quest
* [GitHub][https://github.com/] - Repository to store our work

The two design patterns we plan to use are Factory and Strategy patterns.
* FACTORY PATTERN- Because we have to make many similar objects that are slightly different (enemies), the factory pattern would be ideal for creating enemies. Each level would introduce a new enemy, so depending on the current level, the factory would produce a different type of enemy. 
	* Each time a level is generated, the client code calls the factory's createEnemy() method to create the new enemy
	* createEnemy() is called multiple times througout runtime everytime we need a new enemy

* STRATEGY PATTERN - We picked this pattern for our element/attack system. 
	* Each "strategy" is represented by the different element-based attacks that the player can use, with each deploying a seperate algorithm for determining how they interact against other elements. During runtime, the player chooses which element to use for each turn, which determines the effectiveness of his attack. 
	* Our factory pattern also works in conjunction with our strategy pattern, because we select from a set of strategies (attacks) that are used to create the different types of enemies. 
	* One problem we ran into with our strategy pattern is the circular dependency of our different classes, and the objects that use that class. We solved this problem by making use of forward declerations. 

 > ## Phase II
 
Kanban board located in Projects tab

## Class Diagram
https://app.diagrams.net/#G1zc5uAu5pfPlCaDtQE04yRj8Chca9av9S
![UML Diagram3](https://user-images.githubusercontent.com/28118510/110696256-b2886b00-819f-11eb-8c32-6cab54f7ffff.png)

Class Diagram Description: 
	Our five different attack classes at the top use different implementations of the doAttack() function which it inherits from our Attack interface. The Player, and the six enemy types that all inherit from the Entity abstract class. The client code makes use of the EnemyFactory to populate the game with enemies for the player to fight. Each enemy type has a different implmentation of the ascii() function to display the current enemy on our GUI. All enemies are asigned one of the 5 Attack subclases to use as an attack, and the player can choose and change his attack at runtime. The client code has a list of functions it calls upon at different stages of the game, such ass levelWin() for completing a level, and gameOverScreen() upon the Player's death. 
	
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 > ![Screenshot (536)](https://user-images.githubusercontent.com/57507406/110699994-4a885380-81a4-11eb-95c6-0ea47f86353c.png)
![Screenshot (537)](https://user-images.githubusercontent.com/57507406/110700029-54aa5200-81a4-11eb-9175-db6968ca395d.png)
![Screenshot (538)](https://user-images.githubusercontent.com/57507406/110700047-5aa03300-81a4-11eb-9c41-2b705cde0ffd.png)
![Screenshot (539)](https://user-images.githubusercontent.com/57507406/110700066-5ffd7d80-81a4-11eb-9d0b-74d23f4b6227.png)
![Screenshot (541)](https://user-images.githubusercontent.com/57507406/110700084-655ac800-81a4-11eb-8f2f-f00ea292a253.png)
![Screenshot (537)](https://user-images.githubusercontent.com/57507406/110700117-71df2080-81a4-11eb-87c0-0be5a846b122.png)

 ## Installation/Usage
 > Instructions on installing and running your application
 > 
 > To install the video game onto your machine, open up a terminal you may have installed on your computer (I am using CMDER) and 
 > type in the code git clone --recursive "paste link here" and grab the github link from our repository. You may need special
 > permissions from BCOE to access it as it is a school repository and not ours. 
 > ![Screenshot (544)](https://user-images.githubusercontent.com/57507406/110684005-79e19500-8191-11eb-89ee-b72af42a35e8.png)
 > 
Once you have installed it, go into the the directory and build the project. You want to write the command "cmake3 ." and press enter. 
Follow up with "make" and press enter to let it build. Once it is built, type ./game to play in the terminal. 

 > ![Screenshot (533)](https://user-images.githubusercontent.com/57507406/110683387-cd9fae80-8190-11eb-98c7-4a0108fe0aec.png)
 > 
 > You will be greeted by the start screen where you will press enter to play the game. 
 > 
![Screenshot (534)](https://user-images.githubusercontent.com/57507406/110683522-f88a0280-8190-11eb-9474-db87585207a2.png)

We have two options in our start screen such as "select difficulty" and "start game". The purpose is self-explanatory. 

![Screenshot (535)](https://user-images.githubusercontent.com/57507406/110683564-03449780-8191-11eb-9158-da3e50eaf3e7.png)

If you feel you want a challenge or the game may feel too hard, press 'd' and enter on your terminal to access the difficulty screen.

![Screenshot (536)](https://user-images.githubusercontent.com/57507406/110683617-13f50d80-8191-11eb-8dbe-eaab9a791eec.png)

Once  here, you may have three options: press 'e' for easy, press 'n' for normal. press 'h' for hard and press enterto save your preference.

![Screenshot (537)](https://user-images.githubusercontent.com/57507406/110683646-1c4d4880-8191-11eb-8c88-d597e572cadd.png)

To play the game, press 's' on your keyboard and you will be greeted by our psycho bulter robot. He will ask you for your name
so that he will know what to call you. 

![Screenshot (538)](https://user-images.githubusercontent.com/57507406/110683688-28390a80-8191-11eb-8fe0-80c68b0f8a46.png)

 As soon as you tell him yor name, he will draw a picture of what he thinks you look 
like based on your namehe will display your stats. Your stats entirely depend on what difficulty you have chosen. If you
picked "Hard", then your HP will be 100, "Normal" is 500 HP and "Easy" is 1000 HP. Please press start when you prompted to do so. 

![Screenshot (539)](https://user-images.githubusercontent.com/57507406/110683722-2ff8af00-8191-11eb-838d-d935a44b4293.png)

This is the first level of the game. All levels will look and feel the same so we have only included one screenshot of 
the battle phase. You will be given a list of options to choose from.

![Screenshot (540)](https://user-images.githubusercontent.com/57507406/110683741-36872680-8191-11eb-9151-fafbab0286c4.png)

You will type in a strictly numerical attack 
and you choose with the corresponding numbers given in the interface, then press enter. Keep attacking that vicious 
wild gnome until it dies. Now you probably feel like the main character in the Russian novel: "My first Goose" and are 
sad about it, but do not fret, he has gone to "Garden Gnome Heaven". That's part of the lore of the game. 

![Screenshot (541)](https://user-images.githubusercontent.com/57507406/110683865-5e768a00-8191-11eb-85de-bd4c29611bdd.png)

Then you will be greated by the level clear screen where you will press enter. 

![Screenshot (542)](https://user-images.githubusercontent.com/57507406/110683887-65050180-8191-11eb-80b8-9d7d6e6663eb.png)

Once you beat all 6 levels, you will be greeted with the end screen.

![Screenshot (543)](https://user-images.githubusercontent.com/57507406/110683917-6a624c00-8191-11eb-87cd-a06a6279925a.png)

 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 > There were 43 tests done from 8 different test suites on our group project. We created tests to see if the 
 > name of the user and the starting hp affected by difficulty choice outputted the correct information, 
 > we tested the changeHP function to change the HP of our hero and the mobs, we tested the getDifficultyString to make sure 
 > the resulting string contained the correct difficulty and we extensively tested our elemental attacks by making multiple tests
 > for each attack implemented in the game. 
 > 
 > ![Screenshot (547)](https://user-images.githubusercontent.com/57507406/110699013-3db73000-81a3-11eb-911c-223a903b4e15.png)
![Screenshot (546)](https://user-images.githubusercontent.com/57507406/110699019-41e34d80-81a3-11eb-9c58-abc3cbbd633d.png)

## Valgrind reports
![Screenshot (548)](https://user-images.githubusercontent.com/57507406/110711718-defab200-81b4-11eb-8ddd-c8ed75f37959.png)
![Screenshot (549)](https://user-images.githubusercontent.com/57507406/110715320-da84c800-81b9-11eb-8990-69bfc8211335.png)


 
