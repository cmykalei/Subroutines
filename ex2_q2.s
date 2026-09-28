.text
.global main

main:
    # saves backups of register values on the stack frame
    subui $sp, $sp, 3   # pushes down a block of 3
    sw $ra, 2($sp)      # copies $ra into first-in block

    # calls the subroutine to read the switches
    jal readswitches    # jumps to subroutine, overrides $ra
    andi $9, $1, 255    # logical AND 'gets' (--------xxxxxxxx)
    srli $1, $1, 8      # logical shift right by 8 bits 
    andi $8, $1, 255    # logical AND 'gets' (xxxxxxxx--------)

    # copies the values into the stack frame
    sw $8, 1($sp)       # stores parameter 'end'
    sw $9, 0($sp)       # stores parameter 'start'
    
    # calls the subroutine to count the switches
    jal count
    lw $ra, 2($sp)      # restores return address location 
    addui $sp, $sp, 3   # pops the whole block off again
    jr $ra              # jumps and returns to specified $ra
      
