comp= gcc#compilador
flags = -lm
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

exec: compilar
	./$(bin)
	@echo

compilar: $(srcDir)/main.c
	@echo
	$(comandos)
	@echo
	
chato:
	$(comandos) $(chatoFlags)

clean:
	@echo
	rm -rf `find -name '*.o' -o -name '*.exe' -o -name '*.bak' -o -name '*.c~' -o -name 'core' -o -name 'a.out' -o -name '$(bin)'`
	@echo
	
limpa: clean
	@

limpar: clean
	@
	
%:
	@echo
	@echo sua mensagem foiii:
	@echo $@
	@echo
