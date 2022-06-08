.model tiny
org 100h
    
print_shot macro 
    mov ax, [bx + 2] 
    push bx
    mov bx, 80
    mul bx
    pop bx
    add ax, [bx + 4] 
    mov di, ax       
    shl di, 1 
    mov ax, si
    stosw
endm

shift_tanks macro tanks_count
    push bx
    push cx
    
    inc cx
    sub cx, tanks_count
    neg cx
    cmp cx, 0
    je shift_tanks_end
    
shift_tanks_cycle:
    mov dx, [bx + 6]
    mov [bx], dx 
    mov dx, [bx + 8]
    mov [bx + 2], dx
    mov dx, [bx + 10]
    mov [bx + 4], dx
    add bx, 6
    dec cx
    cmp cx, 0
    jne shift_tanks_cycle    

shift_tanks_end:     
    pop cx
    pop bx
endm
    
    .code     
main:
    mov ax, 0003h
    int 10h
    
    mov ah, 02h
    mov dh, 26   
    xor dl, dl  
    int 10h
    
    mov ax, 0b800h
    mov es, ax
    
    mov ah, 00h
    int 1ah
    mov clock_ticks_low, dx
    mov clock_ticks_high, cx
    
game_loop:            
    call update_time 
    call print_time   
      
    mov dx, delay_timer  
    cmp dx, delay
    jl game_loop
    mov delay_timer, 0
   
    call get_char
  
    cmp al, 'e'
    jz main_return  
    
    cmp hq_hp, 0
    jz main_return  
    
    push player_x
    push player_y
    push player_frame
    call redirect 
    pop player_frame
    pop player_y
    pop player_x 
    
    call update_shots 
    cmp game_over, 1
    je main_return
    
    call update_enemies 
     
    call print_map
    call print_hq
    
    mov ah, 0Ah 
    push player_x
    push player_y
    push player_frame    
    call print_tank   
    add sp, 6
    
    call print_enemies    
    call print_shots
    
    jmp game_loop
    
main_return:
   
    mov ah, 02h
    xor dx, dx
    int 10h      
    
    mov ax, 0003h
    int 10h

    int 20h 
         
proc print_map
    xor di, di        
    mov cx, 80 * 25   
    mov ah, 0fh       
    mov bx, offset map
    cld    
print_loop:
    mov al, [bx]
    stosw
    inc bx
    dec cx
    jnz print_loop
    
    ret   
endp print_map


proc print_tank    
    push bp
    mov bp, sp    
    cld       
   
   
    mov bx, [bp + 4]
    shl bx, 1
    mov si, frames[bx] 
    mov bx, 80
   
    push ax
    mov ax, [bp + 6]
    mul bx
    mov di, ax
    pop ax
    
    add di, [bp + 8]
    shl di, 1 
    sub bx, tank_size
    shl bx, 1  
    mov ch, tank_size   
   
tank_print:
    mov cl, tank_size
tank_print_cycle:
    lodsb 
    cmp al, ' '
    jne print_tile
    add di, 2
    jmp printed
print_tile:
    stosw 
printed:
    dec cl
    jnz tank_print_cycle
    add di, bx
    dec ch
    jnz tank_print   
   
    pop bp 
    ret
endp print_tank

proc print_enemies
    push bp       
    mov bp, sp
    
    mov cx, enemies_count 
    mov bx, offset enemies
    
print_enemies_cycle:
    cmp cx, 0
    je print_enemies_return
    mov ah, 0Ch
    push cx
    push bx
    push [bx + 4]
    push [bx + 2]
    push [bx]
    call print_tank
    add sp, 6
    pop bx
    pop cx
    add bx, 6
    dec cx
    jmp print_enemies_cycle 
    
print_enemies_return:
    pop bp 
    ret    
endp print_enemies

proc print_shots
    cld 
    xor cx, cx 
    mov si, 0ab1h
    mov bx, offset player_shots
    
print_player_shots:
    cmp cx, player_shots_count
    je print_enemies_shots
    print_shot
    inc cx
    add bx, 6
    jmp print_player_shots
    
