# Logic-Gates-Simulator

## Some basics
* At first, we'll need a ```.cir``` file which we will initialize our gates, inputs, outputs and start the simulation.

* in the ```.cir```, a simple ANDgate is initialized like this: ``` AND A B C ```, and this line means that we want to initialize an AND gate with the inputs called A and B, and the output called C.

* to initialize the values of the nodes themselves, use something like the line ``` SET A 1```, which indicates that the first input of the ANDgate, A is 1 or High.

* Nodes can stack to more than one gate, e.g. we can assign the node A to another gate of any type, which indicates that this particular input node is wired to two different logic gates.

* The command ```SIM```, when typed in the ```.cir``` file, will evaluate all the output nodes of the gates, e.g. calculate the value of the output nodes assigned to each gate.

* After the simulation using the ```SIM``` command, we can output the values of the nodes by using the ```OUT``` command.

* The ```OUT``` command, if followed by a name of a node, it will print to the console only the value of this node, e.g. ```OUT A``` will print the value of the node A to the console, ```OUT C``` will print the value of the node C, which is the output node of the ANDgate we initialized.

* if the ```OUT``` command is followed by the command ```ALL```, which means typing ```OUT ALL``` in the ```.cir``` file, the program will print all the nodes in the simulator.

* An example input for the simulator to evaluate the output in the case of specified inputs in the ```.cir``` file would look like this:
```
AND  A B C
OR   C E D
NAND C D F
SET    A 1
SET    B 0
SET    E 1
SIM
OUT    ALL
```
* Which shall print this result to the console:
```
A 1
B 0
C 0
E 1
D 1
F 1
```

## Truth Table:
* if the ```TSETIN``` command is followed by a name of a node, It's going to be assigned as an input node for the circuit and it will be considered in the truth table as an input node.

* if the ```TSETOUT``` command is followed by a name of a node, It's going to be assigned as an output node for the circuit and it will be considered in the truth table as an output node.

* the ```TRUTH``` command is used to print out the truth table of the circuit using the input nodes assigned by the ``TSET``` command.

* An example input for the simulator to evaluate the truth table for the specified input nodes would look like:
```
XOR A B S
AND A B C
TSETIN A
TSETIN B
TSETOUT S
TSETOUT C
TRUTH
```

* Firstly, initialize a ```Simulator``` object using the default constructor. And call the ```load()``` method passing the ```.cir``` file name as a string parameter.
