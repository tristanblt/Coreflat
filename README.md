The Epitech CoreWar project, with a graphical interface, a champion editor, and a visualiser.

![alt text](https://github.com/tristanblt/Coreflat/blob/master/bonus/assets/imgs/screen1.png)

# How to use it ?

The standard ASM:

```
cd asm && make && ./asm [name of the .s file]
```

The standard CoreWar VM:

```
cd corewar && make && ./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
```

The disassembler:

```
cd asm && make bonus && ./disasm [input file .cor] [output file (optional)]
```

CoreFlat:

```
make coreflat && ./coreflat
```

# CoreFlat

Once launched, you can play the corewar, create and edit champions and visualise a champion. You can change the volume of the music in the settings.

# Playing the game

To play a normal game, click on Begin the war.

Choose the number of champions you want to see fighting, and then you will have to choose between an automatic and manual cycles per second.

If you choose automatic, the game is set to last exactly a minute (you will be able to accelerate it).

You can now choose your champions and their color if the random color is not to your liking.

Note that if you have more than 19 champions in the champion directory, some will not show up in the list.

# The champion editor

Click on Editor and choose between creating and editing a champion.
If you want to create a new champion, type it's name using your keyboard.

![alt text](https://github.com/tristanblt/Coreflat/blob/master/bonus/assets/imgs/screen2.png)

Click on the instruction you want to add on the right of the screen.
You can then move it using the arrows.

You can add a register by dragging and dropping the desired register number directly into the instruction's argument.

Type direct and indirect numbers using your keyboard and then drag and drop the 'n' into the instruction's argument.

Add a label by clicking on the yellow '+' left of the instruction.
To add a label as an argument, click on it (in the box just above the registers) and drag and drop the n into the instruction's argument.

Remove an instruction by clicking on the red X button next to the undesired instruction.

Once you're done, save your champion and it'll be ready to go!

# The visualiser

The visualiser lets you see what your champion does by itself in the memory. In this mode, it cannot die and it will not stop until you close Coreflat.

# Music

Music by BROME (https://soundcloud.com/blazornet)

All code is made with <3