print_enemies_shots:
    mov bx, offset enemies_shots
    xor cx, cx
    mov si, 0cb1h
    
print_enemies_shots_cycle:  
    cmp cx, enemies_shots_count
    je print_shots_return
    print_shot
    inc cx
    add bx, 6
    jmp print_enemies_shots_cycle
    
print_shots_return:
    ret
endp print_shots

proc redirect
    push bp
    mov bp, sp
    
    mov bx, [bp + 4] ;frame
    mov cx, [bp + 6] ;y
    mov dx, [bp + 8] ;x
    
    cmp al, 'w'
    jne cmp_a
    cmp bx, 0 
    je move_up
    cmp bx, 2 
    jne switch_to_up
    dec cx    
switch_to_up:
    xor bx, bx
    jmp redirect_check
move_up:
    dec cx
    jmp redirect_check 
   
cmp_a:
    cmp al, 'a'
    jne cmp_s  
    cmp bx, 3 
    je move_left
    cmp bx, 1 
    jne switch_to_left
    dec dx    
switch_to_left:
    mov bx, 3
    jmp redirect_check
move_left:
    dec dx
    jmp redirect_check 
    
cmp_s:
    cmp al, 's'
    jne cmp_d
    cmp bx, 2
    je move_down
    cmp bx, 0
    jne switch_to_down
    inc cx  
switch_to_down:
    mov bx, 2
    jmp redirect_check
move_down:
    inc cx
    jmp redirect_check
    
cmp_d:
    cmp al, 'd'
    jne cmp_f
    cmp bx, 1 
    je move_right
    cmp bx, 3
    jne switch_to_right
    inc dx
switch_to_right:
    mov bx, 1
    jmp redirect_check
move_right:
    inc dx
    jmp redirect_check
    
cmp_f:
    cmp al, 'f'
    jne redirect_return
     
    cmp dx, player_x
    jne allow_shooting
    cmp cx, player_y
    jne allow_shooting
    cmp player_delay, 0
    je redirect_return
    mov player_delay, 0

allow_shooting:    
    push dx
    push cx
    push bx
    call shoot
    pop bx
    pop cx
    pop dx
    mov ax, 1
    jmp redirect_return
            
redirect_check:    
    push dx
    push cx
    push bx
    call is_movement_possible   
    pop bx
    pop cx
    pop dx
    
    cmp ax, 1
    jne redirect_return
    
    mov [bp + 4], bx
    mov [bp + 6], cx
    mov [bp + 8], dx    
   
redirect_return:    
   pop bp 
   ret  
redirect endp

proc shoot
    push bp
    mov bp, sp
    
    mov bx, [bp + 4]
    mov cx, [bp + 6]
    mov dx, [bp + 8]
    
    cmp bx, up
    je first_frame
    cmp bx, right
    je second_frame
    cmp bx, down
    je third_frame
    jmp fourth_frame
    
first_frame:
    inc dx
    mov ax, up
    jmp add_shot
    
second_frame:
    add dx, 2
    inc cx    
    mov ax, right
    jmp add_shot
    
third_frame:
    inc dx
    add cx, 2   
    mov ax, down
    jmp add_shot
    
fourth_frame:
    inc cx  
    mov ax, left

add_shot:    
    mov si, [bp + 6]
    cmp si, player_y
    jne enemie_shoot
    mov si, [bp + 8]
    cmp si, player_x
    jne enemie_shoot
    
    mov di, max_player_shots
    cmp player_shots_count, di
    
    je shoot_return
    push dx
    push ax
    mov ax, player_shots_count
    shl ax, 1
    mov bx, 3
    mul bx
    mov bx, ax
    pop ax
    pop dx
    mov player_shots[bx], ax
    mov player_shots[bx + 2], cx
    mov player_shots[bx + 4], dx
    inc player_shots_count
    jmp shoot_return
 
enemie_shoot:
    cmp enemies_shots_count, max_enemies_count
    je shoot_return 
    push dx
    push ax
    mov ax, enemies_shots_count
    shl ax, 1
    mov bx, 3
    mul bx
    mov bx, ax
    pop ax
    pop dx
    mov enemies_shots[bx], ax
    mov enemies_shots[bx + 2], cx
    mov enemies_shots[bx + 4], dx
    inc enemies_shots_count

