Tribe Nine Zero
---------------

TNZ is a program that intercepts the messages sent from the game client to the (now dead) game server
and provides an offline substitute for the responses.

What's the purpose of each binary? 
----------------------------------
- libzero.dll: loads the hooks needed to implement offline mode
- loader.exe: executes the game and injects libzero.dll
- launcher.exe:
  helper gui that asks for the location of the game executable to cache it, and launchs
  the loader
- semba.db: database that stores the player progress and game objects (quests, area enemies, etc)

What's working?
---------------
- From after tutorial skip, until [this part](https://youtu.be/dLCiWCpVHPs?t=8492)
- The standard gacha
- Most enemy drops
- Lux Phantasma (needs tp to Mita's Hideout)

Build instructions
------------------
See [build.md](docs/build.md)

Useful links
------------
- [Il2CppDumper dumper_out](https://www.dropbox.com/scl/fi/qe7ezmjuvr7lr6nma9klv/dumper_out.zip?rlkey=o8o3lv9890fwj7q8lenq7ps1w&st=ovmpeizh&dl=1) (has the signatures of the game functions and the C++ structures used in il2cpp)
- [onlineLogs JSON](https://www.dropbox.com/scl/fi/8m8shj74l2ot6rx8093yw/04_onlineLogsClean.zip?rlkey=duvtjj9efq8hi8up5tdbnbqc5&st=o52vqyjx&dl=1) (JSON req/res pairs of the game playthrought)
- [July 11th masterData](https://www.dropbox.com/scl/fi/9et45rtt8wy0yd5kuflg5/July-11th-Masterdata.zip?rlkey=r79qb7wbwd7aeebzkkr5mf8lv&st=c0hwrdor&dl=1) (used to implement some endpoints of the server part)
- [Protobuf objects](https://24tribe.github.io/dev/protobuf_objects/) (protobuf objects used in the responses of the server part (as JSON))
- [Save files](https://www.dropbox.com/scl/fo/lfzs6dt7olmwlcc282u8r/AOTzVRqFihit2j0iYkD8UTA?rlkey=lkcaixtwnvyn8ofn120aofxq8&st=ggsuow07&dl=0)

High-level flow chart
---------------------
<img width="536" height="726" alt="highlevelflowchart" src="https://github.com/user-attachments/assets/3acc79b9-6884-4e62-81e6-c0e42aee0143" />
