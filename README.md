#Devious Dungeon([Inspiration](https://sludgelife.fandom.com/wiki/Crypt_Creeper))

###Description:
Devious Dungeon is a randomly generated grid based puzzle game. To run the game just select the
"deviousdungeon" configuration and press the run/play button.

#####The goal:
Reach the portal, doing this enough times takes you to the final boss room. Defeat the boss.

#####Player: 
Has 3 health, has 2 inventory spaces(one for melee weapons, and one for ranged weapons).

#####Movement: 
WASD keys allow the player to move left, right, up, and down on the board. Once the player moves to another tile that
previous tile becomes empty

#####Weapons: 
Melee weapons are used automatically when walking to an enemy tile. Ranged weapons can be used at any time by 
selecting a valid target with the mouse.
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

#####Uses:
* VisualStudio 2015
* Cinder
* Cmake