shoot_return:    
    pop bp
    ret
shoot endp
  
proc update_shots
    mov cx, 2
    push cx
    
update_shots_cycle:    
    xor cx, cx
    mov bx, offset player_shots

update_player_shots:
    cmp cx, player_shots_count
    je update_enemies_shots    
    call check_for_shot_collision
    cmp ax, 1
    jne delete_shot    
    mov si, offset enemies_shots
    push enemies_shots_count
    call check_for_shots_shots_coll
    pop dx
    mov enemies_shots_count, dx
    cmp ax, 0
    je delete_shot     
    call check_for_shot_hq_coll
    cmp ax, 1
    je check_for_hits
    dec hq_hp
    jmp delete_shot
check_for_hits:
    push [bx + 4]
    push [bx + 2]
    call check_for_shot_tanks_coll
    add sp, 4 
    cmp ax, -1
    je update_player_shots_end
    push bx
    push cx
    mov cx, ax
    mov bx, offset enemies
get_tank_offset:
    cmp ax, 0
    je delete_tank
    add bx, 6
    dec ax
    jmp get_tank_offset
delete_tank:
    shift_tanks enemies_count
    dec enemies_count
    pop cx
    pop bx
delete_shot:
    push player_shots_count
    call shift_shots
    pop player_shots_count
    dec cx
    dec player_shots_count
        
update_player_shots_end:    
    inc cx                 
    add bx, 6
    jmp update_player_shots 
    

update_enemies_shots:
    mov bx, offset enemies_shots
    xor cx, cx
    
update_enemies_shots_cycle: 
    cmp cx, enemies_shots_count
    je update_shots_cycle_end
    call check_for_shot_collision
    cmp ax, 0
    je delete_enemy_shot
    call check_for_player_hit
    cmp ax, 1
    jne player_was_hit
    jmp player_wasnt_hit
player_was_hit:
    mov game_over, 1 
    pop cx
    jmp update_shots_return
player_wasnt_hit:    
    mov si, offset player_shots
    push player_shots_count
    call check_for_shots_shots_coll
    pop dx
    mov player_shots_count, dx
    cmp ax, 0
    je delete_enemy_shot      
    push [bx + 4]
    push [bx + 2]
    call check_for_shot_tanks_coll
    add sp, 4
    cmp ax, -1
    jne delete_enemy_shot    
    call check_for_shot_hq_coll
    cmp ax, 1
    je update_enemies_shots_cycle_end
    
delete_enemy_shot:  
    push enemies_shots_count
    call shift_shots
    pop enemies_shots_count
    dec cx
    dec enemies_shots_count
update_enemies_shots_cycle_end:
    inc cx
    add bx, 6
    jmp update_enemies_shots_cycle
update_shots_cycle_end:    
    pop cx   
    dec cx
    cmp cx, 0
    je update_shots_return
    push cx
    jmp update_shots_cycle    

update_shots_return:            
    ret
update_shots endp 

proc check_for_shots_shots_coll 
    push bp
    mov bp, sp
    push cx
    
    mov ax, 1
    xor cx, cx
    
shots_shots_cycle:
    cmp cx, [bp + 4]
    je check_for_shots_shots_return
    
    mov dx, [bx + 2]
    cmp dx, [si + 2]
    jne shots_shots_cycle_end
    mov dx, [bx + 4]
    cmp dx, [si + 4]
    jne shots_shots_cycle_end
    
    push bx
    mov bx, si
    mov dx, [bp + 4]
    push dx
    call shift_shots
    pop dx  
    dec dx
    mov [bp + 4], dx
    pop bx
    xor ax, ax
    jmp check_for_shots_shots_return
shots_shots_cycle_end:
    add si, 6
    inc cx
    jmp shots_shots_cycle
         
check_for_shots_shots_return:    
    pop cx 
    pop bp
    ret
check_for_shots_shots_coll endp

