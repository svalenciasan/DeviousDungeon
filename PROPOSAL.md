#Devious Dungeon([Inspiration](https://sludgelife.fandom.com/wiki/Crypt_Creeper))

Crypt Creeper is a minigame inside of a game called "Sludge Life". I want to make a game similar to this minigame
while additionally fixing some of the issues I had with it. I think this project won't be too difficult to do using our
previous projects as reference. However, I might be underestimating things since I'm still not entirely familiar with
cinder and my game depends heavily on it. I would like to know if you have any suggestions on things that might be
difficult to implement or any tools or resources you might think could be useful at the top of your head.

![Image of Crypt Creeper](https://static.wikia.nocookie.net/sludgelife/images/a/a2/Crypr_Creeper_Level_1_Exemple.png/revision/latest/scale-to-width-down/498?cb=20201015224729)

###Description:
Randomly generated grid based puzzle game.

#####The goal:
Reach the portal, doing this enough times takes you to the final boss room. Defeat the boss.

#####Player: 
Has 3 health, has 2 inventory spaces(one for melee weapons, and one for ranged weapons).

#####Movement: 
Arrow keys allow the player to move left, right, up, and down on the board. Once the player moves to another tile that
previous tile becomes empty

#####Weapons: 
Melee weapons are used automatically when walking to an enemy tile. Ranged weapons can be used at any time by 
pressing the 'space' key and selecting a valid target with the arrow keys
(Can only attack enemies diagonal and connected to your current tile).

#####Empty tiles: 
If the player tries to move to an empty tile they lose.

#####Health tiles: 
If the player steps on this tile they regen a certain amount of health.

#####Gold tiles: 
If the player steps on this tile they gain a certain amount of coins.

#####Weapon Tiles: 
When the player steps onto an weapon tile they pick up said weapon. If they already have that type of
 weapon in their inventory then the previous weapon gets replaced by the new weapon.

#####Enemy Tiles: 
When the player moves onto a cell with an enemy they take health damage according to 
(enemy_damage - melee_weapon_value).

#####Store Tile: 
Opens up a menu and allows the user to buy weapons, health potions, or powerups with coins.

###Overview:

My goal in these 3 weeks is to have one level working with the essential mechanics. Reaching the portal will be the
winning condition.

* Week 1: I want to have implemented the player and grid system with the different kinds of tiles(except the store). I
want to dedicate this week to getting the random level generation working.

* Week 2: This week I want to be able to move my character and interact with the tiles. I should be able to reach the end
and trigger a win by reaching the portal.

* Week 3: I want to dedicate this week to getting the weapons and combat to work. Especially the ranged weapons, 
I think these will be difficult to implement.

###Stretch Goals: 
* Store mechanics: Buying items with collected gold.
* Power-ups: Bombs to damage all enemies on the screen, teleport to the next level.
* Leveling: Enemies give xp and after each level up the player can choose to increase their total health or inventory
space
