debugLogsOffline
----------------
Stores the game client api requests and their response.

areaObjects
-----------
Stores the current area objects in an area.

tipRelease
----------
Stores the changed area objects (if any) after the game client sends a request to the
"/tip/release" endpoint.
This table is read-only.

areaEnemies
-----------
Stores the current area enemies in an area.

areaItems
---------
Stores the current items in an area.

areaBgm
-------
Stores the current background music in an area

userData
--------
Stores key-value pairs. For now, it's used to persist the user status (position, areaId, etc)

gates
-----
Stores each gate teleport source position and their destination position.
This table is read-only.

characters
----------
Stores the hp and stats of the characters owned by the player.

tensionCards
------------
Stores the stats of the tension cards owned by the player

challengeProgresses
-------------------
Stores the current challenge progresses and their state

nineSequences
-------------
Stores the current nineSequences.

tips
----
Stores the already read game tips.

characterCostumes
-----------------
Stores the character costumes owned by the player

totalTasks
----------
Stores each task cleared and the number of times cleared

tutorialStates
--------------
Store each tutorial state and if it's enabled

shopProducts
------------
Stores shop products

battleParameters
----------------
Stores battle parameters. Each battle parameters is a group of enemies.
This table is read-only.

formations
----------
Stores formations. Each formation is composed of three characters and five tension cards.

readSequence
------------
Stores the changed area objects (if any) and changedResources (if any) in the response
of a "/adventure/read_sequence" api call.
This table is read-only

adventureVariables
------------------
Stores adventure variables

challengeTasks
--------------
Stores challenge tasks

battleFinishAreaObjects
-----------------------
Stores the changed area objects after a "/battle/finish" api call is made.
This table is read-only

areaActionSequenceIds
---------------------
Stores the current actionSequenceId (if any) of an area.

readSequenceAreaAction
----------------------
Stores the new actionSequenceId (if any) after an api call to "/adventure/read_sequence" is made.
This table is read-only.

readSequenceAreaBgm
-------------------
Stores the new areaBgm (if any) after an api call to "/adventure/read_sequence" is made.
This table is read-only.

areaItemRewards
---------------
Stores the reward of each areaItem (e.g., trash cans, chests).
This table is read-only.

questStates
-----------
Stores the clear count and best score of each node in Lux Phantasma

clearedAchievements
-------------------
Stores the clearead achievements (e.g. reach x score, full combo?) of each node in Lux Phantasma