proc shift_shots
    push bp
    mov bp, sp
    
    push bx
    push cx
    
    inc cx
    sub cx, [bp + 4]
    neg cx
    cmp cx, 0
    je shift_shots_end
    
shift_shots_cycle:
    mov dx, [bx + 6]
    mov [bx], dx 
    mov dx, [bx + 8]
    mov [bx + 2], dx
    mov dx, [bx + 10]
    mov [bx + 4], dx
    add bx, 6
    dec cx
    cmp cx, 0
    jne shift_shots_cycle    

shift_shots_end:     
    pop cx
    pop bx
    pop bp
    ret
shift_shots endp


proc check_for_shot_hq_coll
    mov ax, 1    
    mov dx, [bx + 2]
    cmp [bx + 2], hq_y
    jl no_shot_hq_coll
    sub dx, hq_size
    cmp dx, hq_y
    jge no_shot_hq_coll
    mov dx, [bx + 4]
    cmp dx, hq_x
    jl no_shot_hq_coll
    sub dx, hq_size
    cmp dx, hq_x
    jge no_shot_hq_coll
    xor ax, ax 
no_shot_hq_coll:
    ret 
check_for_shot_hq_coll endp
  
  
proc check_for_player_hit
    push bp
    mov bp, sp
    push bx
          
    mov dx, [bx + 2]
    mov ax, [bx + 4]
          
    cmp dx, player_y
    jl no_player_hit
    sub dx, tank_size
    cmp dx, player_y
    jge no_player_hit
    cmp ax, player_x
    jl no_player_hit
    sub ax, tank_size 
    cmp ax, player_x
    jge no_player_hit
    
check_player_tile:
    push cx
    xor cx, cx      ;ch - x, cl - y
    add dx, tank_size
    add ax, tank_size
    mov si, player_y
    mov di, player_x
check_player_tile_y:
    cmp dx, si
    je check_player_tile_x
    inc si
    inc cl
    jmp check_player_tile_y
check_player_tile_x:
    cmp di, ax
    je check_for_player_tile_coll
    inc di
    inc ch
    jmp check_player_tile_x
check_for_player_tile_coll: 
    push bx
    mov bx, player_frame
    shl bx, 1
    mov ax, frames[bx]
    xchg bx, ax ;bx points on player's tank
get_player_tile_y_offset:
    cmp cl, 0
    je get_player_tile_x_offset
    add bx, tank_size
    dec cl
    jmp get_player_tile_y_offset
get_player_tile_x_offset:
    cmp ch, 0
    je check_for_player_tile
    add bx, 1
    dec ch
    jmp get_player_tile_x_offset
check_for_player_tile:
    cmp [bx], 0b1h       
    je shot_player_collision
    pop bx      
    pop cx
    jmp no_player_hit     

shot_player_collision:
    pop bx
    pop cx
    xor ax, ax
    jmp check_for_player_hit_return
    
no_player_hit:
    mov ax, 1 
 
check_for_player_hit_return:          
    pop bx      
    pop bp
    ret
check_for_player_hit endp


proc check_for_shot_tanks_coll
    push bp
    mov bp, sp
    push bx 
    push cx
    
    mov bx, offset enemies
    xor cx, cx
   
shot_tanks_coll_cycle:
    mov ax, -1
    cmp cx, enemies_count
    je check_for_shot_tanks_coll_return 
    
    mov dx, [bp + 4]  ;load shot's y
    mov ax, [bp + 6]  ;load shot's x
      
    cmp dx, [bx + 2]
    jl shot_tanks_coll_cycle_end
    sub dx, tank_size
    cmp dx, [bx + 2]
    jge shot_tanks_coll_cycle_end
    cmp ax, [bx + 4]
    jl shot_tanks_coll_cycle_end
    sub ax, tank_size
    cmp ax, [bx + 4]
    jge shot_tanks_coll_cycle_end
    
check_tile:
    push cx
    xor cx, cx      ;ch - x, cl - y
    add dx, tank_size
    add ax, tank_size
    mov si, [bx + 2]
    mov di, [bx + 4]
