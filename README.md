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
- From after tutorial skip, until before Zero's XB
- Lux Phantasma (needs tp to Mita's Hideout)