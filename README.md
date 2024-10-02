![Static Badge](https://img.shields.io/badge/School_42-Antananarivo_Madagascar-green?logo=42) ![Static Badge](https://img.shields.io/badge/System_Linux-Ubuntu-green) ![Static Badge](https://img.shields.io/badge/Language-C-blue) ![Static Badge](https://img.shields.io/badge/Subject-fr-blue) ![Static Badge](https://img.shields.io/badge/Total_point_%2B_bonus-125pts_outstanding-green) ![Static Badge](https://img.shields.io/badge/Norminette_V4-done-green) ![Static Badge](https://img.shields.io/badge/Leaks-No_leaks-green)

# Resume

The aim of this project is to have you create a small data exchange program using UNIX signals.

# Introduction 

The minitalk communication protocol involves sending messages between two processes using a series of signals over a single wire. 

-One process, called the "speaker/client" sends the message by transmitting a series of signals over the wire. 

-The other process, called the "listener/server" receives the message by interpreting the series of signals as a message.

![schema](https://42-cursus.gitbook.io/~gitbook/image?url=https%3A%2F%2F2977649544-files.gitbook.io%2F%7E%2Ffiles%2Fv0%2Fb%2Fgitbook-x-prod.appspot.com%2Fo%2Fspaces%252Fz2zo8aAL0o31034sj7J7%252Fuploads%252F5eY61q1QT9MHUx2Zxf7g%252Fminitalk_scheme.png%3Falt%3Dmedia%26token%3D22a960bd-d30e-4e73-a4e7-a683b9c4d931&width=768&dpr=4&quality=100&sign=967dfba2&sv=1) 

<font color="red">**NB**: The message received by the server must be displayed only once, but not per character. Like this: </font>

![visualizer](https://github.com/PrincyRaks/minitalk/blob/main/GIF/minitalk.gif)

**For 150 paragraphs of execution ≃ 2.s✨**

# Documentation

The subjects of this project is [here](https://github.com/PrincyRaks/minitalk/blob/main/fr.subject_2.pdf)

For more understand the subject, I visit the website [Gitbook42](https://42-cursus.gitbook.io/guide/rank-02/minitalk)

## Test
You can test this project if you have compiler C in your device :

- `git clone git@github.com:PrincyRaks/minitalk.git`
- open terminal and execute the following commands :
 - `cd minitalk/`
 - execute `make` for mandatory :
  - Firstly, launch server `./server`
  - Copy the PID and paste in the client with the message, `./client <PID_server> "The message here"`
- `make bonus` for bonus project and execute, launch `./server_bonus` then `./client_bonus`