check_tile_y:
    cmp dx, si
    je check_tile_x
    inc si
    inc cl
    jmp check_tile_y
check_tile_x:
    cmp di, ax
    je check_for_tile_coll
    inc di
    inc ch
    jmp check_tile_x
check_for_tile_coll: 
    push bx
    mov ax, [bx]
    xchg ax, bx
    shl bx, 1
    mov ax, frames[bx]
    xchg ax, bx  ;bx points on tank
get_tile_y_offset:
    cmp cl, 0
    je get_tile_x_offset
    add bx, tank_size
    dec cl
    jmp get_tile_y_offset
get_tile_x_offset:
    cmp ch, 0
    je check_for_tile
    add bx, 1
    dec ch
    jmp get_tile_x_offset
check_for_tile:
    cmp [bx], 0b1h       
    je shot_tank_collision
    pop bx      
    pop cx
    jmp shot_tanks_coll_cycle_end
shot_tank_collision:
    pop bx  
    pop cx
    mov ax, cx
    jmp check_for_shot_tanks_coll_return
    
shot_tanks_coll_cycle_end:
    inc cx
    add bx, 6
    jmp shot_tanks_coll_cycle                          
    
check_for_shot_tanks_coll_return:    
    pop cx
    pop bx
    pop bp
    ret
check_for_shot_tanks_coll endp


proc check_for_shot_collision        
    cmp [bx], up
    je move_shot_up
    cmp [bx], right
    je move_shot_right
    cmp [bx], down
    je move_shot_down
    
move_shot_left:
    dec [bx + 4]
    jmp check_for_shot_coll
move_shot_up:
    dec [bx + 2]
    jmp check_for_shot_coll
move_shot_right:
    inc [bx + 4]
    jmp check_for_shot_coll
move_shot_down:
    inc [bx + 2]   

check_for_shot_coll:
    mov si, [bx + 4]    
    push bx          
    mov ax, [bx + 2]           
    mov bx, 80
    mul bx
    add ax, si 
    mov bx, ax 
    mov ax, 1
    cmp map[bx], ' '
    je no_shot_collision
    xor ax, ax       

no_shot_collision:
    pop bx         
    ret
check_for_shot_collision endp   


proc is_movement_possible
    push bp
    mov bp, sp    
    xor ax, ax
    
    cmp [bp + 8], 0
    je is_movement_possible_return
    cmp [bp + 8], 77
    je is_movement_possible_return
    cmp [bp + 6], 0
    je is_movement_possible_return
    cmp [bp + 6], 22
    je is_movement_possible_return
   

    mov bx, [bp + 4]
    shl bx, 1
    mov si, frames[bx]; si points on tank 
    mov bx, 80
    
    mov di, offset map
    mov ax, [bp + 6]
    mul bx
    add di, ax    
    add di, [bp + 8] ;di points on map   
    sub bx, tank_size
    mov ch, tank_size   
   
check_on_collisions:
    mov cl, tank_size
check_on_collisions_cycle:
    cmp [di], '#'
    jne check_on_collisions_cycle_end
    cmp [si], 0b1h
    jne check_on_collisions_cycle_end
    xor ax, ax
    jmp is_movement_possible_return
check_on_collisions_cycle_end:
    inc si
    inc di
    dec cl
    jnz check_on_collisions_cycle
    add di, bx
    dec ch
    jnz check_on_collisions
    
    mov bx, [bp + 4]
    shl bx, 1
    mov si, frames[bx]; si points on tank
    mov bx, 80
    sub bx, tank_size 
    mov ch, tank_size   
       
check_on_hq_coll:
    mov cl, tank_size
check_on_hq:
    cmp [si], 0b1h
    jne check_on_hq_coll_end
    mov ax, [bp + 8]; tank left high corner x coordinate
    push cx
get_tile_x:
    cmp cl, tank_size
    je cmp_x
    inc cl
    inc ax
    jmp get_tile_x
cmp_x:
    pop cx
    cmp ax, hq_x
    jl check_on_hq_coll_end
    sub ax, hq_size
    cmp ax, hq_x
    jge check_on_hq_coll_end
    mov ax, [bp + 6] ;tank left high corner y coordinate
    push cx
