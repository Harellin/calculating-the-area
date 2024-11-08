section .note.GNU-stack noalloc noexec nowrite progbits

section .data
    a1 dq 0.35
    a2 dq -0.95
    a3 dq 2.7
    b1 dq 3.0
    c2 dq 2.0

section .text
global f1
global f2
global f3
global test1
global test2
global test3
    
f1: ; 0.35x^2 − 0.95x + 2.7
    push ebp
    mov ebp, esp
    
    finit
    fld qword[a1]
    fld qword[ebp + 8]
    fld qword[ebp + 8]
    fmulp
    fmulp
    fld qword[a2]
    fld qword[ebp + 8]
    fmulp
    faddp
    fld qword[a3]
    faddp
    
    leave
    ret

f2: ; 3x + 1
    push ebp
    mov ebp, esp
    
    finit
    fld qword[b1]
    fld qword[ebp + 8]
    fmulp
    fld1
    faddp
    
    leave
    ret
    
f3: ; 1 / (x + 2)
    push ebp
    mov ebp, esp
    
    finit
    fld1
    fld qword[ebp + 8]
    fld qword[c2]
    faddp
    fdivp
    
    leave
    ret
    
test1: ;x
    push ebp
    mov ebp, esp
    
    finit
    fld qword[ebp + 8]
    
    leave
    ret
    
test2: ;x^2
    push ebp
    mov ebp, esp
    
    finit
    fld qword[ebp + 8]
    fld qword[ebp + 8]
    fmulp
    
    leave
    ret

test3: ;sqrt(x)
    push ebp
    mov ebp, esp
    
    fld qword[ebp + 8]
    fsqrt
    
    finit
    fld qword[ebp + 8]