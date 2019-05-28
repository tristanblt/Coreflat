# Coreflat
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

# Our champion editor

![alt text](https://github.com/tristanblt/Coreflat/blob/master/bonus/assets/imgs/screen2.png)

Click on the instruction you want to add on the left of the screen.
You can then move it using the arrows.

You can add a register by dragging and dropping the desired register number directly into the instruction.

Type direct and indirect numbers using your keyboard and then drag and drop the 'n' into the instruction.

Add a label by clicking on the yellow '+' at left of the instruction.
To add a label as an argument, click on it (in the box just above the registers) and then drag and drop the n into the instruction you want.

Remove an instruction by clicking on the red X button next to the desired instruction.

Once you're done, save your champion.

/!\ DOCUMENTATION IN PROGRESS /!\

All code is made with <3