get_tile_y:
    cmp ch, tank_size
    je cmp_y 
    inc ax
    inc ch
    jmp get_tile_y
cmp_y:
    pop cx
    cmp ax, hq_y
    jl check_on_hq_coll_end
    sub ax, hq_size 
    cmp ax, hq_y
    jge check_on_hq_coll_end 
    xor ax, ax
    jmp is_movement_possible_return
check_on_hq_coll_end:
    inc si
    dec cl
    jnz check_on_hq
    add di, bx
    dec ch
    jnz check_on_hq_coll
    
    push [bp + 8]
    push [bp + 6]
    push [bp + 4]   
    call check_for_coll_with_tanks 
    add sp, 6
    cmp ax, 1
    jne is_movement_possible_return    
    
movement_is_possible:   
    mov ax, 1  
is_movement_possible_return:
    pop bp   
    ret
is_movement_possible endp


   
proc check_for_coll_with_tanks
    push bp
    mov bp, sp
    xor di, di
    mov ax, 1
    
    cmp enemies_count, 0
    je check_for_tanks_coll_return
    
    mov bx, [bp + 4]
    shl bx, 1
    mov si, frames[bx]; si points on tank
    mov bx, offset enemies
    add bx, 2
    mov cx, enemies_count

check_for_tanks_coll:   
    mov ax, [bx]    ; load another tank's y coordinate
    mov dx, [bx + 2]; load another tank's x coordinate   
    
another_tank:
    sub ax, tank_size
    cmp [bp + 6], ax     ;compare y
    jle no_intersection
    add ax, tank_size
    add ax, tank_size
    cmp [bp + 6], ax
    jge no_intersection 
    sub dx, tank_size
    cmp [bp + 8], dx     ;compare x
    jle no_intersection
    add dx, tank_size
    add dx, tank_size
    cmp [bp + 8], dx
    jge no_intersection
    
    inc di
    cmp di, 2
    jl no_intersection
    xor ax, ax
    jmp check_for_tanks_coll_return
                                           
no_intersection:
    add bx, 6; go to next tank y coordinate
    mov ax, 1
    dec cx 
    cmp cx, 0
    jg check_for_tanks_coll        
    jl check_for_tanks_coll_return 
    mov bx, offset player_y
    jmp check_for_tanks_coll 
    
check_for_tanks_coll_return:    
    pop bp
    ret
endp check_on_coll_with_tanks

proc update_enemies
    call add_new_enemy
    
    xor cx, cx
    mov bx, offset enemies
    
update_enemies_loop:
    cmp cx, enemies_count
    je update_enemies_return
    
    push bx
    mov bx, offset enemies_delays
    add bx, cx
    cmp [bx], 1
    jne continue_moving  
    mov [bx], 0
    pop bx
    mov al, 'f'
    jmp move_enemie  

continue_moving:
    pop bx 
        
    cmp [bx], up
    je moving_up
    cmp [bx], right
    je moving_right
    cmp [bx], down
    je moving_down
    cmp [bx], left
    je moving_left
    
moving_up:
    mov al, 'w'   
    jmp move_enemie    
moving_right:
    mov al, 'd'   
    jmp move_enemie    
moving_down:
    mov al, 's'   
    jmp move_enemie
moving_left:
    mov al, 'a'   

move_enemie:
    push cx
    push bx
    push [bx + 4]; x
    push [bx + 2]; y
    push [bx]    ; frame
    call redirect
    pop dx
    pop si
    pop di
    pop bx
    pop cx    
    mov [bx], dx
    mov [bx + 2], si
    mov [bx + 4], di      
         
    cmp ax, 1
    je update_enemies_loop_end
    inc [bx] ;change tank's direction
    cmp [bx], 4
    jl update_enemies_loop_end
    mov [bx], 0  
     
update_enemies_loop_end:
    add bx, 6
    inc cx
    jmp update_enemies_loop   

update_enemies_return:    
    ret
endp update_enemies

