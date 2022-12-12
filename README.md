# PA4: Pokemon Game

## Starting Object Location: 
Starting the game, there are 7 objects in total:
- G1: Gym 1, located at (0,0)
- G2: Gym 2, located at (5,5)
- C1: Center 1, located at (1,20)
- C2: Center 2, located at (10,20)
- T1: Trainer 1, located at (5,1)
- T2: Trainer 2, located at (10,1)
- W1: WildPokemon 1, located at (10,12)
- W2: WildPokemon 2, located at (15,5)

## Game Commands:
There are several commands you can use to play this game:
1. **n <object_char> <id_num> <x_position> <y_position>**

    for example:
    ```
    n C 3 15 9
    ```
    This will create a new PokemonCenter C3 at (15,9)

2. **m <trainer_id> <x_position> <y_position>**

    for example:
    ```
    m 1 10 12
    ```
    This will move trainer 1 to (10,12)

3. **c <trainer_id> <center_id>**

    for example:
    ```
    c 1 1
    ```
    this will move trainer 1 to center 1

4. **g <trainer_id> <gym_id>**

    for example:
    ```
    g 1 1
    ```
    this will move trainer 1 to gym 1

5. **s <trainer_d>**

    for example:
    ```
    s 2
    ```
    this will stop trainer 2 

6. **p <trainer_id> <center_id>

    for example:
    ```
    p 1 2
    ```
    this will recover trainer 1's health in center 2
    will not recover health if trainer 1 is not inside center 2

7. **b <trainer_id> <gym_id>**

    for example:
    ```
    b 1 2
    ```
    this will allow trainer 1 to battle in gym 2
    will not battle if trainer 1 is not inside gym 2

8. **a**

    for example: 
    ```
    a
    ```
    advance the game 1 tick. 

9. **r**

    for example:
    ```
    r
    ```
    advance the game 5 ticks

10. **q**

    for example:
    ```
    q
    ```
    Quit the game. Terminate the program


## How Trainer Behave: 
Stating the game, each trainer will have:
- 25 health
- 0 experiences
- 0 pokedollars. 

Everytime the trainer moves, the trainer will lose 1 health:
- Trainer lose 1 health when moves 1 tick

However, the trainer will also gain a random number of pokedollar each time it moves
- trainer gain a random amount of (between $0.0-$2.0) pokedollar when it moves (1 tick)

So, the trainer loses health when it moves but gains pokedollars in the meanwhile. 

