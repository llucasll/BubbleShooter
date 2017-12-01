comp= gcc#compilador
flags = -lm -lpthread
sdl = -lSDL2 -lSDL2_image

chatoFlags= -Wall  -pedantic #prof
outros= -D_GNU_SOURCE=1 -D_REENTRANT -lm

head = lib-headers/*.h 
lib = lib/*.c
srcDir = src
source = $(srcDir)/*.c
bin = exe

comandos = $(comp) -o $(bin) $(lib) $(source) $(flags) $(sdl)
#rm -rf *.o *.exe *.bak *.c~ core a.out $(bin)
#echo `find . -name "*.o"` `find . -name "$(bin)"`
#find . -iname ".svn" -exec rm -rf {} ; *.o *.exe *.bak *.c~ core a.out $(bin)

	#@echo
	#@echo LEIA-ME
	#@echo O programa irá se repetir indefinidamente.
	#@echo Use CRTL+C ou ESC para encerrar o jogo, e CRTL+C novamente para encerrar o loop;
	#@echo Use CRTL+C ou ESC para encerrar o jogo, e em seguida ENTER para iniciar novamente.
	#@echo

testar: cleanSimples repetir
	@echo

repetir:
	@$(comp) -o repetir repetir.c
	@./repetir

exec: compilar
	./$(bin)
	@echo

#$(srcDir)/main.c
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