proc add_new_enemy           
    mov di, min_enemies_count
    cmp enemies_count, di
    jl create_enemy
    cmp allow_to_add_enemy, 1
    jne add_new_enemy_return
    cmp enemies_count, max_enemies_count
    je add_new_enemy_return
    
create_enemy:
    mov ax, enemies_count
    mov bx, 3
    mul bx
    shl ax, 1
    xchg ax, bx
    mov dx, new_enemy_dir
    mov enemies[bx], dx    
    mov dx, new_enemy_y
    mov enemies[bx + 2], dx
    mov dx, new_enemy_x
    mov enemies[bx + 4], dx
    
    inc enemies_count
    push new_enemy_x
    push new_enemy_y
    push new_enemy_dir
    call is_movement_possible
    add sp, 6
    dec enemies_count
    cmp ax, 1
    jne add_new_enemy_return
    
    inc enemies_count
    mov allow_to_add_enemy, 0
    sub new_enemy_x, 2
    cmp new_enemy_x, 3
    jg correct_x
    mov new_enemy_x, 75
correct_x:
    inc new_enemy_dir
    cmp new_enemy_dir, 4
    jl add_new_enemy_return
    mov new_enemy_dir, 0
    
add_new_enemy_return:
    ret
endp add_new_enemy

proc get_char
    mov ah, 06h
    mov dl, 0ffh 
    int 21h        
    push ax
    mov ah, 0ch
    xor al, al
    int 21h        
    pop ax   
    ret
endp get_char


proc itoa 
    xor cx, cx                      
    cmp ax, 0
          
itoa_cycle:
    cmp ax, 10
    jl itoa_end
    xor dx, dx
    push bx
    mov bx, 10           
    div bx
    pop bx
    add dl, 48
    push dx
    inc cx
    jmp itoa_cycle
    
itoa_end:  
    mov [bx], al
    add [bx], 48
    inc bx

itoa_fill_string:
    cmp cx, 0
    je itoa_return    
    pop dx
    mov [bx], dl
    inc bx
    dec cx
    jmp itoa_fill_string 

itoa_return:     
    mov [bx], '$'      
    ret
itoa endp


print_string proc
     mov ah, 09h
     int 21h
     ret
print_string endp 

proc update_time 
   
    mov ah, 00h
    int 1ah
    
    cmp al, 1
    je update_time_return
    
    push cx
    push dx
    
    sub dx, clock_ticks_low
    sbb cx, clock_ticks_high
    
    add timer, dx
    add delay_timer, dx
    
    pop clock_ticks_low
    pop clock_ticks_high
    
    cmp timer, 18
    jl update_time_return
    
    inc adding_delay_timer
    cmp adding_delay_timer, delay_to_add_enemy
    jl set_shooting_delays
    mov allow_to_add_enemy, 1
    mov adding_delay_timer, 0

set_shooting_delays:
    mov player_delay, 1    
    mov bx, offset enemies_delays
    xor cx, cx  
    
update_enemies_delays:
    cmp cx, enemies_count    
    je update_timer
    mov [bx], 1 
    inc cx
    inc bx
    jmp update_enemies_delays
    
update_timer:    
    mov timer, 0
    inc seconds
    cmp seconds, 60
    jl update_time_return
    mov seconds, 0
    inc minuetes
    
update_time_return:    
    ret
update_time endp


proc print_time
    mov bx, offset buffer
    mov ax, minuetes    
    cmp ax, 9
    jg minuetes_double_digit
    mov [bx], '0'
    inc bx    
minuetes_double_digit:       
    call itoa
    mov [bx], ':'
    inc bx
    mov ax, seconds
    cmp ax, 9
    jg seconds_double_digit
    mov [bx], '0'
    inc bx
seconds_double_digit:
    call itoa
    
    mov ah, 0fh ;attribute
    mov cx, 5   ;symbol counter
    mov si, offset buffer
    mov di, 37  ;starting address to output time
    shl di, 1
    cld

print_time_cycle:    
    lodsb ;al = ds:[si]
    stosw ;es:[di] = ax
    dec cx
    test cx, cx
    jnz print_time_cycle
    
    ret   
