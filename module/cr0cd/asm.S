.intel_syntax noprefix

.global ReadCR0
ReadCR0:
	mov rax, cr0
	ret

.global WriteCR0
WriteCR0:
	mov cr0, edi
	ret
