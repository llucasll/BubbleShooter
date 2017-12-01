comp= gcc #compilador
flags = -lm -lpthread
sdl = -lSDL2 -lSDL2_image

chatoFlags= -Wall -pedantic -ansi #prof
outros= -D_GNU_SOURCE=1 -D_REENTRANT

head = lib-headers/*.h 
lib = lib/*.c
srcDir = src
source = $(srcDir)/*.c
bin = exe

comandos = $(comp) -o $(bin) $(lib) $(source) $(flags) $(sdl)

testar: cleanSimples repetir
	@echo

repetir:
	@$(comp) -o repetir repetir.c
	@./repetir

%:	
	@echo
	$(comp) -o $@ lib/terminal.c $@.c
	@echo
	./$@
	@echo
	rm -rf $@
	@echo

exec: compilar
	./$(bin)
	@echo

compilar:
	@echo
	$(comandos)
	@echo
	
chato:
	$(comandos) $(chatoFlags)

cleanSimples:
	@echo
	rm -rf `find -name '*.o'; find -name '$(bin)'; find -name 'repetir'`

clean: cleanSimples
	rm -rf `find  -name '*~'; find -name 'core'; find -name 'a.out'`
	@echo

cleanCompleto:
	@echo
	rm -rf `find -name '*.o' -o -name '*.exe' -o -name '*.bak' -o -name '*.c~' -o -name 'core' -o -name 'a.out' -o -name '$(bin)' -o -name 'repetir'`
	@echo
	
limpa: clean
	@

limpar: clean
	@

#%:
#	@echo
#	@echo sua mensagem foi:
#	@echo $@
#	@echo