print_time endp


proc print_hq      
    mov ax, hq_y
    mov bx, 80
    mul bx
    mov di, ax    
    add di, hq_x
    shl di, 1 
    sub bx, hq_size
    shl bx, 1  
    mov ch, hq_size
    
    mov ah, 0Ch     ;load attribute
    mov al, hq_tile ;load symbol 
    cld    
   
hq_print:
    mov cl, hq_size
hq_print_cycle:
    stosw ;es:[di] = ax
    dec cl
    jnz hq_print_cycle
    add di, bx
    dec ch
    jnz hq_print
    
    mov cx, 2
    mov ax, hq_size
    div cx
    add ax, hq_y
    mov bx, 80
    mul bx
    add ax, cx 
    add ax, hq_x
    shl ax, 1
    mov di, ax
    mov ah, 0Ch
    mov al, hq_hp
    add al, 030h
    stosw
    
    ret
print_hq endp

;DATA 
       
tank_size           equ 3
hq_size             equ 5
max_enemies_count   equ 6 
max_enemies_shots   equ 24
delay               equ 1 
hq_x                equ 65
hq_y                equ 5
hq_tile             equ 0b1h
up                  equ 0
right               equ 1
down                equ 2
left                equ 3

buffer db 6 dup ('$')

game_over          db 0

delay_timer        dw 0
minuetes           dw 0
seconds            dw 0
timer              dw 0
clock_ticks_low    dw 0
clock_ticks_high   dw 0

min_enemies_count  dw 3
max_player_shots   dw 4

player_frame       dw 2
player_y           dw 17    
player_x           dw 3      
player_delay       db 0


player_shots_count dw 0        
player_shots       dw max_player_shots * 3 dup (0)
 
enemies             dw 2, 20, 3, 2, 20, 17, 2, 10, 40, (max_enemies_count - 3) * 3 dup (0)  ;maximum 6 enemies, 3 default at start
enemies_count       dw 3                
enemies_shots_count dw 0
enemies_shots       dw max_enemies_shots * 3 dup (0)
enemies_delays      db max_enemies_count dup (0)
hq_hp               db 5

delay_to_add_enemy  equ 10
allow_to_add_enemy  db 0 
adding_delay_timer  db 0
new_enemy_x         dw 23
new_enemy_y         dw 2
new_enemy_dir       dw left
    
frame1 db ' ',  0b1h,  ' ',  ; #
       db 0b1h, 0b1h, 0b1h   ;###
       db 0b1h, 0b1h, 0b1h   ;###
       
frame2 db 0b1h, 0b1h, ' ',   ;##
       db 0b1h, 0b1h, 0b1h,  ;###
       db 0b1h, 0b1h, ' '    ;##
       
frame3 db 0b1h, 0b1h, 0b1h,  ;###
       db 0b1h, 0b1h, 0b1h,  ;###
       db ' ' , 0b1h, ' '    ; # 
       
frame4 db ' ',  0b1h, 0b1h,  ; ##
       db 0b1h, 0b1h, 0b1h,  ;###
       db ' ',  0b1h, 0b1h   ; ##
       
frames dw frame1, frame2, frame3, frame4
       
map    db '################################################################################'
       db '#                                                                              #'
       db '#                                                                              #'
       db '#                                                                              #'
       db '#            #                  #                                              #'
       db '#            #                  #                                              #'
       db '#            #                  #                                              #'
       db '#            #                                                                 #'
       db '#            #                                                                 #'
       db '#            #                                                                 #'
       db '#            #                  #                                              #'
       db '#                               #                                              #'
       db '#                               #                                              #'
       db '#                                                                              #'
       db '#            #                                                                 #'
       db '#            #                                                                 #'
       db '#            #                  #                                              #'
       db '#                               #                                              #'
       db '#                                   #########        ###########################'
       db '#                                                                              #'
       db '#                                                                              #'
       db '#                                                                              #'
       db '#                                                                              #'
       db '#                                                                              #'    
       db '################################################################################'
                      
end main
    
        
    
    



